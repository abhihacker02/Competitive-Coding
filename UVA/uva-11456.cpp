#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef vector<int>vi;
typedef long long int lli;
vi v,d;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int li=0,ld=0;
		v.clear();d.clear();
		int n;
		scanf("%d",&n);
		int a[n];
		for(int i=0;i<n;i++){
		//	for(int i=0;i<v.size();i++) cout<<v[i]<<" ";cout<<endl;
			scanf("%d",&a[i]);
			if(v.empty()) {
			v.pb(a[i]);li++;}
			else{
				if(a[i]>v[v.size()-1]) {
				v.pb(a[i]);li++;}
				else{
					if(a[i]<v[0]) {
						v.insert(v.begin(),a[i]);li++;
					}
					else{
					int in=lower_bound(v.begin(),v.end(),a[i])-v.begin();
				//	cout<<in<<endl;
					v[in+1]=a[i];}
				}
			}
				if(d.empty()) {
				d.pb(a[i]);ld++;}
			else{
				if(a[i]<d[d.size()-1]) {
				d.pb(a[i]);ld++;}
				else{
					if(a[i]>d[0]) {
						d.insert(d.begin(),a[i]);ld++;
					}
					else{
					int in=upper_bound(d.begin(),d.end(),a[i],greater<int>())-d.begin();
				//	cout<<in<<endl;
					d[in]=a[i];}
				}
			}
		}
		//int k=v.size();
		//cout<<k<<" "<<n-k+1<<endl;
		int ans=max(li,ld);
		printf("%d\n",ans);
	}
}
