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
	set<int>s;
	fast
	int n,k;
	cin>>n>>k;
	int a[n],b[n];
	FOR0(n){
		cin>>a[i];b[i]=a[i];
	}
	sort(b,b+n);
	vi v;
	int c=0;lli sum=0;
	rev(n-1){
		sum+=b[i];
		c++;
		v.pb(b[i]);
		if(c==k) break;
	}
	vi t;
		for(int i=0;i<v.size();i++){
			for(int j=0;j<n;j++){
				if(a[j]==v[i]&&s.find(j)==s.end()){
					s.insert(j);
					t.pb(j);break;
				}
			}
		}
		sort(all(t));
		if(t.size()==1){
			cout<<sum<<endl;
			cout<<n;return 0;
		}
		cout<<sum<<endl;
		for(int i=0;i<t.size();i++){
			if(i==0){
				cout<<t[i]+1<<" ";
			}
			else if(i==t.size()-1){
				cout<<n-t[i-1]-1<<" ";
			}
			else cout<<t[i]-t[i-1]<<" ";
		}
}
