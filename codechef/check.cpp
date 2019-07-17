#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<pair<int,int> >v;
	v.push_back(make_pair(1,2));
	v.push_back(make_pair(3,4));
	swap(v[0],v[1]);
	cout<<v[0].first<<" "<<v[1].first<<endl;
}
