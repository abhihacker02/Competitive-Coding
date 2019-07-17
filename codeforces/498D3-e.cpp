#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define SUM(v) accumulate(v.begin(),v.end(),lli(0))
#define rev(n) for(int i=n;i>=0;i--)
#define FOR0(n) for(int i=0;i<n;i++)
#define FOR(a,n) for(int i=a;i<n;i++)
#define FORQ(a,n) for(int i=a;i<=n;i++)
#define inf 1000000009
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
const int N=200005;
int dr8[]={0,0,1,-1,1,1,-1,-1};
int dc8[]={1,-1,0,0,-1,1,-1,1};
int dr4[]={0,1,-1,0};
int dc4[]={1,0,0,-1};
vi gr[N],v;
int d=1;
int vis[N],in[N],s[N];
int dfs2(int u){
	vis[u]=1;
	int ans=0;
	if(gr[u].size()==0) return s[u]=1;
	for(int i=0;i<gr[u].size();i++){
		int v=gr[u][i];
		if(!vis[v]){
			ans+=dfs2(v);
		}
	}
	return s[u]=1+ans;
}
void dfs(int u){
	v.pb(u);
	in[u]=d++;
	vis[u]=1;
	for(int i=0;i<gr[u].size();i++){
		int v=gr[u][i];
		if(!vis[v]){
			dfs(v);
		}
	}
}
int main(){
	mem(vis,0);
	fast
	int n,q,x;
	cin>>n>>q;
	for(int i=2;i<=n;i++){
		cin>>x;
		gr[x].pb(i);
	}
	dfs(1);
	memset(vis,0,sizeof vis);
	dfs2(1);
//	FORQ(1,n) cout<<in[i]<<" ";cout<<endl;
//	FORQ(1,n) cout<<s[i]<<" ";cout<<endl;
//	FORQ(0,n-1) cout<<v[i]<<" ";cout<<endl;
	vector<int>::iterator it;
	while(q--){
		int y,z;
		cin>>y>>z;
		if(s[y]<z) cout<<-1<<endl;
		else{
			cout<<v[in[y]+z-2]<<endl;
		}
	}
}
