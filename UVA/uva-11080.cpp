#include<bits/stdc++.h>
using namespace std;
#define pb push_back
vector<int> gr[205];
int col[205];
int main(){
	int n,nd;
	scanf("%d",&t);
	while(t--){
		int v,e;
		//cout<<n<<endl;
		scanf("%d %d",&v,&e);
		for(int i=0;i<205;i++) gr[i].clear();
		memset(col,-1,sizeof col);
		queue<int>q;
		for(int i=1;i<=e;i++){
			int x,y;
			scanf("%d %d",&x,&y);
			if(i==1) q.push(x);
			gr[x].pb(y);
			gr[y].pb(x);
		}
		col[q.front()]=1;int np=0;
		while(!q.empty()){
			int v=q.front();q.pop();
			for(int i=0;i<gr[v].size();i++){
				if(col[gr[v][i]]==-1){
					q.push(gr[v][i]);
					col[gr[v][i]]=col[v];
				}
				else if(col[gr[v][i]]!=col[v]){
					np=1;break;
				}
			}
		}
		if(np==0) printf("BICOLORABLE.\n");
		else printf("NOT BICOLORABLE.\n");
	}
}
