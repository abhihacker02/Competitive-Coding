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
	int n;
	cin>>n;
	string s1,s2;
	cin>>s1>>s2;
	map<char,vector<int> >m1,m2;
	FOR0(n){
		m1[s1[i]].pb(i);m2[s2[i]].pb(i);
	}
	lli ans=0;
	vpii v;
	vi lsp,rsp;
	map<char,lli>::iterator it;
	for(char i='a';i<='z';i++){
		int mn=min(m1[i].size(),m2[i].size());
		for(int j=0;j<mn;j++){
			v.pb({m1[i][j],m2[i][j]});
		}
		for(int j=mn;j<m1[i].size();j++){
			lsp.pb(m1[i][j]);
		}
		for(int j=mn;j<m2[i].size();j++){
			rsp.pb(m2[i][j]);
		}
	}
	vi lin,rin;
	for(int i=0;i<m1['?'].size();i++){
		lin.pb(m1['?'][i]);
	}
	for(int i=0;i<m2['?'].size();i++){
		rin.pb(m2['?'][i]);
	}
	ans=v.size();
	int mnn=min(lin.size(),rsp.size());
	for(int i=0;i<mnn;i++){
		v.pb({lin[i],rsp[i]});
	}
	int mkk=min(lin.size()-mnn,rin.size());
	for(int i=0;i<mkk;i++){
		v.pb({lin[i+mnn],rin[i]});
	}
	int lmm=min(rin.size()-mkk,lsp.size());
	for(int i=0;i<lmm;i++){
		v.pb({lsp[i],rin[i+mkk]});
	}
//	for(int i=0;i<min(in.size(),sp.size());i++){
//		v.pb({sp[i],in[i]});
//	}
	ans=v.size();
	cout<<ans<<endl;
	FOR0(v.size()){
		cout<<v[i].ff+1<<" "<<v[i].ss+1<<endl;
	}
}


