#include<bits/stdc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define SUM(v) accumulate(v.begin(),v.end(),lli(0))
#define rev(n,d) for(int i=n;i>=d;i--)
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
	int n,m;
	cin>>n>>m;
	int a[n];
	set<pii>s;
	FOR0(n) cin>>a[i];
	int c[n];
	FOR0(n) cin>>c[i];
	FOR0(n) {
		s.insert(mp(c[i],i));
	}
	set<pii>::iterator it;
	lli ans[m];
	mem(ans,0);
	int q[m][2];
	int t,d;
	FOR0(m){
		cin>>t>>d;
		t--;
		q[i][0]=t;q[i][1]=d;
	}
	FOR0(m){
		t=q[i][0];
		d=q[i][1];
		if(s.empty()){
			ans[i]=0;
			break;
		}
		if(a[t]>=d){
		//	cout<<"f\n";
			ans[i]=c[t]*d;
			it=s.find(mp(c[t],t));
			s.erase(it);
			a[t]-=d;
			if(a[t]>0) s.insert(mp(c[t],t));
		}
		else{
			it=s.find(mp(c[t],t));
			s.erase(it);
			d-=a[t];
			ans[i]=c[t]*a[t];
			a[t]=0;
		//	cout<<c[t]<<" cds "<<a[t]<<endl;
			int f=0;
			while(d>0){
				if(s.empty()){
					f=1;break;
				}
				it=s.begin();
				s.erase(it);
				int id=(*(it)).ss;
				int nm=a[id];
				int cs=(*(it)).ff;
				if(nm>=d){
					ans[i]+=(d*cs);
					nm-=d;
					a[id]-=d;
					if(nm>0){
						s.insert(mp(c[id],id));
					}
					d=0;
				}
				else{
					ans[i]+=(nm*cs);
					d-=nm;
					a[id]=0;
				}
			}
			if(f==1){
				ans[i]=0;
				break;
			}
		}
	}
	FOR0(m) cout<<ans[i]<<endl;	
}


