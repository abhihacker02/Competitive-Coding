#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli dp[5][300005];
lli a[]={1,5,10,25,50};
lli ways(int i,lli value){
	if(i==5) return 0;
	if(value<0) return 0;
	if(dp[i][value]!=-1) return dp[i][value];
	if(value==0) return 1;
	lli ans=0;
//	for(int j=i;j<5;j++){
		ans+=ways(i,value-a[i])+ways(i+1,value);
//	}
	dp[i][value]=ans;
	return ans;
}
int main(){
	int v;
	for(int i=0;i<5;i++){
		memset(dp[i],-1,sizeof dp[i]);
	}//scanf("%d",&v);
	while(scanf("%d",&v)!=EOF){
		//cout<<v;
		lli ans=ways(0,v);
		if(ans>1){
			printf("There are %lld ways to produce %d cents change.\n",ans,v);
		}
		else 
		printf("There is only 1 way to produce %d cents change.\n",v);
	}
}
