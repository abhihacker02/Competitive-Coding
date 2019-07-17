#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef struct node{
	lli mx;lli s[60];
}node;
node tree[400025];
lli a[100005];
void build(int ind,int l,int r){
	if(l==r){
		tree[ind].mx=0;
		for(int i=1;i<60;i++) tree[ind].s[i]=0;
		tree[ind].s[0]=a[l];
		return;
	}
	int m=(l+r)/2;
	build(2*ind,l,m);
	build(2*ind+1,m+1,r);
	tree[ind].mx=max(tree[2*ind].mx,tree[2*ind+1].mx);
	int lft=0,rht=0;
	for(int i=0;i<60;i++){
		if(tree[2*ind].s[lft]>tree[2*ind+1].s[rht]){  
			tree[ind].s[i]=tree[2*ind].s[lft];lft++;
		}
		else{
			tree[ind].s[i]=tree[2*ind+1].s[rht];rht++;	
		}
	}
	for(int i=0;i<58;i++){
		if(tree[ind].s[i+2]==0)break;
		if(tree[ind].s[i]<tree[ind].s[i+1]+tree[ind].s[i+2]){
			tree[ind].mx=max(tree[ind].mx,tree[ind].s[i+1]+tree[ind].s[i+2]+tree[ind].s[i]);
		}
	}
	return;
}
void update (int nd,long long int indx,long long int val,int l,int r){
	if(l==indx&&r==indx){
		tree[nd].s[0]=val;
		return ;
	}
	int mid=(l+r)/2;
	if(indx>mid){
		update(2*nd+1,indx,val,mid+1,r);
	}
	else update(2*nd,indx,val,l,mid);
	int lft=0,rht=0;
	for(int i=0;i<60;i++){
		if(tree[2*nd].s[lft]>tree[2*nd+1].s[rht]){
			tree[nd].s[i]=tree[2*nd].s[lft];lft++;
		}
		else{
			tree[nd].s[i]=tree[2*nd+1].s[rht];rht++;	
		}
	}
	tree[nd].mx=max(tree[2*nd].mx,tree[2*nd+1].mx);
	for(int i=0;i<58;i++){
		if(tree[nd].s[i+2]==0)break;
		if(tree[nd].s[i]<tree[nd].s[i+1]+tree[nd].s[i+2]){
			tree[nd].mx=max(tree[nd].mx,tree[nd].s[i+1]+tree[nd].s[i+2]+tree[nd].s[i]);
		}
	}
	return ;
}
node* query(int nd,long long int l,long long int r,int st,int en){
	node* temp=(node*)malloc(sizeof(node));
	temp->mx=0;
		for(int i=1;i<60;i++) temp->s[i]=0;
		temp->s[0]=0;
	if(st>r||en<l){
		return temp;
	}
	if(st>=l&&en<=r){
		return (tree+nd);
	}
	int mid=(st+en)/2;
	node* lft=query(2*nd,l,r,st,mid);
	node* rht=query(2*nd+1,l,r,mid+1,en);
	temp->mx=max(lft->mx,rht->mx);
	int j=0,k=0;
	for(int i=0;i<60;i++){
		if(lft->s[j]>rht->s[k]){
			temp->s[i]=lft->s[j];j++;
		}
		else{
			temp->s[i]=rht->s[k];k++;	
		}
	}
	for(int i=0;i<58;i++){
		if(temp->s[i+2]==0)break;
		if(temp->s[i]<temp->s[i+1]+temp->s[i+2]){
			temp->mx=max(temp->mx,temp->s[i+1]+temp->s[i+2]+temp->s[i]);
		}
	}
	return temp;
}
int main(){
	 ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n,q;cin>>n>>q;
	for(int i=0;i<n;i++)cin>>a[i];
	build(1,0,n-1);
	long long int x,y, z;
	while(q--){
		cin>>x>>y>>z;
		if(x==1){
			a[y-1]=z;
			update(1,y-1,z,0,n-1);
		}
		else{
			cout<<(query(1,y-1,z-1,0,n-1)->mx)<<"\n";
		}
	}
	return 0;
} 
