#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli s;
int a[100005];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		s=0;
		sort(a,a+n);int c=1;
		for(int i=0;i<n-1;i++){
			if(a[i]==a[i+1]) c++;
			else{
				s+=c-1;
				c=1;
			}
		}
		if(c>1) s+=c-1;
		printf("%lld\n",s);
	}
}
