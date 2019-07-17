#include<bits/stdc++.h>
using namespace std;
 
int m, n;
int p[110], f[110];
int dp[110][15000];
 
int calc(int i, int w) {
    if(w > m && m < 1800)
        return -1000;
    if(w > m + 200)
        return -1000;
    if(i == n) {
        if(w > m && w <= 2000)
            return -1000;
        return 0;
    }
    if(dp[i][w] != -1)
        return dp[i][w];
 
    return dp[i][w] = max(calc(i + 1, w), \
        f[i] + calc(i + 1, w + p[i]));
}
 
int main(){
	while(scanf("%d %d", &m, &n) == 2){
		memset(dp,-1,sizeof dp);
		for(int i=0;i<n;i++){
			scanf("%d %d",&p[i],&f[i]);
		}
	//	if(m>2000) m=m+200;
		printf("%d\n",calc(0,0));
	}
}
