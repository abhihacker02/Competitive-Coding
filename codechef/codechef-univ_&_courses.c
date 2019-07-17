#include<malloc.h>
#include<stdio.h>
int main()
{
	int t,n,i,j;
	scanf("%d",&t);
	int **a;int b[t];
	a=(int **)malloc(t*sizeof(int *));
	for(i=0;i<t;i++)
	{
		scanf("%d",&n);b[i]=n;
		a[i]=(int *)malloc(n*sizeof(int));
		for(j=0;j<n;j++)
		scanf("%d",&a[i][j]);
	}
	for(i=0;i<t;i++)
	{
		int max=a[i][0];
		for(j=0;j<b[i];j++)
		{
			if(a[i][j]>max)
			max=a[i][j];
		}
		printf("\n%d",b[i]-max);
	}
}
