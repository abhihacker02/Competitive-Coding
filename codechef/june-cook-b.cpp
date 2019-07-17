#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define FOR0(n) for(int i=0;i<n;i++)
#define FOR(a,n) for(int i=a;i<n;i++)
#define FORQ(a,n) for(int i=a;i<=n;i++)
#define inf 1e14
#define sz(a) int((a).size()) 
#define all(c) c.begin(), c.end()
#define fs first
#define sc second
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
int dr[]={0,1,-1,0};
int dc[]={1,0,0,-1};

int main(){
	fast
	int t;
	cin>>t;
	vi v;
	while(t--){
		int ans=0;
		v.clear();
		int n,k;
		cin>>n>>k;
		int a[n+1];
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}	
		for(int i=1;i<=n;i++) v.pb(i);
		do{
			int pos=1;
			for(int i=1;i<=n;i++){
				if(a[i]!=0&&a[i]!=v[i-1]){
					pos=0;break;
				}
			}
			if(pos==1){
				int c=0;
				for(int i=1;i<n;i++){
					if(v[i]>v[i-1]) c++;
				}
				if(c==k) ans++;
			}
			
		}while(next_permutation(v.begin(),v.end()) );
		cout<<ans<<endl;
}
}
