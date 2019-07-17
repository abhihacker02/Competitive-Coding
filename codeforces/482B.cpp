#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli a1[130],a2[130],a3[130];
lli k[3];
int main(){
	memset(a1,0,sizeof a1);
	memset(a2,0,sizeof a2);
	memset(a3,0,sizeof a3);
	lli n;
	cin>>n;
	string s1,s2,s3;
	cin>>s1;
	cin>>s2;
	cin>>s3;
	lli l1=s1.length();
	lli l2=s2.length();
	lli l3=s3.length();

	for(int i=0;i<l1;i++) {
	a1[s1[i]]++;
	}
	for(int i=0;i<l2;i++) a2[s2[i]]++;
	for(int i=0;i<l3;i++) a3[s3[i]]++;
	int mx1=0,mx2=0,mx3=0;
	for(int i=0;i<130;i++){
		if(a1[i]<=0) continue;
			if(a1[i]==l1&&n==1) {
			a1[i]--;
			if(a1[i]>mx1) mx1=a1[i];
			continue;} 
			if(a1[i]+n<=l1) a1[i]=a1[i]+n;
			else{
				a1[i]=l1;
			}
		
		if(a1[i]>mx1) mx1=a1[i];
	}
	for(int i=0;i<130;i++){
		if(a2[i]<=0) continue;
			if(a2[i]==l1&&n==1) {
			a2[i]--;
				if(a2[i]>mx2) mx2=a2[i];
			continue;}
		if(a2[i]+n<=l2) a2[i]=a2[i]+n;
				else a2[i]=l2;
		
		if(a2[i]>mx2) mx2=a2[i];
	}
	for(int i=0;i<130;i++){
		if(a3[i]<=0) continue;
		if(a3[i]==l1&&n==1){
		 a3[i]--;
		 if(a3[i]>mx3) mx3=a3[i];
		 continue;}
				if(a3[i]+n<=l2) a3[i]=a3[i]+n;
				else a3[i]=l2;
			
		if(a3[i]>mx3) mx3=a3[i];
	}
	k[0]=mx1;k[1]=mx2;k[2]=mx3;
	sort(k,k+3);
//	cout<<mx1<<mx2<<mx3<<endl;
	if(k[2]==k[1]) cout<<"Draw\n";
	else{
		if(mx1>mx2){
			if(mx1>mx3) cout<<"Kuro\n";
			else cout<<"Katie\n";
		}
		else{
			if(mx2>mx3) cout<<"Shiro\n";
			else cout<<"Katie\n";
		}
	}
}
