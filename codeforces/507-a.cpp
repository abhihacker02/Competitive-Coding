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
	int n,a,b;
	cin>>n>>a>>b;
	int ar[n];
	FOR0(n) cin>>ar[i];
	int mn=min(a,b);
	int sum=0,np=0;
	for(int i=0;i<=(n-1)/2;i++){
		if((ar[i]==ar[n-i-1])&&(ar[i]==0||ar[i]==1)) continue;
		else if((ar[i]==ar[n-i-1]&&ar[i]==2)){
			sum+=(2*mn);
			if(i==(n-i-1)) sum-=mn;
		}
		else if(ar[i]!=ar[n-i-1]){
			if((ar[i]==0&&ar[n-i-1]==1)||(ar[i]==1&&ar[n-i-1]==0)){
				np=1;break;
			}
		/*	if(ar[i]!=2&&ar[n-i-1]!=2){
			//	cout<<i<<endl;
				np=1;break;
			}*/
			else{
				int mnn=min(ar[i],ar[n-i-1]);
				if(mnn==0){
					sum+=a;
				}
				else
				sum+=b;
			}
		}
	}
	if(np==0){
		cout<<sum;
	}
	else cout<<-1;
}

