#include<bits/stdc++.h>
using namespace std;
int n,ans,mn;
int a[10][10];
void calc(int mc,int mr){
	if(mr==(1<<n)-1&&mc==(1<<n)-1){
		if(ans<mn){
			mn=ans;
		}ans=0;return;
	}
		for(int i=0;i<n;i++){
			int posi=i,posj,mnc=99999999;
			if(!(mc&(1<<posi))){
				for(int j=0;j<n;j++){
					posj=j;
					if((!(mr&(1<<posj)))&&a[posj][posi]<mnc)mnc=posj;
				}
				ans+=a[mnc][posi];
				calc(mc|(1<<posi),mr|(1<<mnc));
			}
		}
	}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		scanf("%d",&a[i][j]);
		ans=0;mn=99999999;
		calc(0,0);
		printf("%d\n",mn);
	}
}
