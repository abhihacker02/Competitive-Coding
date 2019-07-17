#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
 
	int t,n,m;
 
	string s1,s2;
 
	cin>>t;
 
	while(t--){
 
		cin>>n>>m;
 
		cin>>s1>>s2;
 
		int dp[n+m];
 
		int alph1[26]={0};
 
		int aplh2[26]={0};
 
		dp[0]=1;alph1[s1[0]-97]++;
 
		for(int i=1;i<n;i++){
 
 
			if(s1[i]==s1[i-1]) dp[i]=dp[i-1];
 
			else {dp[i]=dp[i-1]+1;alph1[s1[i]-97]++;}
 
		}
 
		for(int i=0;i<m;i++){
 
			if(i==0&&alph1[s2[i]-97]>0) {
 
			dp[i+n]=dp[i+n-1];alph1[s2[i]-97]--;}
 
			else if(i==0) dp[i+n]=dp[i+n-1]+1;
			
			if(i>0){
 
				if(s2[i]==s2[i-1]) dp[i+n]=dp[i+n-1];
 
				else if(alph1[s2[i]-97]>0){
 
					alph1[s2[i]-97]--;dp[i+n]=dp[i+n-1];
 
				}
 
				else dp[i+n]=dp[i+n-1]+1;
 
			}
 
		}
 
		cout<<dp[m+n-1]<<endl;
 
	}
 
} 
