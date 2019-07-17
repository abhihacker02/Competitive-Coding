#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int a[n],d[n];
		for(int i=0;i<n;i++) {
		scanf("%d",&a[i]);d[i]=0;}
		for(int i=0;i<n-1;i++) {
			int diff=abs(a[i]-a[i+1]);
			if(d[diff]!=0) break;
			else d[diff]=1;
		}
		int np=0;
		for(int i=1;i<n;i++) {
			if(d[i]!=1) np=1;
		}
		if(np==0) printf("Jolly\n");
		else printf("Not jolly\n");
	}
}
