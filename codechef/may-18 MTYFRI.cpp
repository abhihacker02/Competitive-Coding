#include<bits/stdc++.h>
using namespace std;
int a[10005],e[5005],o[5005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k,sumo=0,sume=0;
		cin>>n>>k;
		for(int i=0;i<n;i++) {
		cin>>a[i];
		if(i%2==0) {
		sume+=a[i];e[i/2]=a[i];}else{
		 sumo+=a[i];o[(i-1)/2]=a[i];}}
		 int so=n/2,se=n-so;
		 sort(e,e+se);sort(o,o+so);
		 int diff=sume-sumo;
		 if(sumo>sume){
		 	cout<<"YES\n";
		 }
		 else{
		 	int mx=0;
		 	int mn=min(so,k),ie=se-1,io=0;
		 	for(int i=0;i<mn;i++){
		 		mx+=e[ie]-o[i];ie--;
			 }
			 if((2*mx)>diff){
			 	cout<<"YES\n";
			 }
			 else cout<<"NO\n";
		 }
	}
}
