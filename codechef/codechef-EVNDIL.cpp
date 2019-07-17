#include<bits/stdc++.h>
using namespace  std;
typedef long long int lli;
lli mod,sum;
lli ans[5][2];
lli power(lli n,lli k)
{
	if(k==0)return(1);
	if(k==1)return((n+mod)%mod);
	lli an;
	if(k%2==0)
		an=power((n*n+mod)%mod,k/2);
	else an=(n*(power((n*n)%mod,k/2))+mod)%mod;
	while(an<mod)an+=mod;
	an = an%mod;
	return(an);
} 
lli calc(lli n){
	if(n/2<=3){
		lli i=n/2, r=n-n/2;
		return ((ans[i][0]*ans[r][0])%mod+(ans[i][1]*ans[r][1])%mod +mod)%mod;
	}
	else{
		lli half=calc(n/2);lli rem=calc(n-n/2);
		return ((((half)*(rem))%mod +(((lli(power(10,n/2))%mod-half)) *(lli(power(10,n-n/2))%mod -rem)))%mod +mod)%mod;
	}
}
int  main(){
	mod=1000000007;
	ans[1][0]=9;ans[1][1]=1;ans[2][0]=82;ans[2][1]=18;ans[3][0]=756;ans[3][1]=244;ans[4][0]=7048;ans[4][1]=2952;
	int t;
	cin>>t;
	while(t--){
		lli n;
		cin>>n;
		if(n<=3) cout<<ans[n][0]%mod<<endl;
		else{
			sum=0;
			cout<<calc(n)%mod<<endl;
		}
	}
}
