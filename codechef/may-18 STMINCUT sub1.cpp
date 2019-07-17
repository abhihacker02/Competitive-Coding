#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);int c=0,t=0;
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		for(int i=0;i<n;i++){
			if(a[i]=='.'){
				if(t<3) t++;
				else{
					c++;
					t=1;
				}
			}
			else{
				c++;
			}
		}
		printf("%d\n",c);
	}
}
