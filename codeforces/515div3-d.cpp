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
#define mod 998244353
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
int power(int x, int y, int p)
{
    int res = 1;      // Initialize result
 
    x = x % p;  // Update x if it is more than or
                // equal to p
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (1LL*res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (1LL*x*x) % p;
    }
    return res;
}
int main(){
	fast
	int n,m;
	cin>>n>>m;
	string a,b;
	cin>>a>>b;
	int pr[m];
	mem(pr,0);
	FOR0(m){
		if(i==0&&b[i]=='1') pr[i]=1;
		else if(b[i]=='1') pr[i]=pr[i-1]+1;
		else pr[i]=pr[i-1];
	}
//	FOR0(m) cout<<pr[i]<<" ";cout<<endl;
	int i=0;
	int off=n-m;
	lli ans=0;
	if(n>m) i=n-m;
	for(i;i<n;i++){
		if(a[i]=='1'){
			int c=pr[i-off];
			int p=n-1-i;
			ans=(ans+(1LL*c*(power(2,p,mod)))%mod)%mod;
		//	cout<<ans<<"b"<<endl;
		}
	}
	cout<<ans;
}


