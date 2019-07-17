#include <iostream.h>
#include <algorithm>
using namespace std;
typedef long long int lli;
int count =-1;
void subseq(lli a[],int index,int n,lli k,lli product)
{
	if(index==n&&product<=k)
	count=count+1;
	else if(index<n)
	{
		if(lli(product*a[index])<=k)
		subseq(a,index+1,n,k,product*a[index]);
		subseq(a,index+1,n,k,product);
	}
}
int main()
{
	int n;lli k;
	cin >> n >> k;
	lli arr[n];
	for(int i=0;i<n;i++)
	cin >> arr[i];
	sort(arr,arr+n);
	subseq(arr,0,n,k,1);
	cout << count;
}
