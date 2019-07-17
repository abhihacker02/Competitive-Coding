#include<iostream>
#include<stdlib.h>
#include<algorithm>
typedef long long int lli;
using namespace std;
int n;//lli sum=0;
void find(lli in,lli fn,int** a,int sum)
{
	if(in>=n)
	return;
	if(fn==in)
	cout<<sum;
	for(int i=0;i<n;i++)
	{
		if(a[in][i]!=0)
		{
			sum+=a[in][i];
		find(i,fn,a,sum);
		}
	}
}
int main()
{
	int t,n;
	cin>>t;
	lli res[t];
	for(int j=0;j<t;j++){
	cin>>n;
	int **a;
	a=(int**)calloc(n,sizeof(int*));
	for(int i=0;i<n;i++)
	a[i]=(int *)calloc(n,sizeof(int));
	for(int i=0;i<n-1;i++)
	{
		int el1,el2,val;
		cin>>el1>>el2>>val;
		a[el1-1][el2-1]=val;
		a[el2-1][el1-1]=val;
	}
	int m;
	cin>>m;
	lli u,v,k;
//	for(int i=0;i<m;i++)
//	{
		cin>>u>>v>>k;
	//	if(a[u-1][v-1]!=0)
	//	sum+=a[u-1][v-1];
	//	else
	find(u-1,v-1,a,0);
//0	}
//	cout<<sum;
}
}
