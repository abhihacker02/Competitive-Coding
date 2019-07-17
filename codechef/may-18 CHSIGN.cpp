#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define pb push_back
#define mp make_pair
typedef vector<int>v;
#define p pair<lli,int>
vector<p>vi;
int a[100005];
lli ans1[100005];
int vc[100005];
lli ans2[100005];
int sum=0,tot=0;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int prev=0;
		vi.clear();
		int n;
		scanf("%d",&n);
		a[0]=a[n+1]=1000000007;                                  
		for(lli i=1;i<=n;i++) scanf("%d",&a[i]);
		sum=0;tot=0;
		for(lli i=1;i<=n;i++){
			if(a[i]<a[i-1]&&a[i]<a[i+1]){
				if(sum==0){
					sum=a[i+1]+(-1*a[i]);
					tot=a[i];
					prev=i;
				}
				else{
					if((sum+(-1*a[i]))<1){
						vi.pb(mp(tot,prev));
						tot=0;prev=0;
						sum=a[i+1]+(-1*a[i]);
						tot=a[i];
						prev=i;
					}
					else{
						vi.pb(mp(tot,prev));
						vi.pb(mp(-1,0));
						tot=a[i];
						sum=a[i+1]+(-1*a[i]);
						prev=i;
					}
				}
				i++;
			}
			else{
				if(tot!=0){
				vi.pb(mp(tot,prev));
				vi.pb(mp(0,0));tot=0;sum=0;prev=0;
			}
			}
		}		
		if(prev!=0)
		vi.pb(mp(tot,prev));
		ans2[0]=0;vc[0]=0;vc[1]=0;
		ans2[1]=0;
		ans1[0]=0;
		if(vi.size()==0){
			for(int i=1;i<=n;i++) printf("%lld ",a[i]);printf("\n");
			continue;
		}
		else{
			ans1[1]=vi[0].first;ans2[1]=vi[0].second;              
			for(int i=1;i<vi.size();i++){
				ans2[i+1]=0;ans1[i+1]=0;
			    if((vi[i-1].first==0&&i!=1)||vi[i-1].first==-1){
			        ans1[i+1]=ans1[i]+vi[i].first;
			        ans2[i+1]=i;
			        vc[i+1]=vi[i].second;
			        continue;
			    }
				if(ans1[i]>vi[i].first+ans1[i-1]){
					ans1[i+1]=ans1[i];
					ans2[i+1]=i;
					vc[i+1]=0;
				}
				else{
					ans1[i+1]=vi[i].first+ans1[i-1];
					ans2[i+1]=i-1;
					vc[i+1]=vi[i].second;
				}
			}
			int i=vi.size();v an;
			while(i>1){
				an.pb(ans2[i]);
				i=ans2[i];
			}
			v fin;
			fin.pb(vc[vi.size()]);
			if(an.size()>0) fin.pb(ans2[an[an.size()-1]]);
			else fin.pb(ans2[1]);
			for(int i=an.size()-1;i>=0;i--){
				if(vc[an[i]]!=0)
				fin.pb(vc[an[i]]);
			}
			int mx=fin.size();
			for(int i=0;i<fin.size();i++){
				a[fin[i]]=-1*a[fin[i]];
			}
			for(int i=1;i<=n;i++){
				printf("%d ",a[i]);
			}
			printf("\n");
			}
	}
}   
