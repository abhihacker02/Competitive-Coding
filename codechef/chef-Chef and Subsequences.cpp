#include<bits/stdc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define SUM(v) accumulate(v.begin(),v.end(),lli(0))
#define rev(n,d) for(int i=n;i>=d;i--)
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
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<int,pii>ppii;
typedef vector<int>vi;
typedef vector<vi>vvi;
typedef vector<pii>vpii;
const int N=100005;
int dr8[]={0,0,1,-1,1,1,-1,-1};
int dc8[]={1,-1,0,0,-1,1,-1,1};
int dr4[]={0,1,-1,0};
int dc4[]={1,0,0,-1};
int main(){
	fast
	lli n,m;
	cin>>n>>m;
	lli a[n];
	FOR0(n) cin>>a[i];
	if(n==1){
		if(a[0]<=m) cout<<1;
		else cout<<0;
	}
	else{
		lli ans=0;
		int h=n/2;
		vector<lli>v;
		for(int i=0;i<(1<<h);i++){
			int t=i;
			lli sm=1;
			for(int j=0;j<h;j++){
				int par=t%2;
				if(par==1&&sm<=m)
				sm=(sm*a[j]);
				if(sm>m) sm=m+1;
				t/=2;
			}
			if(i==0) sm=0;
			if(sm!=0&&sm<=m) ans++;
			v.pb(sm);
		}
		sort(all(v));
	//	FOR0(v.size()) cout<<v[i]<<" ";cout<<endl;
		int r=n-h;
		for(int i=0;i<(1<<r);i++){
			int t=i;
			lli sm=1;
			for(int j=0;j<r;j++){
				int par=t%2;
				if(par==1&&sm<=m)
				sm=(sm*a[j+h]);
				if(sm>m) sm=m+1;
				t/=2;
			}
			if(i==0) sm=0;
//			cout<<sm<<" ";
			if(sm==0) continue;
			if(sm<=m) ans++;
			vector<lli>::iterator it;
			lli search=m/sm;
			it=upper_bound(all(v),search);
			int in=it-v.begin();
			in--;
			ans+=in;
		}
//		cout<<endl;
		cout<<ans;
	}
}


