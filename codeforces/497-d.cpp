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
int a[100005];
int main(){
	fast
	int t;
	cin>>t;
	while(t--){
		int three=0,two=0;
		int x,y,z;
		mem(a,0);
		cin>>x>>y>>z;
		int mx=max(x,max(y,z));
		lli k1=0,k2=0,k3=0;
		for(int i=1;i*i<=mx;i++){
			if(x%i==0){
				k1++;
				a[i]++;
				if(x/i!=i){
					a[x/i]++;
					k1++;
				}
			}
		}
		for(int i=1;i*i<=mx;i++){
			if(y%i==0){
				k2++;
				a[i]++;
				if(a[i]==2) two++;
				if(y/i!=i){
					a[y/i]++;
					if(a[y/i]==2) two++;
					k2++;
				}
			}
		}
		for(int i=1;i*i<=mx;i++){
			if(z%i==0){
				k3++;
				a[i]++;
				if(a[i]==2) two++;
				if(a[i]==3){
					three++;two--;
				}
				if(z/i!=i){
					a[z/i]++;
					if(a[z/i]==2) two++;
					if(a[z/i]==3){
						three++;two--;
					}
					k3++;
				}
			}
		}
		if(k1==1&&k2==1&&k3==1){
			cout<<1<<endl;
			//continue;
		}
		else if(k1==1||k2==1||k3==1){
			lli ans=1;
			ans*=k1;ans*=k2;ans*=k3;
			cout<<(ans-(2*(three-1))-two)<<endl;
			//continue;
		}
		else{
		//	cout<<k1<<" "<<k2<<" "<<k3<<endl;
		lli ans=1;
		ans=ans*k1;ans*=k2;ans*=k3;
		cout<<(ans-(2LL*three)-two)<<endl;}
	}
}
