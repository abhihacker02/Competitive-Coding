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
	int n,a,b;
	cin>>n>>a>>b;
	vi v;
	v.pb(a);
	FOR0(1<<n){
		if(i!=a&&i!=b) 
			v.pb(i);
	}
	v.pb(b);
	int c1=0,c2=0;
	int t1=a,t2=b;
	while(t1>0){
		if(t1%2!=0) c1++;
		t1/=2;
	}
	while(t2>0){
		if(t2%2!=0) c2++;
		t2/=2;
	}
	if(c1==c2){
		cout<<"NO";return 0;
	}
	while(true){
		int f=0;
		FOR0(n-1){
			int xr=v[i]^v[i+1];
			if((xr&(xr-1))){
				f=1;break;
			}
		}
		if(f==0){
			cout<<"YES\n";
			FOR0(1<<n) cout<<v[i]<<" ";
			return 0;
		}
		random_shuffle(v.begin()+1,v.begin()+(1<<n)-1);
	}
}


