#include<bits/stdc++.h>
#include<string.h>
using namespace std;
#define mkp make_pair
#define pb push_back
int ls=0;
vector<pair<string,int> >v[27];
template<typename T>
bool compare(const T &a,const T &b){
    if (a.first<=b.first) return true;
}
template<typename T>
bool compare2(const T &a,const T &b){
//	cout<<b.first<<endl;
//	if(a.first>=b.first&&b.second>=a.second) cout<<"m"<<a.first<<" "<<b.first<<endl;
    return !(b.second>=a.second&&a.first>=b.first);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	string a[n+1],s;
	for(int j=1;j<=n;j++){
		cin>>s;
		if(j==1) a[j]=s;
		else{
			a[j]=min(s,a[j-1]);
		}
		v[s[0]-'a'].pb(mkp(s,j));
	}
	int q;
	cin>>q;
	int k=0;
		vector<int>::iterator it;
		vector<pair<string,int> >::iterator its;
		for(int i=0;i<27;i++){
			sort(v[i].begin(),v[i].end());
		}
		for(int i=0;i<5;i++){
			for(int j=0;j<v[i].size();j++) cout<<v[i][j].first<<" "; cout<<endl;
		}
	while(q--){
		k++;
		int id;string s;
		cin>>id>>s;
		if(v[s[0]-'a'].size()==0){
			cout<<"h";
			cout<<a[id]<<"k"<<endl;
			continue;
		}
		else{
			int done=0;
		//	cout<<"b";
		int l=s.length();
		for(int i=0;i<l;i++){
			string st=s.substr(0,l-i);
			its=lower_bound(v[s[0]-'a'].begin(),v[s[0]-'a'].end());
			if(its!=v[s[0]-'a'].end()){
				int in=its-v[s[0]-'a'].begin();
				//cout<<v[s[0]-'a'][in].first<<" "<<v[s[0]-'a'][in].second<<" "<<st<<" "<<"id="<<id<<endl;
				cout<<its->first<<" "<<its->second<<endl;
				if(v[s[0]-'a'][in].second<=id){
					cout<<v[s[0]-'a'][in].first<<"ip"<<endl;
					done=1;
					break;
				}
			}
		}
	if(done==0)
				cout<<a[id]<<"k"<<endl;}
	}
} 
