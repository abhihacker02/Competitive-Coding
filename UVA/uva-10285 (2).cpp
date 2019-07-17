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
int dr[]={0,1,-1,0};
int dc[]={1,0,0,-1};
int dis[105][105],n,m,a[105][105];int mx=0;
int check(int x,int y){
	if(x<0||x>=n||y<0||y>=m) return 0;
	return 1;
}
void calc(int x,int y,int d){
	mx=max(mx,d);
	dis[x][y]=d;
	for(int i=0;i<4;i++){
		int p=x+dr[i];
		int q=y+dc[i];
		if(check(p,q)&&a[x][y]<a[p][q]//&&dis[p][q]==-1
		) calc(p,q,d+1);
	//	else if(check(p,q)&&a[x][y]>a[p][q]) dis[p][q]=dis[p][q]+d;
	}
}
int main(){
	fast
	int t;
	cin>>t;
	while(t--){
		mx=0;
		mem(dis,-1);
		string s;
		cin>>s>>n>>m;
		int mn=inf,posi,posj;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++) {
			cin>>a[i][j];
			if(a[i][j]<mn){
				mn=a[i][j];posi=i;posj=j;
			}
			}
		}
		//int mx=0;
		//cout<<posi<<posj<<endl;
		//calc(posi,posj,1);
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
			//	if(dis[i][j]==-1){
					calc(i,j,1);
			//	}
				//mx=max(mx,dis[i][j]);
			}
		}
		cout<<mx<<endl;
	}
}
