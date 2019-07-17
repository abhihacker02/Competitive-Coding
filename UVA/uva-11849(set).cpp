#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,t;
	while(true){
		cin>>n>>m;
		if(n==0&&m==0) break;
		set<int>s;
		int x,c=0;
		while(n--) {
		cin>>x;
		s.insert(x);}
		while(m--){
			cin>>x;
			if(s.find(x)!=s.end()) c++;
		}
		cout<<c<<endl;
	}
}
