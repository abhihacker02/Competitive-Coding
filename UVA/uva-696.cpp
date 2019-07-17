#include<bits/stdc++.h>
using namespace std;
int main(){
	int r,c;
	scanf("%d %d",&r,&c);
	while(r!=0&&c!=0){
		int ans=0;
		if(r<=2&&c<=2) ans=r*c;
		else if(r>=3&&c>=3) ans=(((max(r,c)+1)/2)*((min(r,c)+1)/2))+(((max(r,c))/2)*((min(r,c))/2));
		else if(r==1||c==1) ans=max(r,c);
		else if(r==2&&c==3||r==3&&c==2) ans=4;
		else if(r<=2||c<=2) {
			int m=max(r,c);
			while(m>0){
				ans+=min(m,2)*2;
				m=m-4;
			}
		}
		printf("%d knights may be placed on a %d row %d column board.\n",ans,r,c);
		scanf("%d %d",&r,&c);
	}
}
