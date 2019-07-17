#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int pr[25][25];
int dp[205][25],m,c,n;
int count(int gar,int total){
	if(total<0) return -100000000;
	if(gar==c) return m-total;
	if(dp[total][gar]!=-1) return dp[total][gar];
	int ans=-1;
	for(int i=1;i<=pr[gar][0];i++){
		int temp=count(gar+1,total-pr[gar][i]);
		ans=max(temp,ans);
	}
	return dp[total][gar]=ans;
}
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d %d",&m,&c);
		for(int i=0;i<c;i++){
			scanf("%d",&pr[i][0]);
			for(int j=1;j<=pr[i][0];j++) scanf("%d",&pr[i][j]);
		}
		memset(dp,-1,sizeof dp);
		int ans=count(0,m);
		if(ans>0) printf("%d\n",ans);
		else printf("no solution\n");
	}
	return 0;
}
