#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n+1];
	for(int i=1;i<n+1;i++) cin>>a[i];
	int st=1;
	int c=1,mx=1,mx2,pos2;
	for(int i=2;i<=n;i++)
	{
		if(a[i]>=a[i-1]) c++;
		else{
			int c2=1,pos=i;
			for(int j=i+1;j<=n;j++){
				if(a[j]<=a[j-1]) c2++;
				else {
					pos=j-1;break;
				}
			}
				for(int k=st;k<i;k++){
					if(a[i]>a[k]) continue;
					else{
						mx2=pos-k+1;
						pos2=k;
						break;
						//mx=max(mx,s);
					}
				}
				
			//	for(int k=pos2;k>=st;k--){
			//		if(a[k]<=a[pos2]) mx2++;
			//	}
			for(int k=pos+1;k<=n;k++)
			{
				if(a[k]>=a[i-1]) mx2++;else break;
			}
			mx=max(mx,mx2);
			st=i;c=1;
		}
	}
	mx=max(mx,c);
	cout<<mx;
}
