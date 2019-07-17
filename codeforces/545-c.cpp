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
	int n,m;
	cin>>n>>m;
	lli a[n][m];
	FOR0(n){
		for(int j=0;j<m;j++) cin>>a[i][j];
	}
	vector<lli> r[n],c[m];
	for(int i=0;i<n;i++){
		set<lli>s;
		for(int j=0;j<m;j++){
			if(s.find(a[i][j])==s.end()){
				r[i].pb(a[i][j]);
				s.insert(a[i][j]);
			}
		}
		sort(all(r[i]));
	}
	for(int i=0;i<m;i++){
		set<int>s;
		for(int j=0;j<n;j++){
			if(s.find(a[j][i])==s.end()){
				c[i].pb(a[j][i]);
				s.insert(a[j][i]);
			}
		}
		sort(all(c[i]));
	}
	lli an[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			an[i][j]=r[i].size();
			lli in=lower_bound(all(r[i]),a[i][j])-r[i].begin();
			lli p2=lower_bound(all(c[j]),a[i][j])-c[j].begin();
			lli pos=in+1+c[j].size()-p2-1;
			an[i][j]=max(pos,an[i][j]);
			lli pos2=p2+1+r[i].size()-in-1;
			an[i][j]=max(an[i][j],pos2);
			an[i][j]=max(an[i][j],lli(c[j].size()));
//			if(i==1&&j==0){
//				cout<<in<<" "<<p2<<endl;
//			}
		}
	}
//	FOR0(n){
//		for(int j=0;j<m;j++) an[i][j]=max(an[i][j],an[j][i]);}
	FOR0(n){
		for(int j=0;j<m;j++) cout<<an[i][j]<<" ";
		cout<<endl;
	}
}


