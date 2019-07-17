#include<bits/stdc++.h>
using namespace std;
int main(){
	long long int a,c;
	long long int y,g,b;
	cin>>a>>c;
	cin>>y>>g>>b;
	long long int ry=y*2+g*1;
	long long int rb=1*g+3*b;
	if(ry>a) ry=ry-a;
	else ry=0;
	if(rb>c) rb=rb-c;
	else rb=0;
	cout<<ry+rb;
}
