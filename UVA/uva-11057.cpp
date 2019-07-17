#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define pb push_back
vector<int>v;
int main(){
	int n;
	string s;
	while(cin>>n){
	int x;
	for(int i=0;i<n;i++) {
	cin>>x;v.pb(x);}
	int amt;
	cin>>amt;
	int n1,n2,diff=100000005;
	vector<int>::iterator up;
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++){
		up=upper_bound(v.begin(),v.end(),amt-v[i]);
			if(*(up-1)+v[i]==amt&&abs(*(up-1)-v[i])<diff&&up-v.begin()-1!=i){
				//cout<<*(up-1);
				n1=v[i];n2=*(up-1);diff=abs(*(up-1)-v[i]);
		}
	}
	cout<<"Peter should buy books whose prices are "<<n1<<" and "<<n2<<".\n\n";
	//getline(cin,s);
	v.clear();//cin>>n;
}
}
