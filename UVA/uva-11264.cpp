#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		lli a[n+1];a[n]=1000000000000000;
		scanf("%lld",&a[0]);lli sum=0;sum=a[0];int c=1;
		for(int i=1;i<n;i++){
			scanf("%lld",&a[i]);
		}
		for(int i=1;i<n;i++){
			if(sum+a[i]<a[i+1]){
			c++;
			sum+=a[i];}
		}
		printf("%d\n",c);
	}
}
