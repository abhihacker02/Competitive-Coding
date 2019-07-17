#include<bits/stdc++.h>
using namespace std;
int  main(){
	vector<int>v;
	//vector<int>c;
	v.push_back(5);
	v.push_back(6);
	vector<int>&c=v;
	c[0]=2;
	v.clear();
	cout<<v.size()<<endl;
	v.push_back(4);
	cout<<v[0]<<endl;
	cout<<c[0]<<endl;
}
