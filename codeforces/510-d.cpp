#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define SUM(v) accumulate(v.begin(),v.end(),lli(0))
#define rev(n) for(int i=n;i>=0;i--)
#define FOR0(n) for(int i=0;i<n;i++)
#define FOR(a,n) for(int i=a;i<n;i++)
#define FORQ(a,n) for(int i=a;i<=n;i++)
#define inf 1000000009
#define inff 0x3f3f3f3f
#define sz(a) int((a).size())
#define all(c) c.begin(), c.end()
#define ff first
#define ss second
#define endl "\n"
#define mod 1000000007
#define mem(ar,x) memset(ar,x,sizeof ar)
#define present(container, element) (container.find(element) != container.end())
#define max3(a,b,c) return (lli(a)>lli(b)?(lli(a)>lli(c)?a:c):(lli(b)>lli(c)?b:c))
#define max4(a,b,c,d) return (max3(a,b,c)>lli(d)?(max3(a,b,c)):d)
#define min3(a,b,c) return (lli(a)<lli(b)?(lli(a)<lli(c)?a:c):(lli(b)<lli(c)?b:c))
#define min4(a,b,c,d) return (max3(a,b,c)<lli(d)?(max3(a,b,c)):d)
typedef long long int ll;
#define M6 6000009
#define M5 6000009
typedef pair<ll,ll> pll;
ll power(ll x,ll n){
    ll ret=1;
    while(n>0){
        if(n&1) ret=(ret*x);
        x=(x*x);
        n/=2;
    }
    return ret;
}
ll m,n,ar[M5],cr[M5],tree[M6],ql[M5],qr[M6];
void update(ll st,ll en,ll nd,ll i,ll v){
    if(st==en) {tree[nd]+=v; return;}
    ll mid=(st+en)/2;
    if(i>=st&&i<=mid){
        update(st,mid,2*nd,i,v);
    }
    else update(mid+1,en,2*nd+1,i,v);
    tree[nd]=tree[2*nd]+tree[2*nd+1];
}
ll query(ll st,ll en,ll nd,ll qs,ll qe){
    if(st>qe||en<qs) return 0;
    if(st>=qs&&en<=qe) return tree[nd];
    ll mid=(st+en)/2;
    ll p=query(st,mid,2*nd,qs,qe);
    ll q=query(mid+1,en,2*nd+1,qs,qe);
    return p+q;
}
int  main()
{   fast
ll kk;
    ll test=1,t=1,flag,i,j,k,l,a,b,ans=0,p,q;
    cin>>n>>kk;
    test=1;
    vector<ll> v;
    for(i=1;i<=n;i++) {
	cin>>ar[i];ar[i]+=ar[i-1],v.pb(ar[i]);}
    v.pb(0);
    for(i=1;i<=test;i++){
        ql[i]=-20000000000000001;qr[i]=kk-1;
        for(j=1;j<=n;j++) v.pb(ar[j]-ql[i]),v.pb(ar[j]-qr[i]);
    }
    sort(v.begin(),v.end());
    for(i=1;i<=test;i++){
        q=(ll)v.size();
        j=lower_bound(v.begin(),v.end(),0)-v.begin();
        update(0,q,1,j,1);
        ans=0;
        for(j=1;j<=n;j++){
            a=ar[j]-qr[i]; b=ar[j]-ql[i];
            a=lower_bound(v.begin(),v.end(),a)-v.begin();
            b=lower_bound(v.begin(),v.end(),b)-v.begin();
            ans+=query(0,q,1,a,b);
            k=lower_bound(v.begin(),v.end(),ar[j])-v.begin();
            update(0,q,1,k,1);
        }
        j=lower_bound(v.begin(),v.end(),0)-v.begin();
        update(0,q,1,j,-1);
        for(j=1;j<=n;j++){
            k=lower_bound(v.begin(),v.end(),ar[j])-v.begin();
            update(0,q,1,k,-1);
        }
        cout<<ans<<"\n";
    }
    return 0;
}  
