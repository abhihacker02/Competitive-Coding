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
	int n,w;
	cin>>n>>w;
	lli v[n+1],wt[n+1];
	FOR0(n) cin>>wt[i+1]>>v[i+1];
	lli dp[n+5][N];
	FOR0(n+2){
		for(int j=0;j<N;j++) dp[i][j]=inf;
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<N;j++){
			if((j+v[i])>N) break;
			dp[i][j]=dp[i-1][j];
			if((j-v[i])>=0)
			dp[i][j]=min(dp[i-1][j],dp[i-1][j-v[i]]+wt[i]);
		}
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<20;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int j=n-1;j>=1;j--)
	for(int i=N;i>=0;i--){
		if(dp[j][i]<=w){
			cout<<i;return 0;
		}
	}
}
