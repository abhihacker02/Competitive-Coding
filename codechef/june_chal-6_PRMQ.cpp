#include<iostream>
#include<algorithm>
#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;
void SieveOfEratosthenes(int n,bool prime[])
{
    memset(prime, true, sizeof(prime));
 
    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
}
int main()
{
	int n,q,l,r,x,y;
	cin>>n;
	int a[n+1];
	bool prime[1000000+1];
	SieveOfEratosthenes(1000000,prime);
	for(int i=0;i<n;i++)
	cin>>a[i+1];
	cin>>q;
	lli res[q];
	for(int z=0;z<q;z++)
	{
		cin>>l>>r>>x>>y;
		lli sm=0;
	for(int j=x;j<=y;j++)
	{
		if(prime[j])
		{
			for(int k=l;k<=r;k++)
			{
				int nm=a[k];
				int ex=0;
				while(nm%j==0)
				{
					ex++;
					nm=nm/j;
				}
				sm=sm+ex;
			}
		}
	}
	res[z]=sm;
	}
	for(int i=0;i<q;i++)
	cout<<res[i]<<"\n";
}
