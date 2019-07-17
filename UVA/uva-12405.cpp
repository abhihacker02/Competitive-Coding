#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	int k=t;
	while(t--){
		int n;
		scanf("%d",&n);int c=0,tt=0;
		char a[n];
		scanf("%s", a);
		for(int i=0;i<n;i++){
			if(a[i]=='.'){
				if(tt<3) tt++;
				else{
					c++;
					tt=1;
				}
			}
			else{
				if(tt==1){
				c++;
				i++;
			}
			if(tt==2){
				c++;
			}
			if(tt==3){
				c++;
			}
			tt=0;
		}
	}
	if(tt>0) c++;
	printf("Case %d: %d\n",k-t,c);
	}
}
