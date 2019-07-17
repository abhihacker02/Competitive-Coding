#include<bits/stdc++.h>
using namespace std;
int main(){
	long long int n,k,temp;
	cin>>n>>k;
	long long int d=1;
	temp=n;
	while(n>0){
		d*=2;
		n=n/2;
	}
	if(k>1)
	cout<<d-1;
	else cout<<temp;
}

