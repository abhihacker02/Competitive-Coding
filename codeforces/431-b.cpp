#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++)
		cin>>a[i];
	float s1=a[2]-a[1];float f=0,s2=0;
	for(int i=2;i<=n-1;i++)
	{
		for(int j=i+1;j<=n;j++){
		float diff=(float(a[i]-a[j])/(i-j));
		if(diff!=s1 && f==0)
		{
			f=1;s2=diff;
		}
		else if(f==1 && diff==s2)
		continue;
		else if(diff==s1)
		continue;
		else{
			cout<<"Nop";return 0;
		}}
	}if(f!=0)
	cout<<"Yes";
	else
	cout<<"No";
}
