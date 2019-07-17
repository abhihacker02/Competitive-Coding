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
char a[1005][1005];
int vis[1005][1005]={};
int n,m;
int check(int x,int y){
	if(x<0||x>=n||y<0||y>=m) return 0;
	return 1;
}
void dfs(int x,int y){
	
}
int main(){
	fast
	cin>>n>>m;
	FOR0(n){
		for(int j=0;j<m;j++) cin>>a[i][j];
	}
	int p;
	vector<ppii> v;
	FOR0(n){
		for(int j=0;j<m;j++){
//			if(a[i][j]=='*')
			for(p=1;p<n;p++){
				if(a[i][j]!='*') break;
				if(check(i+p,j)&&check(i,j+p)&&check(i-p,j)&&check(i,j-p)){
					if(a[i+p][j]=='*'&&a[i-p][j]=='*'&&a[i][j+p]=='*'&&a[i][j-p]=='*'){
//						v.pb(mp(p,mp(i+1,j+1)));
						vis[i+p][j]=1;vis[i-p][j]=1;vis[i][j+p]=1;vis[i][j-p]=1;
						vis[i][j]=1;
					}
					else break;
				}
				else break;
			}
			if(p!=1) v.pb(mp(p-1,mp(i+1,j+1)));
		}
	}
	FOR0(n){
		for(int j=0;j<m;j++){
			if(vis[i][j]==0&&a[i][j]=='*'){
				//cout<<i<<" "<<j<<endl;
				cout<<-1;return 0;
			}
		}
	}
	cout<<v.size()<<endl;
	for(int i=0;i<v.size();i++){
		cout<<v[i].ss.ff<<" "<<v[i].ss.ss<<" "<<v[i].ff<<endl;
	}
}
