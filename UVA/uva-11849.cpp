#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,t;
	while(true){
		cin>>n>>m;
		if(n==0&&m==0) break;
		t=n+m;
		int a[t],c=0;
		while(t--) cin>>a[t];
		sort(a,a+n+m);
		for(int i=1;i<n+m;i++){
			if(a[i]==a[i-1]) c++;
		}
		cout<<c<<endl;
	}
}
