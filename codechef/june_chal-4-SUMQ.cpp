#include<iostream>
#include<algorithm>
#define mod 1000000007
#define fo for(int i=0;i<t;i++)
#define f for(int j=0;j<n;j++)
typedef long long int lli;
using namespace std;
int main()
{
	int t;
	cin>>t;
	lli res[t];
	fo
	{
		int p,q,r,n;
	    cin>>p>>q>>r;
		lli a[p],b[q],c[r];
		lli s=-1;
		lli ac[3][p*r];
		n=p;
		f{
		cin>>a[j];
		}
		n=q;
		f{
		cin>>b[j];}
		n=r;
		f{
		cin>>c[j];
		for(int w=0;w<p;w++)
		{
			ac[0][++s]=a[w]*c[j];
			ac[1][s]=(a[w]+c[j])%mod;
			ac[2][s]=c[j];
			if(c[j]<a[w]) ac[2][s]=a[w];
		}
		}
		lli sum=0;
		for(lli j=0;j<=s;j++)
		{
			for(int l=0;l<q;l++)
			{
				if(b[l]>=ac[2][j])
				sum=(sum+(ac[0][j])%mod+(b[l]*b[l])%mod+(b[l]*ac[1][j])%mod)%mod;
			}
		}
	//	sort(a,a+p);
	//	sort(b,b+q);
	//	sort(c,c+r);
	/*	for(int j=0;j<p;j++)
		{
			int z=r;if(a[j]>b[q-1]) break;
			for(int k=q-1;k>=0;k--)
			{
				if(a[j]<=b[k])
				{
					for(int l=0;l<r;l++)
					{
						if(b[k]>=c[l])
						sum=(sum+(((a[j]+b[k])%mod)*((b[k]+c[l])%mod)))%mod;
						else {l=z;
						break;}
					}
				}
				else {
				break;}
			}
		}*/
		res[i]=sum%mod;
	}
	fo{cout<<res[i]<<"\n";}
}
