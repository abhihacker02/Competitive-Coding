#include<bits/stdc++.h>
using namespace std;
int gcd (int a, int b) {
  int r, i;
  while(b!=0){
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,x,ans=0,g;
		cin>>n;int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		for(int i=0;i<n;i++){
			if(a[i]==1) continue;
			for(int k=i+1;k<n;k++){
				if(a[i]==a[k]) continue;
			if(a[i]==0||a[k]==0) continue;
			int g=a[k]%a[i];
			if(g==0){
				a[k]=0;ans++;
			}
		}}g=a[0];
		for(int i=1;i<n;i++){
			if(a[i]!=0) g=gcd(g,a[i]);
		}
		if(g!=1) cout<<-1<<endl;
		else cout<<ans<<endl;
	}
}
