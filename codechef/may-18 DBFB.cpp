#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long int lli;
int a[100005],b[100005];
int fib[100005];
int main(){
	fib[0]=1;fib[1]=1;fib[2]=2;
	for(int i=3;i<100005;i++){
		fib[i]=(fib[i-1]%mod+fib[i-2]%mod)%mod;
	}
	int t;
	cin>>t;
	while(t--){
		int m,n;
		int suma=0,sumb=0;lli ma,mb;
		cin>>m>>n;
		for(int i=0;i<m;i++) {
		cin>>a[i];suma=(suma+a[i])%mod;}
		for(int i=0;i<m;i++) {
		cin>>b[i];sumb=(sumb+b[i])%mod;}
		if(n==1) {
			mb=0;ma=1;
		}
		else if(n==2){
			ma=0;mb=1;
		}
		else{
			ma=fib[n-3];mb=fib[n-2];
		}
		int ans=(m*((((ma*suma)%mod)+((mb*sumb)%mod))%mod))%mod;
		cout<<ans<<endl;
	}
}
