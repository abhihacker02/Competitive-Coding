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
const int N=100005;
int dr8[]={0,0,1,-1,1,1,-1,-1};
int dc8[]={1,-1,0,0,-1,1,-1,1};
int dr4[]={0,1,-1,0};
int dc4[]={1,0,0,-1};
int main(){
	fast
	int t;
	cin>>t;
	while(t--){
		int n;
		map<int,int>m;
		cin>>n;
		int a[n];
		set<int>v[N];
		FOR0(n){
			cin>>a[i];
			if(m.find(a[i])==m.end()){
			    v[1].insert(a[i]);
			}
			else{
			    v[m[a[i]]+1].insert(a[i]);
			}
			m[a[i]]++;
		}
		map<int,vi>c;
		map<int,int>::iterator it;
	//	vi v[N];
		for(it=m.begin();it!=m.end();it++){
			int x=it->ff;
			int y=it->ss;
		//	c[y].pb(x);
		//	v[y].pb(x);
		}
		lli ans=0;
		set<int>::iterator itt;
		for(it=m.begin();it!=m.end();it++){
			int x=it->ff;
			int y=it->ss;
			if(v[x].size()==0) continue;
// 			cout<<x<<" "<<y<<endl;
// 			for(int i=0;i<v[x].size();i++) cout<<v[x][i]<<" ";cout<<endl;
		//	itt=v[x].upper_bound(y);
			int in=distance(v[x].begin(), v[x].upper_bound(y));
		//	int in=itt-v[x].begin();
// 			cout<<in<<"i"<<endl;
			ans=(1LL*ans)+in;
		}
		cout<<ans<<endl;
	}
}


