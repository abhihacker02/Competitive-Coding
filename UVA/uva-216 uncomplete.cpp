#include<bits/stdc++.h>
using namespace std;
int mask,n;int dp[10][1<<9];
int a[10][2];
int calc(int pos,int mask){
	if(dp[pos][mask]!=99999999) return dp[pos][mask];
	if(mask==(1<<n)-1){
		
	}int ans=99999999;
	for(int i=0;i<n;i++){
		if(i!=pos&&!mask&(1<<i)){
			dp[i][mask|(1<<i)]=min(dp[i][mask|(1<<i)],dp[pos][mask]+calc(i,mask|(1<<i)));
		}
	}
}
int main(){
	cin>>n;
	while(n!=0){
		for(int i=0;i<n;i++){
			cin>>a[i][0]>>a[i][1];
		}
		memset(dp,99999999,sizeof dp);
		int ans=calc(-1,0);
	}
}
