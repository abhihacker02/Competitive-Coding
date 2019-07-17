#include<bits/stdc++.h>
typedef long long int lli;
//typedef vector<int> vi;
using namespace std;
int segtree[200005];
int a[100005];
#define MAX 1000000009
void build(int l,int h,int pos){
	if(l==h) { segtree[pos]=a[l]; return;}
	int mid=(l+h)/2;
	build(a,l,mid,(2*pos)+1);
	build(a,mid+1,h,(2*pos)+2);
	segtree[pos]=min(segtree[(2*pos)+1],segtree[(2*pos)+2]);
}
void update(int ind,int pos,int l,int h,val){
	if(l==h){
		a[ind]=val;
		segtree[ind]=val;return;
	}
	int mid=(l+h)/2;
	if(ind>mid){
		update(ind,2*pos+1,mid+1,h,val);
	}
	else if(ind<=mid){
		update(ind,2*pos,l,mid,val);
	}
	segtree[pos]=min(segtree[2*pos],segtree[2*pos+1]);	
}
int rmq(int lrange,int rrange,int l,int h,int pos){
	if(l>=lrange&&h<=rrange) return segtree[pos];
	if(lrange>h||rrange<l) return 0;
	int mid=(l+h)/2;
	int m1=rmq(lrange,rrange,l,mid,(2*pos)+1);
	int m2=rmq(lrange,rrange,mid+1,h,(2*pos)+2);
	return min(m1,m2);
}
int main(){
	int n,k;
	cin>>n>>k;
	//int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	build(0,n-1,0);
	lli ans[n];ans[0]=a[0];
//	for(int i=0;i<2*n-1;i++) cout<<segtree[i]<<" ";cout<<"\n";
	for(int i=1;i<n;i++){
		if(i<=k){
		ans[i]=(a[i]*a[0])%mod;
		update(i,0,0,n-1,ans[i])}
	}
}
