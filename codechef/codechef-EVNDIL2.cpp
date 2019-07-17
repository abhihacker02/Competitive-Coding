#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod = 1e9+7; 
ll power(ll n,ll k)
{
	if(k==0)return(1);
	if(k==1)return((n+mod)%mod);
	ll ans;
	if(k%2==0)
		ans=power((n*n+mod)%mod,k/2);
	else ans=(n*(power((n*n)%mod,k/2))+mod)%mod;
	while(ans<mod)ans+=mod;
	ans = ans%mod;
	return(ans);
} 
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		
		ll ans,k;
		cin>>k;
		ans = ((ll)(5*power(10,k-1) + 4*power(8,k-1))+mod)%mod;
		cout<<ans<<endl;
	}
	return(0);
} 
