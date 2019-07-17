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
	int n,x,y;
	cin>>n;
	vpii v;
	FOR0(n){
		cin>>x>>y;
		v.pb(mp(x,y));
	}	
	x=-1;y=inf;
	sort(all(v));
	pii fr[n+2],bk[n+2];
	map<int,int>m;
	FOR0(n){
		int f=v[i].ff;
		int s=v[i].ss;
		x=f;
		y=min(y,s);
		fr[i+1]=mp(x,y);
	}
	x=v[n-1].ff;y=inf;
	for(int i=n-1;i>=0;i--){
		int f=v[i].ff;
		int s=v[i].ss;
		y=min(y,s);
		bk[i+1]=mp(x,y);
	}
	int mx=0;
//	for(int i=1;i<=n;i++){
//		int x1=fr[i].ff,y1=fr[i].ss,x2=bk[i].ff,y2=bk[i].ss;
//			cout<<"x1 "<<x1<<" "<<y1<<endl;
//		cout<<"x2 "<<x2<<" "<<y2<<endl;
//	}
	fr[0]=mp(0,inf);bk[n+1]=mp(0,inf);
	for(int i=1;i<=n;i++){
		int x1=fr[i-1].ff,y1=fr[i-1].ss,x2=bk[i+1].ff,y2=bk[i+1].ss;
		//	cout<<"x1 "<<x1<<" "<<y1<<endl;
		//cout<<"x2 "<<x2<<" "<<y2<<endl;
		if(y1<x1||y2<x2) continue;
		if(y1<x2) continue;
		int mn=min(y1,y2);
		int mxx=max(x1,x2);
		//cout<<mn-mx<<endl;
		mx=max(mx,mn-mxx);
	}
	cout<<mx;
}
