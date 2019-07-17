#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
	lli n,m;
	scanf("%lld %lld",&n,&m);
	
	while(n!=0&&m!=0){
		lli h[n],k[m];
		for(int i=0;i<n;i++) scanf("%lld",&h[i]);
		for(int i=0;i<m;i++) scanf("%lld",&k[i]);
		sort(h,h+n);sort(k,k+m);lli id=0,i=0;lli c=0;
		while(id!=m&&i!=n){
			if(k[id]>=h[i]){
				c+=k[id];id++;i++;
			}
			else{
			 id++;}
		}
		if(i==n&&id<=m) printf("%lld\n",c);
		else printf("Loowater is doomed!\n");
		scanf("%lld %lld",&n,&m);
	}
}
