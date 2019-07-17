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
int l;
string s;
int cnt[6];string ans[6];
int dr8[]={0,0,1,-1,1,1,-1,-1};
int dc8[]={1,-1,0,0,-1,1,-1,1};
int dr4[]={0,1,-1,0};
int dc4[]={1,0,0,-1};
void col(char a,char b,char c,int in){
	for(int i=0;i<l;i+=3) {
	if(s[i]!=a) cnt[in]++; ans[in][i]=a;}
	for(int i=1;i<l;i+=3) {
	if(s[i]!=b) cnt[in]++; ans[in][i]=b;}
	for(int i=2;i<l;i+=3) {
	if(s[i]!=c) cnt[in]++; ans[in][i]=c;}
}
int main(){
	fast
	cin>>l;
	cin>>s;
	FOR0(6) ans[i]=s;
	mem(cnt,0);
	col('B','G','R',0);
	col('B','R','G',1);
	col('R','G','B',2);
	col('R','B','G',3);
	col('G','B','R',4);
	col('G','R','B',5);
	int mn=min(cnt[0],min(cnt[1],min(cnt[2],min(cnt[3],min(cnt[4],cnt[5])))));
//	FOR0(6) cout<<ans[i]<<" ";cout<<endl;
	if(mn==cnt[0]){
		cout<<cnt[0]<<endl;
		 cout<<ans[0];
	}
	else if(mn==cnt[1]){
		cout<<cnt[1]<<endl;
		 cout<<ans[1];
	}
	else if(mn==cnt[2]){
		cout<<cnt[2]<<endl;
		 cout<<ans[2];
	}
	else if(mn==cnt[3]){
		cout<<cnt[3]<<endl;
		 cout<<ans[3];
	}
	else if(mn==cnt[4]){
		cout<<cnt[4]<<endl;
		 cout<<ans[4];
	}
	else if(mn==cnt[5]){
		cout<<cnt[5]<<endl;
		 cout<<ans[5];
	}


