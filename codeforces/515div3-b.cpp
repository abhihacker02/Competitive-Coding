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
int main(){
	fast
	int n,r;
	cin>>n>>r;
	int a[n];
	FOR0(n) cin>>a[i];
	int used[n];
	int vis[n];
	int visf[n],visb[n];
	mem(visf,0);mem(visb,0);
	int viss[n];
	int fr[n+1],bk[n+1];
	mem(vis,0);mem(used,0);mem(viss,0);
	FOR0(n) bk[i]=fr[i]=inf;
	int c=1;
	for(int i=0;i<n;i++){
		if(!vis[i]){
			for(int j=i;j>=max(0,i-r+1);j--){
				if(a[j]==1){
					for(int k=max(0,j-r+1);k<=min(n-1,j+r-1);k++){
						vis[k]=1;
						visf[k]=1;
						viss[k]=1;
						fr[k]=min(fr[k],c);
					}
					c++;
					break;
				}
			}
		}
	}
	c=1;
	mem(vis,0);
	for(int i=n-1;i>=0;i--){
		if(!vis[i]){
			for(int j=i;j<=min(n-1,i+r-1);j++){
				if(a[j]==1){
					for(int k=min(n-1,j+r-1);k>=max(0,j-r+1);k--){
						vis[k]=1;
						visb[k]=1;
						viss[k]=1;
						bk[k]=min(bk[k],c);
					}
					c++;
					break;
				}
			}
		}
	}
//	FOR0(n) cout<<viss[i]<<" ";cout<<endl;
	FOR0(n) cout<<fr[i]<<" ";cout<<endl;
	FOR0(n) cout<<bk[i]<<" ";cout<<endl;
	int np=0;
	FOR0(n) if(viss[i]==0) np=1;
	int ans=inf;
	for(int i=0;i<n-1;i++){
		if(visf[i]==1&&visb[i+1]==1)
		ans=min(ans,fr[i]+bk[i+1]);
	}
	if(visf[n-1]==1)
	ans=min(ans,fr[n-1]);
	if(visb[0]==1)
	ans=min(ans,bk[0]);
	if(np==1||ans==inf) ans=-1;
	cout<<ans;
}

