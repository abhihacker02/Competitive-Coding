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
const int INF = int(1e7);
int cnt[500005];
int run=0,k,n;
void add(int x)
{
	if(cnt[x]==0&&x<=k)
	{
		run++;
	}
	cnt[x]++;
}
 
void del(int x)
{
	if(cnt[x]==1&&x<=k)
	{
		run--;
	}
	cnt[x]--;
}
int main(){
	fast
	mem(cnt,0);
//	int n,k;
	cin>>n>>k;
	int a[n+1];
//	FOR0(n){
//		cin>>a[i+1];
//	}
	int l[n+1];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		a[i]=min(a[i],500001);
	}
	l[0]=0;
	if(k==0&&a[0]==0) l[0]=INF;
	int ptr=0;
	run=0;
	if(l[0]==0)
	{
		add(a[0]);
	}
	else
	{
		ptr=1;
	}
	for(int i=1;i<n;i++)
	{
		add(a[i]);
		while(run>=k+1&&ptr<i)
		{
			del(a[ptr]);
			ptr++;
		}
		if(ptr==i&&run>=k+1)
		{
			del(a[i]);
			ptr=i+1;
			l[i]=INF;
		}
		else
		{
			l[i]=ptr;
		}
	}
	set<int>s;map<int,int>m;
	int b[n+1];
//	int l[n+1];
	int dp[n+1];
	dp[0]=1;
//	int p=0;
//	FORQ(1,n){
//		s.insert(a[i]);
//		m[a[i]]++;
//		if(s.find(k)==s.end()){
//			l[i]=p;
//			continue;
//		}
//		int in=distance(s.begin(),s.upper_bound(k));
//	//	cout<<in<<" "<<a[i]<<endl;
//		if((in-1)==k){
//			while((in-1)==k){
//				p++;
//				m[a[p]]--;
//				if(m[a[p]]==0){
//					s.erase(a[p]);
//				}
//				in=distance(s.begin(),s.upper_bound(k));
//			}
//		}
//		l[i]=p;
//	}
	
	for(int i=n;i>0;i--){
		l[i]=l[i-1];
	}
	//FORQ(1,n) cout<<l[i]<<" ";cout<<endl;
	int sum[n+1];sum[0]=1;
	if(l[1]!=0) sum[0]=0;
//	dp[0]=sum[0];
	FORQ(1,n){
		if(l[i]>0){
			dp[i]=(1LL*sum[i-1]-sum[l[i]-1]+mod)%mod;
			sum[i]=(1LL*dp[i]+sum[i-1])%mod;
		}
		else{
			dp[i]=sum[i-1];
			sum[i]=(1LL*dp[i]+sum[i-1])%mod;
		}
	}
//	FORQ(1,n) cout<<sum[i]<<" ";cout<<endl;
//	FORQ(1,n) cout<<dp[i]<<" ";cout<<endl;
	cout<<dp[n];
}


