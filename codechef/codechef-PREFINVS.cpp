#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int l=s.length(),c=0,st=0;l--;
	while(l>0){
		//cout<<0;
		if(st==0&&s[l]=='0') {//cout<<1;
		l--;continue;}
		else if(st==0&&s[l]=='1'){
			st=1;c++;//cout<<2;
		}
		if(st==1){
			if(s[l]==s[l-1]) l--; else {
			c++;l--;}
		}
	}
	cout<<c;
}
