#include<bits/stdc++.h>
using namespace std;
int a[505][505];
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	while(n!=0&&m!=0){
		for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d",&a[i][j]);
		int q;
		scanf("%d",&q);
		while(q--){
			int l,u;
			scanf("%d %d",&l,&u);
			int mn_ind,mx=0;
			for(int i=0;i<n;i++){
				int *it=lower_bound(a[i],a[i]+m,l);
				mn_ind=it-a[i];
				for(int k=mx;k<n;k++){
					if(i+k>=n||mn_ind+k>=m||a[i+k][mn_ind+k]>u) {
					break;}
					//if(k+1>mx) mx=k+1;
					else mx++;
				}
			}
			printf("%d\n",mx);
		}
		printf("-\n");
		scanf("%d %d",&n,&m);
	}
}
