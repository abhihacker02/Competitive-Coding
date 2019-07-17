#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,t=1;
	cin>>n;
	while(n!=-1){
		string s,g;
		cin>>s;
		cin>>g;
		int a[26],ch=0,d[26];
		for(int i=0;i<26;i++) {
		a[i]=0;d[i]=0;}
		for(int i=0;i<s.length();i++){
			if(a[s[i]-97]==0) ch++;
			a[s[i]-97]=1;
		}
		int wr=0,rt=0,p=0;
		for(int i=0;i<g.length();i++){
			if(rt==ch) {
			cout<<"Round "<<t<<endl;cout<<"You win.\n";p=1;break;}
			else if(wr>=7){
				cout<<"Round "<<t<<endl;cout<<"You lose.\n";p=1;break;
			}
			int x=g[i]-97;
			if(a[x]==0&&d[x]==0) wr++;
			else if(a[x]==0) d[x]=1;
			else rt++;
			a[x]=0;
		}
		if(rt==ch&&p==0) {
			cout<<"Round "<<t<<endl;cout<<"You win.\n";p=1;}
			else if(wr>=7&&p==0){
				cout<<"Round "<<t<<endl;cout<<"You lose.\n";p=1;
			}
		 else if(p==0) {
		 cout<<"Round "<<t<<endl;cout<<"You chickened out.\n";}
		cin>>n;t++;
	}
}
