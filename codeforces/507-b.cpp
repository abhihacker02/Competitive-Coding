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
	fast
	int n,k;
	cin>>n>>k;
	if(k>=n){
		cout<<1<<endl;
		cout<<1;return 0;
	}
	if(k==0){
		cout<<n<<endl;
		FORQ(1,n) cout<<i<<" ";
		return 0;
	}
	int ec=(2*k)+1;
	int an=n/ec;
	if(n%ec!=0) an++;
	cout<<an<<endl;
	int r=n%ec;
	int st=0;
	//cout<<r<<endl;
	if(r!=0) st=k-r+1;  //st=min(ec-r,r);
	if(r>k) st=0;
	int till=0;
	cout<<((ec+1)/2)-st<<" ";
	till=(((ec+1)/2)-st)+(ec)/2;
	//cout<<till<<endl;
	for(int i=1;i<an;i++){
		int p=till+(ec+1)/2;
		cout<<min(n,p)<<" ";
		till+=ec;
	}
}

