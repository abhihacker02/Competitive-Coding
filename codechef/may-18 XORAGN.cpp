#include<bits/stdc++.h>
using namespace std;
int a[100005];
typedef long long int lli;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;cin>>n;lli ans=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			ans=ans^(2*a[i]);
		}
		cout<<ans<<endl;
	}
}
