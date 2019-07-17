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
#define endl "\n"
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
int n,vis[5005];vi gr[5005];
map<int,vi>m;
vi g1,g2;
//set<int>s;
set<int>sm;
int a[5005]={};
void dfs(int u,int d){
	m[d].pb(u);
	vis[u]=1;
	for(int i=0;i<gr[u].size();i++){
		int v=gr[u][i];
		if(!vis[v]) dfs(v,d+1);
	}
	vis[u]=0;
}
void dfs2(int u,int d,int f){
	//if(d==f&&s.find(u)==s.end())
	if(a[u]==0&&d==f)
	{
	sm.insert(u);return;}
	vis[u]=1;
	for(int i=0;i<gr[u].size();i++){
		int v=gr[u][i];
		if(!vis[v]) dfs2(v,d+1,f);
	}
	vis[u]=0;
}
int main(){
	//fast
	while(scanf("%d",&n)!=EOF){
	//cin>>n;
		int mx=0;
		//s.clear();
		vector<int>s;
		mem(a,0);
		FOR0(5005) gr[i].clear();
		sm.clear();
		m.clear();
		g1.clear();g2.clear();
		mem(vis,0);
		FORQ(1,n){
			int t,x;
			scanf("%d",&t);//cin>>t;
			for(int j=0;j<t;j++){
				//cin>>x;
				scanf("%d",&x);
				gr[i].pb(x);
			}
		}
		//cout<<"p";
		dfs(1,0);
		//cout<<"h";
		map<int,vi>::reverse_iterator rit;
		rit=m.rbegin();
		for(int i=0;i<(rit->second).size();i++) g1.pb((rit->second)[i]);
		m.clear();
		dfs(g1[0],0);
		rit=m.rbegin();
		mx=rit->first;
		for(int i=0;i<(rit->second).size();i++) g2.pb((rit->second)[i]);
	//	set<int>s;
		//if(mx%2==0){
		//}
		//else{
		//	dfs2(g1[0],0,(mx)/2);
		//dfs2(g2[0],0,(mx)/2);}
		//}
		for(int i=0;i<g1.size();i++) {
		a[g1[i]]=1; s.pb(g1[i]);}
		for(int i=0;i<g2.size();i++) {
		a[g2[i]]=1; s.pb(g2[i]);}
		dfs2(g1[0],0,(mx)/2);
		dfs2(g2[0],0,(mx)/2);
		printf("Best Roots : ");
	//	cout<<"Best Roots : ";
		set<int>::iterator it; 
		vector<int>::iterator itt;
		for(it=sm.begin();it!=sm.end();it++){
			//cout<<*it<<" ";
			printf("%d ",*it);
		}
		printf("\n");
		printf("Worst Roots : ");
		//cout<<"Worst Roots : ";
	/*	for(itt=s.begin();itt!=s.end();itt++){
			//cout<<*it<<" ";
			printf("%d ",*itt);
		}*/
		for(int i=1;i<=n;i++) if(a[i]==1) cout<<i<<" ";
		printf("\n");
	}
}
