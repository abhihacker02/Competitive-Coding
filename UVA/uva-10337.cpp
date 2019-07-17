#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define oo 1000000007;
lli dp[12][1005];
int a[10][1005];
int n;
lli calc(int alt,int i){
	if(i==n&&alt==0) return 0;
	if(alt>9||alt<0||i==n) return oo;
	if(dp[alt][i]!=-1) return dp[alt][i];
	return 
	dp[alt][i]=
	min(min(lli(30)-a[alt][i]+calc(alt,i+1),lli(20)-a[alt][i]+calc(alt-1,i+1)),lli(60)-a[alt][i]+calc(alt+1,i+1));
}
int main(){
	int t;string bl;
	scanf("%d",&t);
	while(t--){
		getline(cin,bl);
		memset(dp,-1,sizeof dp);
		scanf("%d",&n);
		n=n/100;
		for(int i=9;i>=0;i--) for(int j=0;j<n;j++) scanf("%d",&a[i][j]);
		lli ans=calc(0,0);
		printf("%lld\n",ans);
		printf("\n");
	}
}
