#include<bits/stdc++.h>
using namespace std;
int a[100005];int d[100005];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++) {
		scanf("%d",&a[i]);d[i]=0;}
		for(int i=0;i<n;i++){
			int s=a[i];
			for(int j=i+1;j<n;j++){
				if(s>=0) {
				d[j]+=1;s-=a[j];}
				else break;
			}s=a[i];
			for(int j=i-1;j>=0;j--){
				if(s>=0){
					d[j]++;s-=a[j];
				}
				else break;
			}
		}
		for(int i=0;i<n;i++) printf("%d ",d[i]);printf("\n");
	}
}
