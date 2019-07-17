#include<stdio.h>
int main()
{
	int t,e,m,h,i,j,f1,f2,f3;
	scanf("%d",&t);
	int c,res[t];
	for(i=0;i<t;i++)
	{
		c=0;f1=0;f2=0;f3=0;
		scanf("%d %d %d",&e,&m,&h);
		while(e!=0&&m!=0&&(e>=m))
		{
			if(e==1&&h==0&&m==1)
			break;
			if(e==1&&m==1&&f1==1)
			break;
			if(m==1&&h==0&&f2==1&&e>=m)
			break;
			if(e>=m && e>1&&m>0&&f2!=1)
			{
				c++;
				e-=2;m--;f2=1;f1=f3=0;
			}
			if(h>0&&f1!=1&&(m!=0&&e!=0))
			{
				c++;
				e--;h--;m--;f1=1;f2=f3=0;
			}
			if(m>1&&e>0&&f3!=1)
			{
				if(m<e && ((f2==1&&h!=0)||f2!=1))
				continue;
				c++;
				e--;m-=2;f3=1;f1=f2=0;
			}
			if(h>0&&f1!=1&&m!=0 &&e!=0 )
			{
				f1=1;f2=f3=0;e--;m--;h--;c++;
			}
		}
		if(e==1&&m==1&&h>0)
		c++;
		res[i]=c;
	}
	for(i=0;i<t;i++)
	printf("%d\n",res[i]);
}
