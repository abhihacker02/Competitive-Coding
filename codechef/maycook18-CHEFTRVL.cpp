#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long int lli;
int vis[100005];
int dis[100005];
int bit[100005];
int a[100005];
int cal[100005];
vector<int>gr[100005];
void dfs(int v,int p){
	vis[v]=1;
	if(v!=p){
		dis[v]=dis[p]^1;
	}
	else return;
	for(int i=0;i<gr[v].size();i++){
		int x=gr[v][i];
		if(!vis[x]) {
		//cout<<x<<" "<<v<<endl;
		dfs(x,v);}
	}
}
void calc(int r){
	int p=31;
	int x=a[r];
	int s=a[1];
	while(p--){
		if(x%2!=s%2) bit[r]++;
		x=x/2;s=s/2;
	}
}
int main(){
	int t;
	dis[0]=0;
	cin>>t;
	while(t--){
		memset(vis,0,sizeof vis);
		memset(cal,0,sizeof cal);
		memset(bit,0,sizeof bit);
		memset(dis,0,sizeof dis);
		memset(a,0,sizeof a);
		int n;
		cin>>n;
		dis[0]=0;
		for(int i=0;i<100005;i++) gr[i].clear();
		for(int i=1;i<=n-1;i++){
			int x,y;
			cin>>x>>y;
			gr[x].pb(y);
			gr[y].pb(x);
	}
		dfs(1,0);
		cin>>a[1];
		lli z=0,on=1;
		cal[1]=1;bit[1]=0;
		for(int i=2;i<=n;i++) {
			cin>>a[i];
			calc(i);
			bit[i]=bit[i]%2;
			cal[i]=dis[i]^bit[i];
			if(cal[i]==1) 
				on++;
			else z++;
		}
	//	for(int i=1;i<=n;i++) cout<<dis[i]<<" ";cout<<endl;
	//	for(int i=1;i<=n;i++) cout<<bit[i]<<" ";cout<<endl; 
	//	for(int i=1;i<=n;i++) cout<<cal[i]<<" ";cout<<endl; 
		lli ans=1;
		ans=ans*on;ans=ans*z;
		cout<<ans<<endl;
	}
}
