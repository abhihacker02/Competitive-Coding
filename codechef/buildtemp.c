#include<stdio.h>
int main()
{
	int t,i,j,k;
	scanf("%d",&t);
	int n,res[t];
	for(i=0;i<t;i++)
	{
		scanf("%d",&n);
		int a[n],b[k],pi,pf,del,f=0,r=0,min=-1,dv1,mk,q;
		for(j=0;j<n;j++)
		scanf("%d",&b[j]);
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			a[k]=b[k];
			pi=j;mk=0;q=0;
			dv1=1;del=0;pi=0;pf=0,f=1;r=0;
			for(k=j;k<n;k++)
			{
				if(f==1){
				
				if(a[k]>dv1)
				{
					del=a[k]-dv1;f=1,r=0;a[k]=dv1;
					dv1++;
					
				}
				else if(a[k]==dv1)
				{
					dv1++;
					f=1;r=0;
					
				}
				else if(a[k]<dv1)
				{
					if(a[k-1]-a[k]==1)
					{
						f=0;r=1;dv1=a[k]-1;
						if(dv1<=0)
						{t=1;
						pf=k;break;}
						
					}
					else if(a[k]==a[k-1])
					{
						r=1;f=0;a[k]=a[k]-1;
						dv1=a[k]-1;del++;
						if(dv1<=0)
						{t=1;
						pf=k;break;}
						continue;
					}
					else
					{
						if(a[k-2]-a[k]<=2)
						{
							del=del+a[k-1]-(a[k-2]-1);
							a[k-1]=a[k-2]-1;
							del=del+a[k]+1-a[k-1];
							a[k]=a[k-1]-1;
							dv1=a[k]-1;r=1;f=0;
						}
						else
						{
						
							if((k-pi)%2!=0&&a[k]==1)
							{
								mk=1;pf=k-1;t=1;dv1=0;
								for(q=k-1;;q--,mk++)
								{
									if(a[q]==mk)
									break;
									else
									{
										del=del+a[q]-mk;
										a[q]=mk;
									}
								}
							}
							else if((k-pi)%2!=0)
								mk=a[k]-1;
							else
								mk=a[k];
							dv1=mk-1;r=1;f=0;
							for(q=k-1;;q--)
							{
								mk++;
								if(a[q]==mk)
								break;
								else
								{
								del=del+a[q]-mk;a[q]=mk;}
							}
						}
						if(dv1<=0&&t!=1)
						{t=1;
						pf=k;break;}
						continue;
					}
				}
					if(dv1==0)
						{t=1;
						pf=k;break;}
			}
			else if(r==1)
			{
				if(dv1==a[k])
				{
					dv1--;r=1;f=0;
					if(dv1==0)
						{t=1;
						pf=k;break;}
						continue;
				}
				else if(dv1<a[k])
				{
					del=del+a[k]-dv1;a[k]=dv1;
					dv1--;r=1;f=0;
					if(dv1==0)
						{t=1;
						pf=k;break;}
						continue;
				}
				else
				{
							if((k-pi)%2!=0&&a[k]==1)
							{
								mk=1;pf=k-1;t=1;dv1=0;
								for(q=k-1;;q--,mk++)
								{
									if(a[q]==mk)
									break;
									else
									{
										del=del+a[q]-mk;a[q]=mk;
									}
								}
							}
							if((k-pi)%2!=0)
								mk=a[k]-1;
							else
								mk=a[k];
							dv1=mk-1;r=1;f=0;
							for(q=k-1;;q--)
							{
								mk++;
								if(a[q]==mk)
								break;
								else
								{
								del=del+a[q]-mk;a[q]=mk;}
							}
								if(dv1==0&&t!=1)
						{t=1;
						pf=k;break;}
						continue;
				}
		r=1;f=0;	}
	}
	if(t==1){
			
			for(q=0;q<pi;q++)
			{
				del+=a[q];
			}
			for(q=pf+1;q<n;q++)
			del+=a[q];
		}
			if(min==-1)
			min=del;
			else if(del<min)
			min=del;
		}
		res[i]=min;
	}
	for(i=0;i<t;i++)
	printf("%d",res[i]);
}
