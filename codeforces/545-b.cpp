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
	int n;
	cin>>n;
	string c,a;
	cin>>c;
	cin>>a;
	vector<int>v,b,clo,acr,em;
	int cl=0,ac=0,z=0;
	int t=0;
	FOR0(n){
		if(c[i]=='1'&&a[i]=='1'){
			t++;
			b.pb(i);
		}
		else if(c[i]=='1') {
		cl++;clo.pb(i);}
		else if(a[i]=='1') {
		ac++;acr.pb(i);}
		else {
		z++;em.pb(i);}
	}
	if(cl==ac){
		if(t%2==0){
			for(int i=0;i<clo.size();i++) cout<<clo[i]+1<<" ";
			for(int i=0;i<t/2;i++) cout<<b[i]+1<<" ";
			for(int i=0;i<z/2;i++) cout<<em[i]+1<<" ";
		}
		else{
			if(ac==0){
				cout<<-1;return 0;
			}
			for(int i=0;i<t/2;i++) cout<<b[i]+1<<" ";
			for(int i=0;i<z/2;i++) cout<<em[i]+1<<" ";
			for(int i=0;i<cl;i++) cout<<clo[i]+1<<" ";
			cout<<ac[0]+1<<" ";
		}
	}
	else{
		if(cl<ac){
			
		}
		else{
			
		}
	}
}


