#include<bits/stdc++.h>
using namespace std;
int n,m,i,a,b=1;
int main(){
for(cin>>n,cin>>a,m=n-1;m--;)cin>>b;
cout<<(n%2&&a%2&&b%2?"Yes":"No");
}
