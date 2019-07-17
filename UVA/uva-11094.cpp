#include<bits/stdc++.h>
using namespace std;
char g[25][25];int m,n;
int dr[]={0,1,0,-1};
int dc[]={1,0,-1,0};
int calc(int x,int y,char ch2){
//	cout<<ch2;
	if(y==n) y=0;if(y<0) y=n-1;
	if(x<0||x>m-1||y<0||y>n-1) return 0;
	if(g[x][y]=='.'||g[x][y]==ch2) return 0;
	else{
		int ans=1;
		g[x][y]='.';
		for(int i=0;i<4;i++){
			//x=x+dr[i];y=y+dc[i];
			//if(y==n) y=0;
			ans+=calc(x+dr[i],y+dc[i],ch2);
		}
			return ans;
	}
}
int main(){
	int p1,p2;char ch1,ch2;
	while(scanf("%d %d",&m,&n)!=EOF){
		for(int i=0;i<m;i++) scanf("%s", g[i]);
		scanf("%d %d",&p1,&p2);
		ch1=g[p1][p2];
			for(int i=0;i<m;i++)
			for(int j=0;j<n;j++) if(g[i][j]!=ch1){
				ch2=g[i][j];break;
			}
		int k=calc(p1,p2,ch2),mx=0;
		//	cout<<ch2<<endl;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				int pa=calc(i,j,ch2);
				if(pa>mx) mx=pa;
			}
		}
		printf("%d\n",mx);string s;
		getline(cin,s);
	}
}
