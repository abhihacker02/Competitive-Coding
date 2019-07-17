#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
typedef long long int lli;
using namespace std;
int main()
{
	int t;
	cin>>t;
	lli res[t];
	for(int i=0;i<t;i++)
	{
		int n,d;
		lli sum=0;
		cin>>n>>d;
		int a[n][3];
		for(int j=0;j<n;j++)
			cin>>a[j][0]>>a[j][1]>>a[j][2];
		for(int j=1;j<=d;j++)
		{
			int max=0,pos=-1;
			for(int k=0;k<n;k++)
			{
				if((a[k][2]>max)&&(a[k][1]>0)&&a[k][0]<=j)
				{max=a[k][2];pos=k;}
			}
			if(pos!=-1)
			a[pos][1]--;
			sum+=max;
		}
		sum=0;
		for(int j=0;j<n;j++)
		{
			sum+=(a[j][1]*a[j][2]);
		}
		res[i]=sum;
	}
	for(int i=0;i<t;i++)
	cout<<res[i]<<endl;
}
