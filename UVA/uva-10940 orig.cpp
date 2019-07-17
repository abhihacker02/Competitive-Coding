#include<bits/stdc++.h>
using namespace std;
int dp[500005];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	dp[1]=1;
	dp[2]=2;
	dp[3]=2;
	dp[4]=4;
	for(int i=5;i<=500005;i++){
		int prev=dp[i-1];
		if(prev==i-1) dp[i]=2;
		else dp[i]=prev+2;
	}
	int n;
	cin>>n;
	while(n!=0){
		cout<<dp[n]<<endl;
		cin>>n;
	}
}
