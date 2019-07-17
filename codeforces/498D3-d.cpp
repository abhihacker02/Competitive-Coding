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
	fast
	map<char,int>m;
	int n;
	cin>>n;
	string s1,s2;
	cin>>s1>>s2;
	int ans=0;
	if(n==1&&s1[0]!=s2[0]){
		cout<<1;return 0;
	}
	map<char,int>::iterator it;
	FOR0(n){
		if(n%2!=0&&i==n/2){
			if(s1[i]!=s2[i]) ans++;
			continue;
		}
		m[s1[i]]++;
		m[s2[i]]++;
		m[s2[n-i-1]]++;
		m[s1[n-i-1]]++;
		if(m.size()==3) {
			if(s1[i]==s1[n-i-1]) ans+=2;
			else ans+=1;
		}
		if(m.size()==4) ans+=2;
		if(m.size()==2){
			it=m.begin();
			int k1=it->ss;
			it++;
			int k2=it->ss;
			if(k1!=k2) ans++;
		}
		m.clear();
	}
	if(n%2!=0&&s1[n/2]!=s2[n/2]){
		ans++;
	}
	cout<<ans/2<<endl;
}
