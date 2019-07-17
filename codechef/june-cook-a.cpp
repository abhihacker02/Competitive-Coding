#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define FOR0(n) for(int i=0;i<n;i++)
#define FOR(a,n) for(int i=a;i<n;i++)
#define FORQ(a,n) for(int i=a;i<=n;i++)
#define inf 1000000005
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
typedef pair<double,double> pii;
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
	while(t--){
		vpii v;
		vpii vm;
		v.clear();
		vm.clear();
		int n;
		cin>>n;
		double x,y;
		lli avg=0;
		for(int i=1;i<=n;i++){
			cin>>x>>y;
			avg+=y;
			vm.pb(mp(x,y));
			v.pb(mp(y,x));
		}
		double av=avg/(double(n));
		sort(all(v));
		sort(all(vm));
		int c=0;
		double sum=0;
		int ans=0;
		int nm=0,mn=inf;
	/*	for(int i=0;i<n;i++){
			if((sum+v[i].fs)/(nm+1)<=min(mn,v[i].sc)){
				mn=min(mn,v[i].sc);
				sum+=v[i].fs;
				nm++;
			}
			else{
			/*	ans=max(ans,nm);
				mn=inf;
				sum=0;
				nm=0;
				if(v[i].sc>=v[i].fs){
					sum=v[i].fs;nm=1;mn=v[i].sc;
				}
				continue;
			}
			}*/
			int f=0,l=n-1;
			while(n>0){
				if(vm[f].fs>=av){
					break;
				}
				else{
					if((avg-vm[f].sc)/(n-1)<=vm[f+1].fs){
						n--;break;
					}
					if((avg-v[l].fs)/(n-1)<=vm[f].fs){
						n--;break;
					}
					else{
						avg-=vm[f].sc-v[l].fs;
						n-=2;f++;l--;
					}
				}
			}
			//ans=max(ans,nm);
		cout<<n<<endl;
	}
	
}
