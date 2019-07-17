#include<stdio.h>
#include<string.h>
int main()
{
	char s[100000];
	int k,t,i;
	scanf("%d",&t);
	int res[t],f;
	for(k=0;k<t;k++)
	{
		f=1;
		scanf("%s", s);
		int len=strlen(s);
		for(i=0;i<len-1;i++)
		{
			if((s[i]=='E'&&s[i+1]=='C')||(s[i]=='S'&&s[i+1]=='E')||(s[i]=='S'&&s[i+1]=='C'))
			f=0;
		}
		if(f==1)
		res[k]=1;
		else
		res[k]=0;
	}
for(i=0;i<t;i++)
{
	if(res[i]==1)
	printf("yes\n");
	else
	printf("no\n");
}
}
