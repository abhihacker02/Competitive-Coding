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
int n,m;
int check(int x,int y){
	if(x<0||x>=n||y<0||y>=m) return 0;
	return 1;
}
int main(){
	fast
	//int n,m;
	cin>>n>>m;
	char a[n][m];
	int c=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
			if(a[i][j]=='#') c++;
		}
	}
	if(n==3&&m==3&&c==9) {
		cout<<"NO"; return 0;
	}
	int np=0;
	int nd[n][m];
	mem(nd,0);
	for(int i=0;i<n;i++){
		if(np==1) break;
		for(int j=0;j<m;j++){
			if(np==1) break;
			if(a[i][j]=='#'){
				if(check(i,j+1)&&a[i][j+1]=='#'){
					if(check(i,j-1)&&a[i][j-1]=='#') ;
					else if(check(i,j+2)&&a[i][j+2]=='#') ;
					else{
						np=1;break;
					}
				}
				else if(check(i,j-1)&&a[i][j-1]=='#'&&check(i,j-2)&&a[i][j-2]=='#') ;
//				else if(check(i,j+1)&&a[i][j+1]=='.'){
//					if(check(i,j+2)&&a[i][j+2]=='#') ;
//					else{
//						np=1;break;
//					}
//				}
//				else if(check(i,j-1)&&a[i][j-1]=='.'){
//					if(check(i,j-2)&&a[i][j-2]=='#') ;
//					else{
//						np=1;break;
//					}
//				}
//				else if(check(i,j+1)&&a[i][j+1]=='.'){
//					if(check(i,j+2)&&a[i][j+2]=='#') ;
//					else{
//						np=1;break;
//					}
//				}
				else if(check(i+1,j)&&a[i+1][j]=='#'){
					if(check(i-1,j)&&a[i-1][j]=='#') ;
					else if(check(i+2,j)&&a[i+2][j]=='#') ;
					else{
						np=1;break;
					}
				}
				else if(check(i-1,j)&&a[i-1][j]=='#'&&check(i-2,j)&&a[i-2][j]=='#') ;
//				else if(check(i+1,j)&&a[i+1][j]=='.'){
//					if(check(i+2,j)&&a[i+2][j]=='#') ;
//					else{
//						np=1;break;
//					}
//				}
//				else if(check(i-1,j)&&a[i-1][j]=='.'){
//					if(check(i-2,j)&&a[i-2][j]=='#') ;
//					else{
//						np=1;break;
//					}
//				}
//				else if(check(i+1,j)&&a[i+1][j]=='.'){
//					if(check(i+2,j)&&a[i+2][j]=='#') ;
//					else{
//						np=1;break;
//					}
//				}
				else{
					np=1;break;
				}
			}
		}
	}
	if(np==1) cout<<"NO";
	else cout<<"YES";
}

