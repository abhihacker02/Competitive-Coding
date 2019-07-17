#include<bits/stdc++.h>
using namespace std;
#define pb push_back
vector< vector<int> >v;
stack<int>s;
int vis[105]={0};
void DFS(int i){
	if(vis[i]==1) return;
	vis[i]=1;
	for(int j=0;j<v[i].size();j++){
		if(vis[v[i][j]]==1) continue;
		DFS(v[i][j]);
	}
	s.push(i);
}
int main(){
	int n,m;
	while(5){
		s.empty();
		for(int i=0;i<=105;i++) vis[i]=0;
		v.resize(105);
		cin>>n>>m;int x,y;
		if(n==0&&m==0) break;
		while(m--){
			cin>>x>>y;
			v[x].pb(y);
		}
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				vis[i]=0;
				DFS(i);
			}
		}
		int k=s.size();
		for(int i=0;i<k;i++){
			cout<<s.top()<<" ";s.pop();
		}
		cout<<endl;
	}
}
