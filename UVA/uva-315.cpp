#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int vis[105];
int art[105];
int low[105];
int num[105];
int par[105];
vector<int>gr[105];
int child=0,cnt=0,root;
void dfsArt(int u){
	vis[u]=1;
	num[u]=low[u]=cnt;
	cnt++;
	for(int i=0;i<gr[u].size();i++){
		int v=gr[u][i];
		if(!vis[v]){
			par[v]=u;
			if(u==root) child++;
			dfsArt(v);
			if(num[u]<=low[v])
			art[u]=1;
			low[u]=min(low[u],low[v]);
		}
		else if(v!=par[u]) 
			low[u]=min(low[u],num[v]);
	}
}
int main(){
	
	int n,x,y;string s;char c;
	scanf("%d",&n);
	while(n!=0){
		for(int i=0;i<105;i++) gr[i].clear();
		cnt=0;
	memset(vis,0,sizeof vis);
	memset(art,0,sizeof art);
	memset(low,0,sizeof low);
	memset(num,0,sizeof num);
	memset(par,0,sizeof par);
  while(scanf("%d", &x) == 1 && x) {
   while(scanf("%d%c", &y, &c) == 2) {
    gr[x-1].pb(y-1);
    gr[y-1].pb(x-1);
    if(c == '\n') break;
   }
  }
//  for(int i=0;i<n;i++){
  //	for(int j=0;j<gr[i].size();j++) cout<<i<<"->"<<gr[i][j]<<" ";cout<<endl;
  //}
            for(int i=0;i<n;i++){
            	if(!vis[i]){
            		root=i;
            		child=0;
            		dfsArt(i);
            		if(child>=2) art[i]=1;
            		else art[i]=0;
				}
			}
			int ans=0;
			for(int i=0;i<n;i++) if(art[i]==1) {
			//printf("%d ",i);
			ans++;}//cout<<endl;
			printf("%d\n",ans);
			scanf("%d",&n);
	}
}
