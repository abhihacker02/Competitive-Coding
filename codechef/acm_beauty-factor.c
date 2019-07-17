#include<stdio.h>
int main()
{
	char st[50];
	printf("enter a string");
	scanf("%s", st);
	int l=strlen(st);
	char s[l];
	int i=0,j=0,k=0,pos;
	for(;i<l;i++)
	{
		if(st[i+1]==st[i])
		continue;
		else
		{
			pos=i;
			for(j=i+1;j<l;j++)
				s[k++]=st[j];
			break;
		}
	}
	for(i=0;i<=pos;i++)
		s[k++]=st[i];
	int m=1,sm=0;int c=1;
	for(i=0;i<l-1;i++)
	{
		if(s[i+1]==s[i])
		{
			c++;
			continue;
		}
		else
		{
			if(c>m)
			{
				sm=m;
				m=c;
				c=1;
				continue;
			}
			if(c>sm)
			{
				sm=c;
				c=1;
			}
		}
	}
	if(c>m)
	{
		sm=m;m=c;
	}
	if(c<=m&&c>sm)
	sm=c;
	if((m/2)<sm)
	{
	printf("\n%d",sm);return 0;}
	printf("\n%d",m/2);
}
