#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define FOR0(n) for(int i=0;i<n;i++)
#define FOR(a,n) for(int i=a;i<n;i++)
#define FORQ(a,n) for(int i=a;i<=n;i++)
#define inf 1e14
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
typedef pair<int,int> pii;
typedef pair<int,pii>ppii;
typedef vector<int>vi;
typedef vector<vi>vvi;
typedef vector<pii>vpii;
const int N=100005;
int dr8[]={0,0,1,-1,1,1,-1,-1};
int dc8[]={1,-1,0,0,-1,1,-1,1};
int dr[]={0,1,-1,0};
int dc[]={1,0,0,-1};
lli gcd (lli a, lli b){
    a =abs(a); b = abs(b);
    return (b==0) ? a : gcd(b, a%b);
  }

int main(){
	fast
	lli l,r,x,y;
	cin>>l>>r>>x>>y;
	lli c=0;
	lli square_root = (int) sqrt(x*y) + 1;
	lli num=x*y;
for (lli i = 1; i < square_root; i++) { 
    if (num % i == 0&&i*i!=num)
        if(gcd(i,num/i)==x&&((i>=l&&i<=r)&&((num/i)>=l)&&(num/i)<=r)) c+=2;
    if (num % i == 0&&i*i==num)
        if(i==x&&(i>=l&&i<=r))c++;
}
cout<<c<<endl;;
}
