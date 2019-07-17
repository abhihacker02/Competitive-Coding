#include<bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long int lli;
lli m,n,q,d,a[205],dp[205][15][205];
lli ways(int i,lli elem,lli val){
	if(elem==m) return (val==0?1:0);
	if(i==n) return 0;
	if(dp[i][elem][val]!=-1) return dp[i][elem][val];
	lli ans=0;
	ans=ways(i+1,elem+1,(val+a[i])%d)+ways(i+1,elem,val%d);
	return dp[i][elem][val%d]=ans;
//	return ans;
}
int main(){
	scanf("%d %d",&n,&q);int p=1;
	while(n!=0&&q!=0){
		printf("SET %d:\n",p);p++;
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		for(int i=0;i<q;i++){
			memset(dp,-1,sizeof dp);
			scanf("%d %d",&d,&m);
			lli ans=ways(0,0,0);
			printf("QUERY %d: %d\n", i+1, ans);
		}
		scanf("%d %d",&n,&q);
	}
}
