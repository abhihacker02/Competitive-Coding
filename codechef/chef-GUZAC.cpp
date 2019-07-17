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
//#define intt int
//#define int long long
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
	lli t;
	cin>>t;
	while(t--){
		lli n,k,x;
		cin>>n>>k>>x;
		set<lli>s;
		lli a[n],sum=0,mn=inff,mx=0;
		FOR0(k){
			cin>>a[i];
			sum+=a[i];
			s.insert(a[i]);
			if(mx<a[i]) mx=a[i];
			if(mn>a[i]) mn=a[i];
		}
		if(k==n){
			cout<<sum<<endl;
			continue;
		}
		if((mx-mn)!=x){
			s.insert(mn+x);
			k++;
			sum+=mn+x;
		}
		set<lli>::reverse_iterator it,itt;
		itt=s.rbegin();
		itt++;
		for(it=s.rbegin();itt!=s.rend();it++,itt++){
			if(k==n) break;
			lli v1=*it;
			lli v2=*itt;
			v2=max(v2,v1-(n-k)-1);
			lli add=(v1*(v1-1))/2;
			add=add-((v2*(v2+1))/2);
			k+=v1-v2-1;
			sum+=add;
		}
		cout<<sum<<endl;
	}
}
