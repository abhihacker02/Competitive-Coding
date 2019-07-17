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
//multimap<int,int>m;
bool myfunction (int i,int j) { return (i<j); }
int main(){
	fast
	int n;
	vector<lli> v;
	cin>>n;
	lli a[n];
	int ans[n]={};
	FOR0(n){
	cin>>a[i];v.pb(a[i]);}
//	sort(a,a+n);
	sort(all(v));
//	FOR0(n) cout<<v[i]<<" ";cout<<endl;
	vector<lli>::iterator it;
	FOR0(n){
	//	if(ans[i]==1) continue;
		for(int j=0;j<33;j++){
			lli k=lli(1)<<j;
			lli f=k-v[i];
		//	cout<<f<<endl;
			if(f>=0){
				it=upper_bound(v.begin(),v.end(),f);
				if(it!=v.end()){
					
					int in=it-v.begin();
					if(v[in-1]==f&&in-1!=i){
//						cout<<v[i]<<" "<<f<<"p"<<endl;
						ans[i]=1;ans[in-1]=1;
					//	break;
					}
				}
				else{
					int in=n-1;
					if(v[in]==f&&i!=n-1){
//						cout<<v[i]<<" "<<f<<"k"<<endl;
						ans[i]=1;ans[in]=1;//break;
					}
				}
			/*	if (binary_search (v.begin()+i+1, v.end(), f, myfunction)){
					ans[i]=1;
					break;
				}*/
			}
		}
	}
//	cout<<endl;
//	FOR0(n) cout<<ans[i]<<" ";cout<<endl;
	int c=0;
	FOR0(n) if(ans[i]==0) c++;
	cout<<c;
}
