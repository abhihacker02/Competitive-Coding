#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long int lli;
vector<int>pf;
void primeFactors(int n)
{
    while (n%2 == 0)
    {
        pf.pb(2);
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        while (n%i == 0)
        {
            pf.pb(i);
            n = n/i;
        }
    }
    if (n > 2)
        pf.pb(n);
}
int main(){
	int t;
	cin>>t;
	while(t--){
		pf.clear();
		int n,c;
		cin>>n>>c;
		primeFactors(c);
	//	for(int i=0;i<pf.size();i++) cout<<pf[i]<<" ";cout<<endl;
		sort(pf.begin(),pf.end());
		if(pf.size()>n){
			int ar[n];int k=0;
			for(int i=pf.size()-1;i>=pf.size()-n;i--){
				ar[k]=pf[i];k++;
			}
	//		for(int i=0;i<n;i++) cout<<ar[i]<<" ";cout<<endl;
			for(int i=pf.size()-n-1;i>=0;i--){
				int mn=ar[0];int pos=0;
				for(int j=1;j<n;j++){
					if(ar[j]<mn){
						mn=ar[j];
						pos=j;
					}
					//	for(int i=0;i<n;i++) cout<<ar[i]<<" ";cout<<endl;
				}
				ar[pos]=ar[pos]*pf[i];
			}
	//		for(int i=0;i<n;i++) cout<<ar[i]<<" ";cout<<endl;
			pf.clear();
			for(int i=0;i<n;i++){
				pf.pb(ar[i]);
			}
		}
	//	cout<<n<<endl;
	//	cout<<pf.size()<<endl;
	int sz=pf.size();
		for(int i=0;i<n-sz;i++){
			pf.pb(1);
		}
		//for(int i=0;i<pf.size();i++) cout<<pf[i]<<" ";cout<<endl;
		sort(pf.begin(),pf.end());
		int an1[n+1],an2[n+1];int id=0;an1[0]=an2[0]=0;
		for(int i=1;i<=n;i++){
			if(i<n-pf.size()+1){
				an1[i]=i;
			}
			else{
			an1[i]=max(i,pf[id]+i-1);}
			id++;
		}
		int np=0;
		id=pf.size()-1;
		for(int i=1;i<=n;i++){
			an2[i]=max(i,pf[id]+i-1);
			//an2[i]=max(an2[i],an2[i-1]);
			if(an2[i]<an2[i-1]){
				np=1;break;
			}
			id--;
		}
		if(np==0){
			if(an2[n]<an1[n]){
				for(int i=1;i<=n;i++) cout<<an2[i]<<" ";
			}
			else{
				for(int i=1;i<=n;i++) cout<<an1[i]<<" ";
			}
		}
		else {
			for(int i=1;i<=n;i++) cout<<an1[i]<<" ";
		}
	}
}