#include<iostream>
#include<string>
typedef long long int lli;
using namespace std;
int main()
{
	string n;
	int t;cin>>t;
	for(int j=0;j<t;j++)
	{cin>>n;int a[10]={0};
		for(int i=0;i<n.length();i++)
		a[int(n[i])-48]++;
		for(int i=65;i<=90;i++)
		{
			int k=i%10;
			if(a[k]==0)
			{
				continue;
			}
			else
			{
				a[k]--;
				int p=i/10;
				if(a[p]==0)
				{
					a[k]++;
					continue;
				}
				else
				cout<<char(i);
				a[k]++;
			}
		}
		cout<<endl;
	}
}
