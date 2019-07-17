#include<iostream>
using namespace std;
typedef long long int lli;
int main()
{
	int t;
	lli n,b,c,s;
	lli res[t];
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n>>b;
		lli half=n/2;
		lli rem=n-half;
		if(b>=rem)
		{
			s=n-b;
			if(s<0)
			res[i]=0;
			else
			res[i]=s;
		}
		else
		{
			lli times=rem/b;
			lli rem2=rem-(times*b);
			s=times*(half+rem2);
			res[i]=s;
		}
	}
	for(int i=0;i<t;i++)
	cout<<res[i]<<endl;
}
