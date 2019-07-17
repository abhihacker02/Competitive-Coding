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
const int N=1005;
int dr8[]={0,0,1,-1,1,1,-1,-1};
int dc8[]={1,-1,0,0,-1,1,-1,1};
int dr4[]={0,1,-1,0};
int dc4[]={1,0,0,-1};
int n,m;
char a[N][N];
int check(int x,int y){
	if(x>=n||x<0||y>=m||y<0) return 0;
	return 1;
}
int main(){
	fast
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		FOR0(n){
			for(int j=0;j<m;j++){
				cin>>a[i][j];
			}
		}
		int ch[N][N];
		mem(ch,0);
		int np=0;
		FOR0(n){
			for(int j=0;j<m;j++){
				if(a[i][j]=='.'){
					if((check(i,j-1)&&check(i-1,j)&&check(i-1,j-1)&&a[i][j-1]=='.'&&a[i-1][j]=='.'&&a[i-1][j-1]=='.')){
						ch[i][j]=1;
					}
					else if((check(i,j+1)&&check(i-1,j)&&check(i-1,j+1)&&a[i][j+1]=='.'&&a[i-1][j]=='.'&&a[i-1][j+1]=='.')){
						ch[i][j]=1;
					}
					else if((check(i,j-1)&&check(i+1,j)&&check(i+1,j-1)&&a[i][j-1]=='.'&&a[i+1][j]=='.'&&a[i+1][j-1]=='.')){
						ch[i][j]=1;
					}
					else if((check(i,j+1)&&check(i+1,j)&&check(i+1,j+1)&&a[i][j+1]=='.'&&a[i+1][j]=='.'&&a[i+1][j+1]=='.')){
						ch[i][j]=1;
					}
				}
			}
		}
		FOR0(n){
			for(int j=0;j<m;j++){
				if(ch[i][j]==0&&a[i][j]=='.'){
				//	cout<<i<<j<<endl;
					np=1;break;
				}
			}
			if(np==1) break;
		}
		if(np==1){
			cout<<"NO\n";
		}
		else{
			cout<<"YES\n";
		}
	}
	
}


