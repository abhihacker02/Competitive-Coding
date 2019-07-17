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
#define mod 1000000007
#define mem(ar,x) memset(ar,x,sizeof ar)
#define present(container, element) (container.find(element) != container.end())
#define max3(a,b,c) return (lli(a)>lli(b)?(lli(a)>lli(c)?a:c):(lli(b)>lli(c)?b:c))
#define max4(a,b,c,d) return (max3(a,b,c)>lli(d)?(max3(a,b,c)):d)
#define min3(a,b,c) return (lli(a)<lli(b)?(lli(a)<lli(c)?a:c):(lli(b)<lli(c)?b:c))
#define min4(a,b,c,d) return (max3(a,b,c)<lli(d)?(max3(a,b,c)):d)
typedef long long int ll;
typedef pair<int,int> ii;
typedef pair<int,ii>ppii;
typedef vector<int>vi;
typedef vector<vi>vvi;
typedef vector<ii>vpii;
int dr8[]={0,0,1,-1,1,1,-1,-1};
int dc8[]={1,-1,0,0,-1,1,-1,1};
int dr4[]={0,1,-1,0};
int dc4[]={1,0,0,-1};
const int N = 1e6 + 10; 
int s[N], a[N], n, t, cnt[N];  
vector<int> d[N]; 
 
int main() {
	fast;
	for(int i = 2; i < N; i++) if(!s[i]) 
		for(int j = i; j < N; j += i) 
			s[j] += i;
 
	for(int i = 2; i < N; i++) {
		for(int j = i; j < N; j += i) {
			if(s[j] % s[i] == 0) 
				d[i].push_back(j); 
		}
	}
	scanf("%d", &t); while(t--) {
		int n; scanf("%d", &n);
		vector<int> v; 
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]); 
			++cnt[a[i]];
			if(cnt[a[i]] == 1) 
				v.push_back(a[i]); 
		}
 
		ll ans = -n;
		for(int i : v) {
			int tmp = 0; 
			for(int x : d[i]) 
				tmp += cnt[x];
			ans += (ll) tmp * cnt[i]; 
		}	 
 
		printf("%lld\n", ans);
 
		for(int i = 1; i <= n; ++i) 
			--cnt[a[i]];
	}
} 
