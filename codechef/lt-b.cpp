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
const int N=100005;
int dr8[]={0,0,1,-1,1,1,-1,-1};
int dc8[]={1,-1,0,0,-1,1,-1,1};
int dr4[]={0,1,-1,0};
int dc4[]={1,0,0,-1};
int a[2*N+5];
int l[N];	
int par[N];
int mn[2*N+5],mx[2*N+5];
//find min for each node
int mntr(int i){
	if(l[i]!=0) return l[i];
	if(mn[i]!=inf) return mn[i];
	return mn[i]=min(mntr(a[2*i]),mntr(a[2*i+1])); 
}
//find max for each node
int mxtr(int i){
	if(l[i]!=0) return l[i];
	if(mx[i]!=0) return mx[i];
	return mx[i]=max(mxtr(a[2*i]),mxtr(a[2*i+1]));
}
int main(){
	fast
	int t,x,y;
	cin>>t;
	while(t--){
			int n;
		cin>>n;
		lli ans=0;
		FORQ(0,2*n+10) mn[i]=inf;
		FORQ(0,2*n+10) mx[i]=0;
		int np=0;
		mem(l,0);
		FORQ(1,n){
			cin>>x>>y;
			if(x!=-1){
				par[x]=i;par[y]=i;
				a[2*i]=x;a[2*i+1]=y;
			}
			else{
			 l[i]=y;
			 mn[i]=y;mx[i]=y;
			 }
		}
		int w=mntr(1);
		w=mxtr(1);
		FORQ(1,n){
			if(l[i]==0){
				//find right child and left child
				int lc=a[2*i];int rc=a[2*i+1];
				//compare their min and max
				//if left is whole less than right
				if(mx[lc]<mn[rc]) continue;
				//if left child is whole greater than right
				else if(mn[lc]>mx[rc]) {
					ans++;
					
				}
				//if intersect then not psooible
				else np=1;
			}
		}
		if(np==1) cout<<-1<<endl;
		else cout<<ans<<endl;
	}
}
