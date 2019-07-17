#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define FOR0(n) for(int i=0;i<n;i++)
#define FOR(a,n) for(int i=a;i<n;i++)
#define FORQ(a,n) for(int i=a;i<=n;i++)
#define inf 1e14
#define sz(a) int((a).size()) 
#define all(c) c.begin(), c.end()
#define fs first
#define sc second
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
#define mod 1000000007
int dr8[]={0,0,1,-1,1,1,-1,-1};
int dc8[]={1,-1,0,0,-1,1,-1,1};
int dr[]={0,1,-1,0};
int dc[]={1,0,0,-1};
lli power(lli x, lli y, lli p)
{
    lli res = 1;      // Initialize result
 
    x = x % p;  // Update x if it is more than or
                // equal to p
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
 
lli n,k;
int main(){
	fast
	cin>>n>>k;
	if(n==0){
		cout<<0;return 0;
	}
	if(k==0){
		cout<<(2*n)%mod;return 0;
	}
	lli f=power(2,k*2,mod)%mod;
	f=(f*(n%mod))%mod;
	lli s1=power(2,(2*k)-1,mod)%mod;
	lli s2=power(2,k-1,mod)%mod;
	lli ans=((f%mod)-((((s1%mod)-(s2%mod)+mod)%mod)%mod)+mod)%mod;
	if(k>0){
		lli invb=power(s2,mod-2,mod)%mod;
	ans=((ans%mod)*(invb)+mod)%mod;
	}
	else 
	ans=ans*2;
	ans=ans%mod;
	cout<<ans<<endl;
}
