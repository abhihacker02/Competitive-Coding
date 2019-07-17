#include<bits/stdc++.h>
using namespace std;
#define pb push_back
typedef vector<int>vi;
vi v;
int tot,n,a[15];
void backtrack(int sum,int i){
	if(sum==tot){
		int j;
		for(j=0;j<v.size()-1;j++) printf("%d+",v[j]);printf("%d\n",v[j]);
		return;
	}
	if(i==n) return;
	if(sum+a[i]<=tot) {
		v.pb(a[i]);
		backtrack(sum+a[i],i+1);
		v.pop_back();
	}
	backtrack(sum,i+1);
}
int main(){
	scanf("%d %d",&tot,&n);
	while(n!=0){
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		backtrack(0,0);
		scanf("%d %d",&tot,&n);
	}
}
