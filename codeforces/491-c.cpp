#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define SUM(v) accumulate(v.begin(),v.end(),lli(0))
#define rev(n) for(int i=n;i>=0;i--)
#define FOR0(n) for(int i=0;i<n;i++)
#define FOR(a,n) for(int i=a;i<n;i++)
#define FORQ(a,n) for(int i=a;i<=n;i++)
#define inf 1e14
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
	lli n;
	cin>>n;
	lli l=0,h=n,ans=0,b=-1;
	if(n<=10){
		cout<<1<<endl;return 0;
	}
	while(l<h){
		ans=(l+h)/2;
		lli t=n;int i=0;
		lli eat=0;
		if(ans==0){
			l=ans+1;continue;
		}
		while(t>0){
		//	cout<<"B="<<b<<endl;
		//	cout<<ans<<endl;
			if(t<=ans) {
				eat+=t;
				t=0;break;
			}
				t=t-ans;
				eat+=ans;
				lli r=t/10;
				t-=r;
		}
		if(eat<(n+1)/2){
			l=ans+1;
		}
		else{
			if(b==-1){
				b=ans;
			}
			else{
				if(ans<b) b=ans;
			}
			h=ans;
		}
	}
	cout<<b<<endl;
	
}
