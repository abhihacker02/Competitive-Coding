#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int a[10005];
int main(){
	int n;
	scanf("%d",&n);
	while(n!=0){
		lli ans=0,sum=0;
		for(int i=0;i<n;i++){
		 scanf("%d",&a[i]);
		 sum+=a[i];
		 ans=max(sum,ans);
		 if(sum<0) sum=0;
		 }
		 if(ans>0) printf("The maximum winning streak is %lld.\n",ans);
		 else printf("Losing streak.\n");
		scanf("%d",&n);
	}
}
