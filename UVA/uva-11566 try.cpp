#include<bits/stdc++.h>
using namespace std;
int n,x,t,k,amount,tea;
int dp[210][210],a[210],fl[210];
int calc(int id,int tot,int pr,int dish){
	if(id==k) return 0;
	if(dish>(2*(n+1))) return 0;
	if(tot>amount) return 0;
	if(dp[pr][dish]!=-1) return dp[pr][dish];
	int ans=0;
	if(tot+a[id]+int(ceil((pr+a[id]+tea)/10.0))<=amount){
		ans=max(fl[id]+calc(id+1,tot+a[id],pr+a[id],dish+1),calc(id+1,tot,pr,dish));
	}
	else ans=calc(id+1,tot,pr,dish);
	return dp[pr][dish]=ans;
}
int main(){
	scanf("%d %d %d %d",&n,&x,&t,&k);
	while(n!=0||x!=0||t!=0||k!=0){
		memset(fl,0,sizeof fl);
		for(int i=0;i<k;i++){
			int x;
			scanf("%d",&x);
			a[2*i]=x;a[2*i+1]=x;
			for(int j=0;j<=n;j++){
				scanf("%d",&x);
				fl[2*i]+=x;fl[2*i+1]+=x;
			}
		}k=k+k;
		memset(dp,-1,sizeof dp);
		amount=x*(n+1);tea=(n+1)*t;
		double ans=calc(0,tea,0,0);
		printf("%.2f\n",ans/(n+1));
		scanf("%d %d %d %d",&n,&x,&t,&k);
	}
}
