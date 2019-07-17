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
vpii v;
int main(){
	fast
	int n,m;
	cin>>n>>m;
	int a[n];
	int rem[m];
	mem(rem,0);
	FOR0(n){
		
	 cin>>a[i];
	 rem[a[i]%m]++;
	 }
	int dem=n/m;
	int pl[m],mn[m];
	int cpl[m],cmn[m];
	mem(pl,0);mem(mn,0);
	FOR0(m){
		if(rem[i]>dem) pl[i]=rem[i]-dem;
		else if(rem[i]<dem) mn[i]=dem-rem[i];
	}
	FOR0(m){
		cpl[i]=pl[i];cmn[i]=mn[i];
	}
	int ip=0,im=0;
	lli cost=0;
//	FOR0(m) cout<<pl[i]<<" ";cout<<endl;
//	FOR0(m) cout<<mn[i]<<" ";cout<<endl;
	while(true){
		if(pl[ip]==0){
			ip++;
		}
		else if(mn[im]==0){
			im++;
		}
		else{
			if(ip>im){
				int ad=min(pl[ip],mn[im]);
				cost+=(m-ip+im)*ad;
				pl[ip]-=ad;
				mn[im]-=ad;
			}
			else{
				int ad=min(pl[ip],mn[im]);
				cost+=(-ip+im)*ad;
					pl[ip]-=ad;
				mn[im]-=ad;
			}
		}
		if(im==m||ip==m) break;
	}
	cout<<cost<<endl;
	im=0,ip=0;
	int id=0;
//	FOR0(m) cout<<cpl[i]<<" ";cout<<endl;
//	FOR0(m) cout<<cmn[i]<<" ";cout<<endl;
	int d[n];mem(d,0);
	while(true){
	//	cout<<im<<" "<<ip<<endl;
		if(ip==n) break;
		if(cpl[a[ip]%m]==0) ip++;
		else if(cmn[im]==0) im++;
		else{
		//	cout<<ip<<" pik"<<im<<endl;
			if((a[ip]%m)>=im){
				int ad=m-a[ip]%m+im;
				d[ip]=ad;
				cpl[a[ip]%m]--;
				cmn[im]--;
				ip++;
			}
			else if((a[ip]%m)<im){
			//	cout<<ip<<"i"<<im<<endl;
				int ad=-(a[ip]%m)+im;
				d[ip]=ad;
				cpl[a[ip]%m]--;
				cmn[im]--;
				ip++;
			}
		}
	}
	FOR0(n) {
		if(d[i]==0) cout<<a[i]<<" ";
		else cout<<a[i]+d[i]<<" ";
	}
}
