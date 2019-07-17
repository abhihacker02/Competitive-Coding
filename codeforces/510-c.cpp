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
//	cout<<"p";
	fast
	int n;
	cin>>n;
	int a[n];
	vpii v;
//	cout<<"f";
	FOR0(n) {
//		cout<<"g";
	cin>>a[i];v.pb(mp(a[i],i));}
	sort(all(v));
	int neg=1;
//	cout<<"k";
	vi vn,vp,nn,np;
	for(int i=0;i<n;i++){
//		cout<<"b";
		if(v[i].ff>0) continue;
		if(v[i].ff>=-1&&v[i].ff<=0) {
			np.pb(v[i].ss);
			continue;
		}
	neg*=v[i].ff;
		vn.pb(v[i].ss);
	}
	if(neg<0) {
		np.pb(vn[vn.size()-1]);vn.pop_back();
	}
	int ps=1;int tk=0;
	FOR0(n){
//		cout<<"g";
		if(v[i].ff<=0) continue;
		
		if(v[i].ff<=1&&v[i].ff>0){
			np.pb(v[i].ss);continue;
		}
		tk=1;
		ps*=v[i].ff;
		vp.pb(v[i].ss);
	}
	//cout<<vp.size()<<" "<<vn.size()<<" l"<<np.size()<<endl;
	if(vp.size()!=0)
	for(int i=0;i<vp.size()-1;i++){
		cout<<1<<" "<<vp[i]+1<<" "<<vp[i+1]+1<<endl;
	}
	if(vn.size()!=0)
	for(int i=0;i<vn.size()-1;i++){
		cout<<1<<" "<<vn[i]+1<<" "<<vn[i+1]+1<<endl;
	}
	if(vp.size()!=0&&vn.size()!=0){
		cout<<1<<" "<<vp[vp.size()-1]+1<<" "<<vn[vn.size()-1]+1<<endl;
	}
	if(np.size()!=0)
	for(int i=0;i<np.size()-1;i++){
		cout<<1<<" "<<np[i]+1<<" "<<np[i+1]+1<<endl;
	}
	if(np.size()!=0&&vp.size()>0){
		cout<<2<<" "<<np[np.size()-1]+1;
	}
}

