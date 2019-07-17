#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli gr[100005][2];
lli res[100005];
lli dp[100005];
int num[100005];
void DFS(int i,lli sum,int n,lli mn){
	if(dp[gr[i][0]]!=0){
		dp[i]=sum+min(dp[gr[i][0]],mn*num[gr[i][0]]);
		num[i]=n+num[gr[i][0]];
		return;
	}
	else{
		DFS(gr[i][0],sum+min(gr[gr[i][0]][1],mn),n+1,min(mn,gr[gr[i][0]][1]));
		dp[i]+=sum;
		num[i]++;
	}
}
int main(){
	int n,x;
	memset(dp,0,100005);
	memset(num,1,100005);
	cin>>n;gr[0][0]=0;
	for(int i=1;i<n;i++){
		cin>>x;
		gr[i][0]=x-1;
	}
	for(int i=0;i<n;i++){
		cin>>x;
		gr[i][1]=x;
	}
	dp[0]=gr[0][1];num[0]=1;
	cout<<gr[0][1]<<" ";
	for(int i=1;i<n;i++){
		DFS(i,gr[i][1],1,gr[i][1]);
		cout<<dp[i]<<" ";
	}
}
