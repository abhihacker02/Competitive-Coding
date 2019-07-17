#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,sum=0,min1=1000000000;
	cin>>n;
	int a[2*n];
	for(int i=0;i<2*n;i++)
		cin>>a[i];
	sort(a,a+2*n);
	vector<int> v;
	for(int i=0;i<2*n;i++){
		for(int j=i+1;j<2*n;j++){
			v.clear();
			for(int k=0;k<2*n;k++)
				if(k!=i && k!=j)
					v.push_back(a[k]);
			sum=0;
			for(int j=0;j<2*n-2;j+=2)
				sum+=v[j+1]-v[j];
			min1=min(min1,sum);
		}
	}
	cout<<min1;
	return 0;
}
