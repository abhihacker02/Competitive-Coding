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
	fast
	lli n,k,s;
	cin>>n>>k>>s;
	if(((n-1)*k)<s){
		cout<<"NO";return 0;
	}
	if(k>s){
		cout<<"NO";return 0;
	}
	lli m=s/k;
	lli prev=m;
	cout<<"YES\n";
	if(s%k==0){
		for(int i=1;i<=k;i++){
			if(i%2!=0){
				cout<<m+1<<" ";
			}
			else cout<<1<<" ";
		}
		return 0;
	}
	vi v;lli dis=0;
	lli w=m+1;lli pos=1;
	for(int i=1;i<=k-1;i++){
		if(prev==m){
			if((pos+w)<=n){
				cout<<pos+w<<" ";
				pos=pos+w;
				prev=w;
				dis+=w;
			}
			else if((pos-w)>=1){
				cout<<pos-w<<" ";
				pos=pos-w;
				prev=w;
				dis+=w;
			}
			else{
				dis+=m;
				if((pos+m)<=n){
					cout<<pos+m<<" ";
					pos=pos+m;
				}
				else{
					cout<<pos-m<<" ";
					pos=pos-m;
				}
			}
		}
		else{
			if((pos+m)<=n){
				cout<<pos+m<<" ";
				pos=pos+m;
				prev=m;
				dis+=m;
			}
			else if((pos-m)>=1){
				cout<<pos-m<<" ";
				pos=pos-m;
				prev=m;
				dis+=m;
			}
			else{
				dis+=w;
				if((pos+w)<=n){
					cout<<pos+w<<" ";
					pos=pos+w;
				}
				else{
					cout<<pos-w<<" ";
					pos=pos-w;
				}
			}
		}
	}
	lli rem=abs(s-dis);
	if(pos+rem<=n){
		cout<<pos+rem;
	}
	else cout<<pos-rem;
}
