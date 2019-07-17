#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int vis[26],ex[26];
vector<int>v[26];
vector<int>b;
int main(){
	int t,e;
	while(scanf("%d %d",&t,&e)!=EOF){
		for(int i=0;i<26;i++) {
		vis[i]=ex[i]=0;v[i].clear();}
		int c=3,y=0;string st,s;
		//scanf("%d",&e);
		cin>>st;
		vis[st[0]-65]=1;
		vis[st[1]-65]=1;
		vis[st[2]-65]=1;
		ex[st[0]-65]=1;ex[st[1]-65]=1;ex[st[2]-65]=1;
		while(e--){
			cin>>s;
			ex[s[0]-65]=1;ex[s[1]-65]=1;
			v[s[0]-65].pb(s[1]-65);
			v[s[1]-65].pb(s[0]-65);
		}
		while(4){
			if(c==t) break;
			b.clear();y++;
		for(int i=0;i<26;i++){
			int f=0;
			if(vis[i]==1) continue;
			if(ex[i]==1){
				for(int j=0;j<v[i].size();j++){
					if(vis[v[i][j]]==1) f++;
				}
				//cout<<f<<endl;
				if(f>=3) { b.pb(i);
				c++;}
				else if(c==t) break;
			}
		}
		if(b.size()==0||c==t) break;
		for(int j=0;j<b.size();j++) vis[b[j]]=1;
	}
		//cout<<c<<endl;
		if(c==t) printf("WAKE UP IN, %d, YEARS\n",y);
		else printf("THIS BRAIN NEVER WAKES UP\n");
	}
}
