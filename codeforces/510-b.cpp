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
	int n;
	cin>>n;
	int ans=inf;
	int cs;string s;
	int a=inf,b=inf,c=inf,ab=inf,bc=inf,ca=inf,abc=inf;
	FOR0(n){
		cin>>cs>>s;
		int A=0,B=0,C=0;
		for(int j=0;j<s.length();j++){
			if(s[j]=='A')A=1;
			if(s[j]=='B')B=1;
			if(s[j]=='C')C=1;
		}
		if(A==1) a=min(a,cs);
		if(B==1) b=min(b,cs);
		if(C==1) c=min(c,cs);
		if(A==1&&B==1) ab=min(ab,cs);
		if(A==1&&C==1) ca=min(ca,cs);
		if(B==1&&C==1) bc=min(bc,cs);
		if(A==1&&B==1&&C==1) abc=min(abc,cs);
	}
	ans=min(ans,a+b+c);
	ans=min(ans,ab+c);
	ans=min(ans,ca+b);
	ans=min(ans,bc+a);
	ans=min(ans,abc);
	if(ans==inf) cout<<-1;
	else cout<<ans;
}

