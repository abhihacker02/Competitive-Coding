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
int n,vis[N],x,y;
vi gr[N];
int dp[N][2];
int dfs(int u,int col,int par){
	if(u==par) return 0;
	int ans=1;
	if(gr[u].size()==1&&u!=1) return dp[u][col]=1;
	if(dp[u][col]!=-1) return dp[u][col];
	for(int i=0;i<gr[u].size();i++){
		int v=gr[u][i];
		if(v==par) continue;
		if(col==1){
			ans=(1LL*ans*dfs(v,0,u))%mod;
		}
		else{
			ans=(1LL*ans*(dfs(v,0,u)%mod*1LL+dfs(v,1,u))%mod)%mod;
		}
	}
	return dp[u][col]=ans;
}
int main(){
	fast
	cin>>n;
	mem(dp,-1);
	if(n==1){
		cout<<2;return 0;
	}
	FOR0(n-1){
		cin>>x>>y;
		gr[x].pb(y);
		gr[y].pb(x);
	}
	cout<<(1LL*dfs(1,1,-1)+ dfs(1,0,-1))%mod;
}


