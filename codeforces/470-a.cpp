#include<bits/stdc++.h>
using namespace std;
char a[505][505];
int main(){
	int n,m;
	cin>>n>>m;int ans=1;
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++) cin>>a[i][j];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]=='.'||a[i][j]=='W'||a[i][j]=='D') continue;
			if(i==0&&j==0){
				if((a[0][1]=='W'||a[1][0]=='W') )
				ans=0;break;
			}
			else if(i==n-1&&j==m-1){
				if((a[i-1][j]=='W'||a[i][j-1]=='W') )
				ans=0;break;
			}
			else if(i==0){
				if(a[i][j-1]=='W'||a[i][j+1]=='W'||a[i+1][j]=='W') ans=0;break;
			}
			else if(i==n-1){
				if(a[i][j-1]=='W'||a[i][j+1]=='W'||a[i-1][j]=='W') ans=0;break;
			}
			else if(j==0){
				if(a[i+1][j]=='W'||a[i-1][j]=='W'||a[i][j+1]=='W') ans=0;break;
			}
			else if(j==m-1){
				if(a[i-1][j]=='W'||a[i+1][j]=='W'||a[i][j-1]=='W') ans=0;break;
			}
			else{
				if(a[i][j-1]=='W'||a[i][j+1]=='W'||a[i+1][j]=='W'||a[i-1][j]=='W') ans=0;break;
			}
		}
	}
	if(ans==0) cout<<"No\n";
	else {
		cout<<"Yes\n";
		for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
		
		{
			if(a[i][j]=='.')cout<<'D';
			else cout<<a[i][j];
		}
		cout<<endl;}
	}
}
