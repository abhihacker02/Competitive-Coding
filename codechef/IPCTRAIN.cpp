#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<iterator>
typedef long long int lli;
using namespace std;
int main()
{
	int t;
	cin>>t;
	lli res[t];
	for(int i=0;i<t;i++)
	{
		int n,d;
		lli sum=0;
		cin>>n>>d;
		int a[n][3];
		for(int j=0;j<n;j++)
			cin>>a[j][2]>>a[j][1]>>a[j][0];
			
			

   // cout << "Before Sort..." << '\n';
    //std::for_each(a, a+n,
      //  [](const int(&a)[3]) { std::cout << a[0] << ',' << a[1] <<',' <<a[2]<<'\n';});

    std::qsort(a, n, sizeof(*a),
        [](const void *arg1, const void *arg2)->int
        {
            int const *lhs = static_cast<int const*>(arg1);
            int const *rhs = static_cast<int const*>(arg2);
            return (lhs[0] < rhs[0]) ? -1
                :  ((rhs[0] < lhs[0]) ? 1
                :  (lhs[1] < rhs[1] ? -1
                :  ((rhs[1] < lhs[1] ? 1 : 0))));
        });

    //std::cout << "After Sort..." << '\n';
    //std::for_each(a, a+n,
      //  [](const int(&a)[3]) { std::cout << a[0] << ',' << a[1] <<','<<a[2]<< '\n';});
			
			
		for(int j=1;j<=d;j++)
		{
			int max=0,pos=-1;
			for(int k=0;k<n;k++)
			{
				if(j==1)
				{
					sum+=(a[k][1]*a[k][2]);
				}
				if((a[k][1]>0)&&a[k][2]<=j)
				{max=a[k][2];pos=k;break;}
			}
			if(pos!=-1)
			a[pos][1]--;
			sum-=max;
		}
		res[i]=sum;
	}
	for(int i=0;i<t;i++)
	cout<<res[i]<<endl;
}
