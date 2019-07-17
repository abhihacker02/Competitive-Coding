/*
store in the map the latest index of the element encountered and then search for the present element in the map .if found then find the length of the subarray
by subtracting from current index the last index where a match was found.if the element is not found in map then simply keep adding it to the map. 
*/
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		map<int,int>::iterator it;
		for(int i=0;i<n;i++) cin>>a[i];
		map<int,int>m;int pos=0,c=0,mx=0,prev=-1;
		for(int i=0;i<n;i++){
			it=m.find(a[i]);
			if(it==m.end()||it->second<prev)
			{
				c++;
				m[a[i]]=i;
			}
			else{
				mx=max(mx,i-prev-1);
				//int w=prev;
				//prev=m[prev];
				prev=it->second;
				//m.erase(w);
				m[a[i]]=i;
			}
		}
		mx=max(mx,n-1-prev);
		cout<<mx<<endl;
	}
}
