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
lli dp[1005][1005];
void NcR() {
    for (int i = 2; i < 1002; i++)
    {
        int val = 1;
        for (int k = 0; k <= i; k++)
        {
            if(k==0||k==i) dp[i][k]=1;
            else{
                dp[i][k]=(1ll*dp[i-1][k-1]+dp[i-1][k])%mod;
            }
        }
    }
}
int main(){
	fast
	int t;
	cin>>t;
	mem(dp,0);
	dp[1][1]=1;
	dp[1][0]=1;
	NcR();
	while(t--){
		lli a,b,c;
		cin>>a>>b>>c;
		lli nc=0;
		for(int i=1;i<=c;i++){
			nc=(1LL*nc+dp[c][i])%mod;
		}
		lli na[a+1];
		mem(na,0);
		na[0]=dp[a][0];
		for(int i=1;i<=a;i++){
			na[i]=(1LL*na[i-1]+dp[a][i])%mod;
		}
		lli ans=0;
//		cout<<nc<<endl;
		for(int i=1;i<=b;i++){
			if(i>=a) break;
			lli an=(((1LL*na[a]-na[i]+mod)%mod)*1LL*dp[b][i])%mod;
			an=(1LL*an*nc)%mod;
			ans=(1LL*ans+an)%mod;
		}
		cout<<ans<<endl;
	}
}


