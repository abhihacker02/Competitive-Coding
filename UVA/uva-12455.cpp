#include<bits/stdc++.h>
using namespace std;
int f=0,asked,n;
int a[25];
void see(int i,int sum){
	if(sum==asked){
		f=1;return ;
	}
	if(i==n) return ;
	see(i+1,sum+a[i]);
	see(i+1,sum);
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&asked);
		scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		f=0;
		see(0,0);
		if(f==1){
			printf("YES\n");
		}
		else printf("NO\n");
	}
}
