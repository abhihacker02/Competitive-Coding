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
	map<lli,lli>m;
	fast
	lli n,mx=0,mn=inf;
	cin>>n;
	lli a[2*n+5],ans;
	FOR0(2*n) {
	cin>>a[i];m[a[i]]++;}
	map<lli,lli>::iterator it;
	for(it=m.begin();it!=m.end();it++){
		if((it->ss)>=n){
			cout<<0;
			return 0;
		}
	}
	sort(a,a+(2*n));
	mn=a[0];mx=a[(2*n)-1];
	lli d=-1,b=-1;
	b=a[n-1];d=a[n];
	ans=min((a[(2*n)-1]-a[n])*(a[n-1]-a[0]),(mx-d)*(b-mn));
	FORQ(1,n){
		int x1=a[i],x2=a[i+n-1];
		ans=min(ans,(x2-x1)*(a[(2*n)-1]-a[0]));
	}
	cout<<ans;
}
