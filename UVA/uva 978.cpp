#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int b,sg,sb,x;
		cin>>b>>sg>>sb;
		multiset<int>mg;
		multiset<int>mb;
		stack<int>s1,s2;
		multiset<int>::reverse_iterator it1;
		multiset<int>::reverse_iterator it2;
		multiset<int>::reverse_iterator rt;
		for(int i=0;i<sg;i++) {
			cin>>x;mg.insert(x);
		}
		for(int i=0;i<sb;i++){
			cin>>x;mb.insert(x);
		}
		while(mg.size()!=0&&mb.size()!=0){
			int szg=mg.size();
			int szb=mb.size();
			int sz=min(szb,szg);
			sz=min(sz,b);
			for(int i=0;i<sz;i++){
				it1=mg.rbegin();
				it2=mb.rbegin();
				if(*it1==*it2){
					mg.erase(mg.find(*it1));mb.erase(mb.find(*it2));
				}
				else if(*it1>*it2){
					s1.push(*it1-*it2);
					mg.erase(mg.find(*it1));mb.erase(mb.find(*it2));
				}
				else{
					s2.push(*it2-*it1);
					mg.erase(mg.find(*it1));mb.erase(mb.find(*it2));
				}
			}
			while(!s1.empty()){
				mg.insert(s1.top());s1.pop();
			}
			while(!s2.empty()){
				mb.insert(s2.top());s2.pop();
			}
		}
		if(mb.size()==0&&mg.size()==0){
			cout<<"green and blue died\n";if(t>0) cout<<endl;
		}
		else if(mb.size()!=0){
			cout<<"blue wins\n";
			for(rt=mb.rbegin();rt!=mb.rend();rt++) cout<<*rt<<endl;
			if(t>0) cout<<endl;
		}
		else{
			cout<<"green wins\n";
			for(rt=mg.rbegin();rt!=mg.rend();rt++) cout<<*rt<<endl;
			if(t>0) cout<<endl;
		}
	}
}
