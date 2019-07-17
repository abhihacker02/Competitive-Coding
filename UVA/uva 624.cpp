#include<bits/stdc++.h>
using namespace std;
typedef vector<int>vi;
#define pb push_back
vi ans;vi temp;int f=0,mx=0,n;int a[25];
void backtrack(int sum,int tot,int cd){
	//if(tot>=cd) return;
	//if(sum>n) return;
	if(mx==n){
		return;f=1;
	}
	if(sum>mx){
		ans=temp;
		mx=sum;
	} 
	for(int i=tot;i<cd;i++){
		if(f==1) break;
		if(sum+a[i]<=n) {
		temp.pb(a[i]);
		sum+=a[i];
		backtrack(sum,i+1,cd);
		temp.pop_back();sum-=a[i];
	}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>n;
	while(scanf("%d",&n)!=EOF){
		temp.clear();ans.clear();
		f=0;mx=0;
		cin>>t;
		//int a[t];
		for(int i=0;i<t;i++) cin>>a[i];
		backtrack(0,0,t);int sum=0;
		for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";sum+=ans[i];} cout<<"sum:"<<sum<<endl;
		scanf("%d",&n);
	}
}
