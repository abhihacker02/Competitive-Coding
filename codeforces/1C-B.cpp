#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int dp[100005][100005],n,a[100005];
int calc(int i,lli sum,int cnt){
	if(i==n) return 0;
	if (dp[i][cnt]!=-1) return dp[i][cnt];
	
	if(sum<=(6*a[i])){
		
		return dp[i][cnt]=max((1+(calc(i+1,sum+a[i],cnt+1))),calc(i+1,sum,cnt));
	}
	else {
		
	return dp[i][cnt]=calc(i+1,sum,cnt);}
}
int main(){
	int t;
	cin>>t;
	for(int w=1;w<=t;w++){
		memset(dp,-1,sizeof dp);
		cin>>n;
		for(int i=0;i<n;i++) cin>>a[i];
		int ans=calc(0,0,0);
		cout<<"Case #"<<w<<": "<<ans<<endl;
	}
}
