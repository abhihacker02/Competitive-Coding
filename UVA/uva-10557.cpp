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
vi gr[105];int en[105],mn=inf,mx=0;int vis[105]={},n,y;vi dis(105,inf);
int dfs(int u,int pr){
	vis[u]=1;
	if(u==pr){
		return 1;
	}
	for(int i=0;i<gr[u].size();i++){
		int v=gr[u][i];
		if(!vis[v]){
			return dfs(v,pr);
		}
	}
	vis[u]=0;
}
int main(){
	fast
	cin>>n;
	while(n!=-1){
		mn=inf;mx=0;y=0;
		mem(vis,0);
		//vi dis(n+1,inf);
		dis[1]=0;
		int a,b,c;
		for(int i=1;i<=n;i++){
			cin>>a>>b;
			en[i]=-1*a;
			for(int j=0;j<b;j++){
				cin>>c;
				gr[i].pb(c);
			}
		}
			for(int i=0;i<n-1;i++){
			for(int u=1;u<=n;u++){
				for(int j=0;j<gr[u].size();j++){
					int v=gr[u][j];
					if((dis[u]+en[v])>=100) dis[v]=min(dis[v],inf);
					else
					 dis[v]=min(dis[v],dis[u]+en[v]);
				}
			}
		}
		bool has = false;
		int cyc=0;
		int yc=0;
		for (int u = 1; u <=n; u++) 
		for (int j = 0; j < gr[u].size(); j++) {
		int v = gr[u][j];
		if (dis[v]!=inf&&(dis[v] > dis[u] + en[v])){ 
		has = true;cyc=v;} 
		}
		y=dfs(1,n);
		int yr=0;
		if(cyc!=0) {
		yc=dfs(1,cyc);yr=dfs(cyc,n);}
		if((dis[n]<100||has)) cout<<"winnable\n";
		else cout<<"hopeless\n";
		cin>>n;
	}
}
