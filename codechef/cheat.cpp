#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,nt=0;
	cin>>n;
	int ans[n];
	for(int i=0;i<n;i++) ans[i]=-1;
	int left[n],right[n];
	for(int i=0;i<n;i++) cin>>left[i];
	for(int i=0;i<n;i++) cin>>right[i];
	for(int i=0;i<n;i++)
	{
		if(left[i]==0&&right[i]==0)
		{
			ans[i]=n;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(ans[i]==-1)
		{
			ans[i]=n-(left[i]+right[i]);
		}
	}
	for(int i=0;i<n;i++)
	{
		int c=0;
		for(int j=0;j<i;j++)
		{
			if(ans[j]>ans[i]) c++;
		}
		if(c!=left[i])
		{
			nt=1;break;
		}
		c=0;
		for(int j=i+1;j<n;j++)
		{
			if(ans[j]>ans[i]) c++;
		}
		if(c!=right[i])
		{
			nt=1;break;
		}
	}
	if(nt==1)
	{
		cout<<"NO";
	}
	else{
		cout<<"YES\n";
		for(int i=0;i<n;i++)
		{
			cout<<ans[i]<<" ";
		}
	}
}
