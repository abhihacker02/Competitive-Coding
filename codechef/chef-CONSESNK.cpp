#include<bits/stdc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> set_t;
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
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<int,pii>ppii;
typedef vector<int>vi;
typedef vector<vi>vvi;
typedef vector<pii>vpii;
typedef vector<lli>vlli;
const int N=100005;
int dr8[]={0,0,1,-1,1,1,-1,-1};
int dc8[]={1,-1,0,0,-1,1,-1,1};
int dr4[]={0,1,-1,0};
int dc4[]={1,0,0,-1};
int main(){
	fast
	int t;
	cin>>t;
	while(t--){
		lli n,l,a,b;
		cin>>n>>l>>a>>b;
		vlli v(n);
		FOR0(n) cin>>v[i];
		sort(all(v));
		lli ans=1e18;
		lli ll=a,rr=b-(n*l);
		while(rr-ll>10){
			lli m1=ll+(rr-ll)/3;
			lli m2=rr-(rr-ll)/3;
			lli f1=0,f2=0;
			FOR0(n){
				f1+=(abs(m1+((i)*l)-v[i]));
				f2+=(abs(m2+((i)*l)-v[i]));
			}
//			if((m1+(n-1)*l)>b-l) {
//			f1=inff;ll=a;rr=m1-1;continue;
//			}
//			if((m2+(n-1)*l)>b-l){
//			 f2=inff;ans=min(ans,f1);
//			 rr=m2-1;continue;
//			 }
			if(f1>=f2){
				ll=m1+1;
			}
			else rr=m2-1;
			ans=min(ans,min(f1,f2));
		}
		for(lli i=ll;i<=rr;i++){
			lli f1=0;
			for(lli j=0;j<n;j++)
			f1+=(abs(i+((j)*l)-v[j]));
			ans=min(ans,f1);
		}
		cout<<ans<<endl;
	}
}

