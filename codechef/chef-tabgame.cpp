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
	long long t;
	cin>>t;
	for(int z=0;z<t;z++)
	{
		string s1,s2;
		cin>>s1>>s2;
		int m,n,q;
		m = s1.length();
		n = s2.length();
		int arr1[3][m+1] = {0};
		int arr2[n+1][3] = {0};
		for(int i=1;i<=m;i++)
		{
			arr1[0][i] = (int)s1[i-1] - 48;
		}
		for(int j=1;j<=n;j++)
		{
			arr2[j][0] = (int)s2[j-1] - 48;
		}
		int l1=2,l2=2;
		if(m==1)
		{
			l1 = 1;
		}
		if(n==1)
		{
			l2 = 1;
		}
		for(int j=1;j<=l1;j++){
			arr2[0][j] = arr1[0][j];
			for(int i=1;i<=n;i++)
				if(arr2[i-1][j] ==0 || arr2[i][j-1]==0)
					arr2[i][j] = 1;
				else
				    arr2[i][j] = 0;
		}
		for(int j=1;j<=l2;j++){
			arr1[j][0] = arr2[j][0];
			for(int i=1;i<=m;i++)
				if(arr1[j-1][i]==0 || arr1[j][i-1]==0)
					arr1[j][i] = 1;
				else
				    arr1[j][i] = 0;
		}
		cin>>q;
		for(int i=0;i<q;i++)
		{
			long long a,b,des;
			cin>>a>>b;
			if(a<3 || b<3)
			{
				if(a<b)
				   cout<<arr1[a][b];
				else
				   cout<<arr2[a][b];
			}
			else
			{
				des = min(a,b);
				a = a - des + 2;
				b = b - des + 2;
				if(a<b)
				   cout<<arr1[a][b];
				else
				   cout<<arr2[a][b];
			}
		}
		cout<<endl;
	}
}
