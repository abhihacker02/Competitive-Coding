#include<stdio.h>
#include<math.h>
#include<stdlib.h>
typedef long long int lli;
int main()
{
	int t,i;
	scanf("%d",&t);
	lli res[t];
	for(i=0;i<t;i++)
	{
		lli n,count=0,diff;
		scanf("%lld",&n);
		lli temp=n;
		while(n>0)
		{
			n=n/2;
			count++;
		}
		lli diff1=pow(2,count-1)-temp;
		lli diff2=pow(2,count)-temp;
		lli diff3=pow(2,count+1)-temp;
		if(diff1<0)
		diff1=-1*diff1;
		if(diff2<0)
		diff2=-1*diff2;
		if(diff3<0)
		diff3=-1*diff3;
		if(diff1>diff2)
		{
			if(diff2>diff3)
			res[i]=diff3;
			else
			res[i]=diff2;
		}
		else{
			if(diff1>diff3)
			res[i]=diff3;
			else
			res[i]=diff1;
		}
	}
	for(i=0;i<t;i++)
	printf("%lld\n",res[i]);
}
