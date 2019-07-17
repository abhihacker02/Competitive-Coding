#include<bits/stdc++.h>
using namespace std;
typedef vector<int>v;
typedef long long int lli;
#define pb push_back
v gr[300005];
v ans;
lli n,x,y;
int vis[300005],f=0;
lli dfsn(int vt,int find){
	if(vt==find) {
	f=1;return 0;}
	if(vis[vt]){
	 return 0;}
	vis[vt]=1;
	lli ans=1;
	for(int i=0;i<gr[vt].size();i++){
		ans+=dfsn(gr[vt][i],find);
	}
	return ans;
}
int main(){
	memset(vis,0,sizeof vis);
	cin>>n>>x>>y;
	int p,q;
	if(n==1) {
		cout<<0<<endl;return 0;
	}
	for(int i=0;i<n-1;i++) {
		cin>>p>>q;
		gr[p].pb(q);
		gr[q].pb(p);
	}
	lli r1=1,r;
	if(gr[x].size()==1) r1=1;
	else{
		for(int i=0;i<gr[x].size();i++){
		//memset(vis,0,sizeof vis);
		f=0;
		vis[x]=1;
		r=dfsn(gr[x][i],y);
		if(f==0)
		r1+=r;
	}
}
	memset(vis,0,sizeof vis);
	lli r2=1;
	if(gr[y].size()==1) r2=1;
	else{
		for(int i=0;i<gr[y].size();i++){
			//memset(vis,0,sizeof vis);
		f=0;vis[y]=1;
		r=dfsn(gr[y][i],x);
		if(f==0)
		r2+=r;
	}
}
	lli an=n*(n-1);
//	cout<<r1<<r2<<endl;
	an=an-(r1*r2);
	cout<<an<<endl;
}
