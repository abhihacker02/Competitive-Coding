#include<bits/stdc++.h>
using namespace std;
int main(){
	int s,b;
	scanf("%d %d",&s,&b);
	while(s!=0 && b!=0){
		int a[s+1][2];
		for(int i=1;i<=s;i++){
			if(i==s){
				a[i][0]=s-1;a[i][1]=0;
			}
			else{
				a[i][0]=i-1;a[i][1]=i+1;
			}
		}
		a[0][0]=0;a[0][1]=0;
		while(b--){
			int x,y;
			scanf("%d %d",&x,&y);
			int l=a[x][0];int r=a[y][1];
			a[a[x][0]][1]=a[y][1];a[a[y][1]][0]=a[x][0];
			if(l>0) printf("%d ",l);
			else printf("* ");
			if(r>0) printf("%d\n",r);
			else printf("*\n");
			if(b==0) printf("-\n");
		}
		scanf("%d %d",&s,&b);
	}
}
