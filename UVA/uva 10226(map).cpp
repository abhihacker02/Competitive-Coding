#include<bits/stdc++.h>
typedef long long int lli;
#define pb push_back
#define mp make_pair
using namespace std;
int main(){
	int t;
	cin>>t;string s;
	while(t--){
		map<string,int>m;
		getline(cin,s);
	//	getline(cin,s);
		int c=0;
		while(true){
			getline(cin,s);
			if(s.length()==0) break;
			map<string,int>::iterator it=m.find(s);
			if(it==m.end()){
				m[s]=1;
			}
			else m[s]++;
			c++;
		}
		double ans=100.00/c;
		for(map<string,int>::iterator it=m.begin();it!=m.end();it++){
			cout<<it->first<<" "<<setprecision(4)<<fixed<<it->second*ans<<endl;
		}
		if(t>0) cout<<endl;
	}
}
