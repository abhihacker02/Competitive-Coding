#include<iostream>
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
		int n,pos=0;
		cin>>n;
		lli a[n],sump=0,sumn=0;
		for(int j=0;j<n;j++)
		{
			cin>>a[j];
			if(a[j]>=0)
			{
				sump+=a[j];
				pos++;
			}
			else
			sumn+=a[j];
		}
		sort(a,a+n);
		int p=-1;
		for(int j=0;j<n;j++)
		if(a[j]<0) p=j;
		for(int j=p;j>=0;j--)
		{
			if(a[j]<0)
			{
				if(((sump+a[j])*(pos+1)+(sumn-a[j]))>((sump*pos)+sumn))
				{
					pos++;
					sump+=a[j];
					sumn-=a[j];
				}
			}
		}
		res[i]=sumn+(sump*pos);
	}
	for(int i=0;i<t;i++)
	cout<<res[i]<<"\n";
}
