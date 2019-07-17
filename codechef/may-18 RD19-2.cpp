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
		int n,g,x,ans=0;
		cin>>n;int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(a[i]==1) ans=1;
		}
		if(ans==1){
			cout<<0<<endl;
		}
		else{
			ans=0;
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					if(a[i]==a[j]||a[j]==0||a[i]==0) continue;
					if(a[j]%a[i]==0) {
					ans++;a[j]=0;}
				}
			}
			int g=a[0];
			for(int i=1;i<n;i++) if(a[i]!=0) g=gcd(g,a[i]);
			if(g!=1) cout<<-1<<endl;
			else cout<<ans<<endl;
		}
	}
}
