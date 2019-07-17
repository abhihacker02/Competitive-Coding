#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
	int t;
	cin>>t;
	while(t--){
		lli a,b;
		cin>>a>>b;
		int ca=0,cb=0,oa=0,ob=0;
		lli ta=a,tb=b-1;
		while(ta>0){
			ca++;
			if(ta%2==1) oa++;
			ta=ta/2;
		}
		while(tb>0){
			cb++;
			if(tb%2==1) ob++;
			tb=tb/2;
		}
		if(a==b){
			cout<<0<<endl;
		}
		else if(a==b-1){
			cout<<1<<endl;
		}
		else if(b<=1||a<0){
			cout<<-1<<endl;
		}
		else if(oa==ob){
			cout<<1<<endl;
		}
		else if(oa<ob){
			cout<<ob-oa+1<<endl;
		}
		else {
			cout<<2<<endl;
		}
	}
}
