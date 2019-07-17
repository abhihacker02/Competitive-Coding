#include<iostream>
typedef long long int lli;
int main()
{
	int t,i;
	scanf("%d",&t);
	lli res[t];
	lli u,v;
	for(i=0;i<t;i++){
	scanf("%lld %lld",&u,&v);
	lli s,sm;
	s=u+v;
	sm=s*(s+1)/2;
	sm=sm+1+u;
	res[i]=sm;}
	for(i=0;i<t;i++)
	printf("%lld\n",res[i]);
}
