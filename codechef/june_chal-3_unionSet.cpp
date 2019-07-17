#include<iostream>
typedef long long int lli;
int main()
{
	int t;
	cin>>t;
	int n,k;
	for(int i=0;i<t;i++)
	{
		cin>>n>>k,l;
		int a[n][k];
		for(int j=0;j<n;j++)
		{
			cin>>l;
			for(int h=0;h<l;h++)
			{
				int s;
				cin>>s;
				a[j][s-1]=s;
			}
		}
		
	}
}
