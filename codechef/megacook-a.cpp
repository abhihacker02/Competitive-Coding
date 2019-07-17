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
int a[N];int n;
map<int,int>m;
int tree[4*N];
void build(int node,int l,int r){
	if(l==r) {
		tree[node]=a[l];return;
	}
	int mid=(l+r)/2;
	build(2*node,l,mid);
	build((2*node)+1,mid+1,r);
	tree[node]=max(tree[2*node],tree[(2*node)+1]);
}
int query(int node,int ql,int qr,int l,int r){
	if(qr<l||ql>r) return 0;
	if(ql<=l&&qr>=r) return tree[node];
	int mid=(l+r)/2;
	return max(query((2*node),ql,qr,l,mid),query((2*node)+1,ql,qr,mid+1,r));
}
int solve(int l,int r){
	int mx=query(1,l,r,0,n-1);
//	cout<<mx<<endl;
	if(m[mx]==l||m[mx]==r) return 1;
//	cout<<"here";
	return 1+min(solve(l,m[mx]-1),solve(m[mx]+1,r));
}
int main(){
	fast
	int t;
	cin>>t;
	while(t--){
		int x;
		m.clear();
		cin>>n;
		FOR0(n) {
		cin>>x;
		a[i]=x;
		m[x]=i;
		}
		build(1,0,n-1);
	//	FOR0(8) cout<<tree[i]<<" ";cout<<endl;
		cout<<solve(0,n-1)<<endl;
	}
}

