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
	int n,m;
	cin>>n>>m;
//	int a[n+1];
//	int f[m+1]={};
	lli ans=1e18+5;
	vector<int> pri[m+1];
	for(int i=1;i<=n;i++){
		lli x,y;
		cin>>x>>y;
	//	a[x]=y;
		pri[x].pb(y);
		//f[p]++;
	}
	for(int i=1;i<=m;i++)
		sort(pri[i].begin(),pri[i].end());
	for(int i=1;i<=n;i++){
		long long cost =0;
		int need = i-pri[1].size();
		vector<int> U;
		for(int j=2;j<=m;j++){
			int staIn = max(0,(int)pri[j].size()-(i-1));
			for(int k=0;k<staIn;k++){
				cost+=pri[j][k];
				need--;
			}
			for(int k= staIn;k<pri[j].size();k++){
				U.push_back(pri[j][k]);
			}
		}
		sort(U.begin(),U.end());
		if(need>0){
			for(int j=0;j<need;j++)	
				cost+=U[j];
		}
		ans = min(cost,ans);
	}
	cout<<ans<<endl;
	return 0;
}
