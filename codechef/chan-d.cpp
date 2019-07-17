#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;
	int a[n];
	int b[m];
	int c[m];
	for (int i = 0; i < m; ++i)
	{
		b[i]=0;
		c[i]=0;
	}
	vector<int> vec[m];
	for (int i = 0; i < n; ++i)
	{
		/* code */
		cin>>a[i];
		int g=a[i]%m;
		vec[g].push_back(i);
		b[g]++;
	}
	int h=n/m;
	vector<int> vec1,vec2;
	for (int i = 0; i < m; ++i)
	{
		if(b[i]<h)
			vec1.push_back(i);
		else if(b[i]>h)
			vec2.push_back(i);
	}
	int g=vec1.size();
	int f=vec2.size();
	if(g==0 && f==0)
	{
		cout<<"0\n";
		for (int i = 0; i < n; ++i)
		{
			cout<<a[i];
			if(i==n-1)
				cout<<endl;
			else
				cout<<" ";
		}
		return 0;
	}
	long long result=0;
	int i=0,j=0;
	for (int i = 0; i < f; ++i)
	{
		//cout<<vec2[i]<<endl;
		int w=b[vec2[i]]-h;
		//cout<<w<<endl;
		int e=(vec2[i]+1)%m;
		//cout<<e<<endl;
		while(w)
		{
			if(b[e]<h)
			{
				int r=(e+m-vec2[i])%m;
			//	cout<<r<<endl;
				w--;
				b[e]++;
				result+=r;
				b[vec2[i]]--;
				a[vec[vec2[i]][b[vec2[i]]]]+=r;
			}
			else
				e=(e+1)%m;
		}
	}
	cout<<result<<endl;
	for (int i = 0; i < n; ++i)
	{
		/* code */
		cout<<a[i];
		if(i==n-1)
			cout<<endl;
		else
			cout<<" ";
	}
	return 0;
}
