#include<bits/stdc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> set_t;
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
	int n;
	cin>>n;
	int t=n;
	int tmp=n;
	int pw=0;
	while(tmp>0){
		pw++;
		tmp/=2;
	}
	pw--;
	int mx;
	int r=t/(1<<(pw-1));
	mx=r*(1<<(pw-1));
	if(n==1) {
		cout<<1;return 0;
	}
	if(n==3){
		cout<<1<<" "<<1<<" "<<3;return 0;
	}
	int p=0;
	int l;
	while(n>1){
		for(int i=1;i<=(n+1)/2;i++){
			cout<<(1<<p)<<" ";
		}
		l=1<<p;
		n-=(n+1)/2;
		p++;
	}
	//cout<<"l "<<l<<endl;
	if((1<<pw)==t){
		cout<<t;
	}
	else if(t%2==0&&t%l!=0){
		cout<<mx;
	}
	else if(t%2==0&&t%l==0){
		cout<<t;
	}
	else if(t%2!=0&&(t-1)%l==0){
		cout<<t-1;
	}
	else{
		cout<<mx;
	}
}

