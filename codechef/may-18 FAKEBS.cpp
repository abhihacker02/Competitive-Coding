#include<bits/stdc++.h>
using namespace std;
map<int,int>mp;
#define pb push_back
#define mkp make_pair
int c[100005],a[100005];
int main(){
	map<int,int>::iterator it;
	int t,num;
	cin>>t;
	while(t--){
		mp.clear();
		int n,q;
		cin>>n>>q;
		for(int i=0;i<n;i++) {
			cin>>c[i];mp.insert(mkp(c[i],i));a[i]=c[i];}
			sort(a,a+n);
		while(q--){
			cin>>num;
			it=mp.lower_bound(num);
			int ind=it->second;
			//int id=distance(mp.begin(),mp.find(num));
			int id=lower_bound(a,a+n,num)-a;
			int l=id,r=n-id-1,ans=0,sw=0,np=0,m,left=0,right=n-1,sm=0,lr=0;
		//	cout<<l<<" "<<r<<endl;
			while(left<=right){
				//cout<<l<<endl;
				m=(left+right)/2; 
				if(c[m]==num) {
					ans=1;break;
				}
				if(c[m]>num){
					if(ind>m){
						left=m+1;
						if(l<1){
							np=1;break;
						}
						if(lr!=0){
							lr--;l--;
						}
						else if(lr==0){
							l--;sw++;sm++;
						}
					}
					else{
						if(r<1) {
							np=1;break;
						}
						right=m-1;r--;
					}
				}
				else{
					if(ind<m){
						right=m-1;
						if(r<1){
							np=1;break;
						}
						if(sm!=0){
							sm--;r--;
						}
						else if(sm==0){
							r--;sw++;lr++;
						}
					}
					else{
						if(l<1){
							np=1;break;
						}
						left=m+1;l--;
					}
				}
			}
			if(np==1) cout<<-1<<endl;
			else cout<<sw<<endl;
		}
	}
}  
