#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MX = 1e5+5;
const int MOD = 1e9+7;
int a[MX],b[MX],c[MX];
long long int y[MX],x[MX];
int main() {
	#ifndef ONLINE_JUDGE
		freopen("in","r",stdin);
	#endif
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(y,0,sizeof y);
		int p,q,r;
		scanf("%d%d%d",&p,&q,&r);
		long long int c_sum = 0,a_sum = 0;
		for(int i=0;i<p;i++) scanf("%d",&a[i]),a_sum = a_sum + a[i];
		for(int i=0;i<q;i++) scanf("%d",&b[i]);
		for(int i=0;i<r;i++) scanf("%d",&c[i]),c_sum = c_sum + c[i];
		sort(a,a+p);
		sort(b,b+q,greater<int>());
		sort(c,c+r);
		int c_cnt = r-1;
		for(int i=0;i<q && c_cnt>=0;)
		{
			if(b[i]>=c[c_cnt])
			{
				y[i] = ((b[i]*(c_cnt*1LL+1)*1LL)%MOD + c_sum*1LL)*1LL%MOD;
				i++;
			}
			else
			{
				c_sum -= c[c_cnt];
				c_cnt--;
			}
		}
		//for(int i=0;i<q;i++) printf("%llu ",y[i]);
		if(p>100 || q>100 || r>100){
			int a_cnt = p-1;
			for(int i=0;i<q && a_cnt>=0;)
			{
				if(b[i]>=a[a_cnt])
				{
					x[i] = ((b[i]*(a_cnt*1LL+1)*1LL)%MOD + a_sum*1LL)*1LL%MOD;
					i++;
				}
				else
				{
					a_sum -= a[a_cnt];
					a_cnt--;
				}
			}
			// for(int i=0;i<q;i++) printf("%llu ",x[i]);
			long long int result = 0;
			for(int i=0;i<q;i++)
			{
				result = (result*1LL%MOD + (x[i]*1LL%MOD * y[i]*1LL%MOD)%MOD)%MOD;
			}
			printf("%lld\n", result);
		}
		else
		{
			long long int result = 0;
			for(int i=0;i<p;i++)
			{
				for(int j=0;j<q;j++)
				{
					if(a[i]<=b[j])
						result = (result%MOD + ((a[i]*1LL+b[j]*1LL)%MOD * (y[j]%MOD))%MOD)%MOD;
				}
			}
			printf("%lld\n",result);			
		}
	}
	return 0;
}  
