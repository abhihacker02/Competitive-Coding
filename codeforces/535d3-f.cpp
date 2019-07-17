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
const int N=200005;
int dr8[]={0,0,1,-1,1,1,-1,-1};
int dc8[]={1,-1,0,0,-1,1,-1,1};
int dr4[]={0,1,-1,0};
int dc4[]={1,0,0,-1};
int n,m;
int par[N];
int size[N];
int mx=0;
int root(int i)
{
    while(par[ i ] != i){
    	i = par[ i ];
    }
    return i;
}	
bool find(int A,int B)
{
    if( root(A)==root(B) )
    	return true;
    else
    	return false;
}
void initialize()
{
	for(int i = 0;i<=n;i++){
	par[ i ] = i ;
	size[ i ] = 1;
	}
}
void un(int A,int B)
{
    int root_A = root(A);
    int root_B = root(B);
    if(size[root_A] < size[root_B ]){
		par[ root_A ] = par[root_B];
		size[root_B] += size[root_A];
	}
    else{
		par[ root_B ] = par[root_A];
		size[root_A] += size[root_B];
	}
	mx=max(mx,max(size[root_A],size[root_B]));
}
int main(){
	fast
	cin>>n>>m;
	int u,v,w;
	initialize();
	vector< pair<int, pii> > EdgeList; 
	for (int i = 0; i < m; i++){
		cin>>u>>v>>w;
		EdgeList.push_back(make_pair(w, pii(u, v))); 
	} 
	lli ans=0;
	int c=0;
	sort(EdgeList.begin(), EdgeList.end()); 
	for (int i = 0; i < m; i++){
		pair<int, pii> front = EdgeList[i];
		if(!find(front.second.first, front.second.second)) {
			//mst_cost += front.first;
			un(front.second.first, front.second.second);
//			cout<<mx<<endl;
			if(mx==n) break; 
		}
		else ans++;	 
	}
	cout<<ans;
}


