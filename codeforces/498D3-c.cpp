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

int main(){
	fast
	map<lli,int>m,p;
	int n;
	cin>>n;
	int a[n];
	FOR0(n) cin>>a[i];
	lli fr[n],bk[n];
	fr[0]=a[0];bk[n-1]=a[n-1];
	m[a[0]]=0;lli sum=a[0];
	if(n==1){
		cout<<0;return 0;
	}
	if(n==2){
		if(a[0]!=a[1]){
			cout<<0;return 0;
		}
		else cout<<a[0];
		return 0;
	}
	for(int i=1;i<n;i++){
		sum+=a[i];
		m[sum]=i;
	}
	sum=a[n-1];p[a[n-1]]=n;
	for(int i=n-2;i>=0;i--){
		sum+=a[i];
		p[sum]=i;
	}
	map<lli,int>::reverse_iterator it;
	for(it=m.rbegin();it!=m.rend();it++){
		if(p.find(it->ff)!=p.end()&&p[it->ff]>it->ss){
			cout<<it->ff;return 0;
		}
	}
	cout<<0;
}
