#include<bits/stdc++.h>
using namespace std;
 
int itemPrice, n, coins[111], maxi;
int dp[111][10009*2], paid;
const int oo = 1000000;
 
int calc(int idx,int value)
{
	if(value<0) return oo;
	if( idx == n )
		if( value == 0 )
		return 0;
		else
			return oo;
	int &ret = dp[idx][value] ;
	if( ret != -1 )
		return ret;
 
	return ret = min(calc(idx+1,value), calc(idx+1,value-coins[idx]) + 1 );
	
 
}
 
int main()
{
	int cases;
	scanf("%d",&cases);
 
	while( cases-- )
	{
		scanf("%d%d",&itemPrice,&n);
		for(int i = 0 ; i < n ; ++i)
			scanf("%d",coins+i);
		memset(dp,-1,sizeof dp);
		int ret;
		for(int i = itemPrice ; i <= itemPrice + 10000 ; ++i)
		{
			ret = calc(0,i);
 
			if( ret != oo )
			{
				paid = i;
				break;
			}
		}
 
		printf("%d %d\n",paid,ret);
	}
	return 0;
}
