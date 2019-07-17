#include <stdio.h>
#include<stdlib.h>
//#include <algorithm>
//using namespace std;
typedef long long int lli;
lli count =-1;
int comp (const void * elem1, const void * elem2) 
{
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}
void subseq(lli a[],int index,int n,lli k,lli product)
{
	if(index==n&&product<=k)
	count=count+1;
	else if(index<n)
	{
		if((lli)(product*a[index])<=k)
		subseq(a,index+1,n,k,product*a[index]);
		subseq(a,index+1,n,k,product);
	}
}
int main()
{
	int n,i;lli k;
	scanf("%d %lld",&n,&k);
	lli arr[n];
	for(i=0;i<n;i++)
	scanf("%lld",&arr[i]);
	qsort(arr,n,sizeof(lli),comp);
	subseq(arr,0,n,k,1);
	printf("%lld",count);
	return 0;
}
