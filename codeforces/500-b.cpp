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
int c[N]={};
int main(){
	fast
	int n,x;
	cin>>n>>x;
	int a[n];
	FOR0(n) {
	cin>>a[i];c[a[i]]++;}
	sort(a,a+n);
	FOR0(n-1){
		if(a[i]==a[i+1]){
			cout<<0<<endl;return 0;
		}
	}
	FOR0(n){
	//	cout<<c[3]<<endl;
		c[a[i]]--;
		int k=a[i]&x;
		//cout<<a[i]<<" "<<k<<endl;
		if(c[k]>0){
			cout<<1<<endl;
			return 0;
		}
		c[a[i]]++;
	}
	FOR0(n) a[i]=a[i]&x;
	sort(a,a+n);
	FOR0(n-1){
		if(a[i]==a[i+1]){
			cout<<2<<endl;
			return 0;
		}
	}
	cout<<-1;
}
