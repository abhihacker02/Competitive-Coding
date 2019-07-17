#include<bits/stdc++.h>
using namespace std;
vector<string>st;
#define pb push_back
int main(){
	int t;
	scanf("%d",&t);
	for(int w=1;w<=t;w++){
		st.clear();
		int n,l,np=0,pos1,pos2,posi;
		scanf("%d %d",&n,&l);
		string s[n];
		for(int i=0;i<n;i++){
			cin>>s[i];
		}
		for(int i=0;i<l;i++){
			for(int j=0;j<n;j++){
				for(int k=0;k<n;k++){
					if(s[j][i]!=s[k][i]){
						string str=s[j].substr(0,i);
						str.append(s[k].substr(i,i+1));
						str.append(s[j].substr(i+1));
						st.pb(str);
					}
				}
			}
		}
		sort(s,s+n);
		int d=0;
		for(int i=0;i<st.size();i++){
			np=0;
			if(binary_search(s,s+n,st[i])) np=1;
			if(np==0) {
			cout<<"Case #"<<w<<": "<<st[i]<<endl;d=1;break;}
		}
		if(d==1) continue;
		else cout<<"Case #"<<w<<": -\n";
	}
}
