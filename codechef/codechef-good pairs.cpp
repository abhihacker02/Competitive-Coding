#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define SUM(v) accumulate(v.begin(),v.end(),lli(0))
#define rev(n) for(int i=n;i>=0;i--)
#define FOR0(n) for(int i=0;i<n;i++)
#define FOR(a,n) for(int i=a;i<n;i++)
#define FORQ(a,n) for(int i=a;i<=n;i++)
#define inf 1e14
#define sz(a) int((a).size()) 
#define all(c) c.begin(), c.end()
#define ff first
#define ss second
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
const int N = 1000*1000+10 , M=21;
lli dp[N] , cnt[N] , ans;
int dr8[]={0,0,1,-1,1,1,-1,-1};
int dc8[]={1,-1,0,0,-1,1,-1,1};
int dr4[]={0,1,-1,0};
int dc4[]={1,0,0,-1};
int a[1000005],n,t;
//lli dp[10005][N];
int F[10005];
int main(){
	fast
	mem(a,0);
	mem(dp,0);
	mem(F,0);
	cin>>t;
		/*for(int mask = 0; mask < (1<<N); ++mask){
		//	cout<<"H";
		if(a[mask])
		dp[mask][-1] = 1;
		else dp[mask][-1]=0;	//handle base case separately (leaf states)
		//cout<<"P";
		if(a[mask])
	for(int i = 0;i < N; ++i){
		if(mask & (1<<i)){
			dp[mask][i] = dp[mask][i-1];
			if(a[mask^(1<<i)]) dp[mask][i]+=dp[mask^(1<<i)][i-1];
			}
		else
			dp[mask][i] = dp[mask][i-1];
	}
	F[mask] = dp[mask][N-1];*/
	while(t--){
		memset(cnt , 0 , sizeof cnt);
		ans = 0;
		int n;
		cin >> n;
		for(int i=0 ; i<n ; i++){
			int d;cin >> d;
			cnt[d] ++;                
		}
		for(int i=0 ; i<N ; i++)
			dp[i] = cnt[i];
		for(int i=0 ; i<M ; i++)
			for(int j=0 ; j<N ; j++){
			if(j&(1<<i))//	if((j & (1<<i)) == 0 && (j | (1<<i)) < N)
					dp[j] += dp[j^(1<<i)];
			}                        
		for(int i=0 ; i<N ; i++){
			ans += cnt[i]*dp[i];
			ans -= cnt[i]*cnt[i];
			ans += cnt[i]*(cnt[i]-1)/2;
		}
		cout << ans << "\n";
	}
}
