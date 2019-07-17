#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopb(i,a,b) for(int i=a;i>=b;i--)
#define loopm(i,a,b,step) for(int i=a;i<b;i+=step)
#define loopbm(i,a,b,step) for(int i=a;i>=b;i-=step)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define INF 1000000007
#define BINF 1000000000000000001
#define int long long int
#define double long double
 
using namespace std;
 
const int MOD=1e9+7;
 
const int N=4e5+5;
 
int fact[N];
int invfact[N];
 
int fxp(int a,int b)
{
	int res=1;
	while(b>0)
	{
		if(b&1ll) res=(res*a)%MOD;
		b>>=1ll;
		a=(a*a)%MOD;
	}
	return res;
}
 
bool cmp(pair<int,int>a,pair<int,int>b)
{
	if(a.first!=b.first) return a.first<b.first;
	else return a.second>b.second;
}
 
#undef int
int main()
{
#define int long long int
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt","r",stdin);
    fact[0]=1;
    loop(i,1,N) fact[i]=(fact[i-1]*i)%MOD;
    
    loop(i,0,N) invfact[i]=fxp(fact[i],MOD-2)%MOD;
    
    int t;
    cin>>t;
    while(t--)
    {
    	int n,k;
    	cin>>n>>k;
    	pair<int,int>x[n];
    	loop(i,0,n) cin>>x[i].first>>x[i].second;
    	
    	sort(x,x+n);
    	
    	int ans=(fact[n]*invfact[k])%MOD;
    	ans*=invfact[n-k];
    	ans%=MOD;
    	
    	multiset<int>lines;
    	int bad=0;
    	loop(i,0,n)
    	{
    		while(!lines.empty())
    		{
    			auto it=lines.begin();
    			if(*it>=x[i].first) break;
    			lines.erase(lines.begin());
    		}
    		
    		int sz=lines.size();
    		
    		if(sz>=k-1)
    		{
    			int curr=(fact[sz]*invfact[k-1])%MOD;
    			curr*=invfact[sz-k+1];
    			curr%=MOD;
    			bad+=curr;
    			bad%=MOD;
    		}
    		lines.insert(x[i].second);
    	}
    	
    	ans-=bad;
    	ans+=MOD;
    	ans%=MOD;
    	cout<<ans<<endl;
    	
    }
    
    return 0;
} 
