#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	while(n!=0){
		int mx=-1;
		map<string,int>m;
		string s[5];
		while(n--){
			cin>>s[0]>>s[1]>>s[2]>>s[3]>>s[4];
			sort(s,s+5);
			string st;
			st=s[0]+s[1]+s[2]+s[3]+s[4];
			if(m.find(st)!=m.end()){
				m[st]++;
				mx=max(m[st],mx);
			}
			else {
				m[st]=1;
				mx=max(mx,1);
			}
			}
			int c=0;
			for(map<string,int>::iterator it=m.begin();it!=m.end();it++){
				if(it->second==mx) c+=it->second;
		}
		cout<<c<<endl;
		cin>>n;
	}
}
