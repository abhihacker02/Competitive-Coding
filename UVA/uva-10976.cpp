#include<bits/stdc++.h>
using namespace std;
#define mkp make_pair
map<int,int>mp;
int n;
int main(){
	map<int,int>::reverse_iterator rit;
	while(scanf("%d",&n)!=EOF){
		mp.clear();
		for(int i=n+1;i<=2*n;i++){
			if((i*n)%(i-n)==0) mp.insert(mkp((i*n)/(i-n),i));
		}
		printf("%d\n",mp.size());
		for(rit=mp.rbegin();rit!=mp.rend();rit++){
			printf("1/%d = 1/%d + 1/%d\n",n,rit->first,rit->second);
		}
	}
}
