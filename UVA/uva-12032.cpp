#include<bits/stdc++.h>
using namespace std;
int a[100005],n;
int can(int num){
	int k=0,f=0;
	for(int i=1;i<=n;i++){
		if(num<=0) {
		f=1;break;}
			if(a[i]-a[i-1]==num) num--;
			else if(a[i]-a[i-1]>num){
				f=1;break;
			} 
	}
	if(f==1) return 0;return 1;
}
int main(){
	int t,c,ans;
	scanf("%d",&t);c=t;
	while(t--){
		scanf("%d",&n);a[0]=0;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		int up=10000001,down=1,mid;
		while(up>down){
			mid=(up+down)/2;
			if(can(mid))
			{up=mid;ans=mid;}
			else down=mid+1;
		}
		printf("Case %d: %d\n",c-t,ans);
	}
}
