#include<bits/stdc++.h>
using namespace std;
typedef long long int lld;
int main(){
	int t;
	cin>>t;
	while(t--){
		double p1,p2,p3,q1,q2,q3,d1,d2,d3,c1,c2,c3,c,C=0,k1,k2,k3;
		cin>>p1>>p2>>p3>>q1>>q2>>q3>>d1>>d2>>d3>>c1>>c2>>c3>>c;
		k1=p1-c1;k2=p2-c2;k3=p3-c3;
		C=(c*c)-(k1*k1)-(k2*k2)-(k3*k3);
		double a=2*((d1*d2*k1*k2)+(d2*d3*k2*k3)+(d1*d3*k1*k3))+((pow(k1,2)+C)*pow(d1,2))+((pow(k2,2)+C)*pow(d2,2))+((pow(k3,2)+C)*pow(d3,2));
		double b=2*((q1*d2*k1*k2)+(q2*d1*k1*k2)+(q3*d1*k1*k3)+(q1*d3*k1*k3)+(q2*d3*k2*k3)+(q3*d2*k2*k3)+((q1*d1)*(pow(k1,2)+C))+((q2*d2)*(pow(k2,2)+C))+((q3*d3)*(pow(k3,2)+C)));
		double k=2*((q1*q2*k1*k2)+(q1*q3*k1*k3)+(q2*q3*k2*k3))+(((k1*k1)+C)*((q1*q1)))+(((k1*k1)+C)*(q2*q2))+(((k3*k3)+C)*(q3*q3));
		double t1=0,t2=0;
	//	cout<<a<<" "<<b<<" "<<k<<endl;
		if(a==0){
			double ans=-k/double(b);
			printf("%0.8f\n",ans);
			continue;
		}
		//cout<<pow(b,2)<<endl;
		double an=0.0;
		cout<<setprecision(3)<<(b*b)<<endl;
		double tf=(b*b)-(4*a*k);
		cout<<tf<<endl;
		an=sqrt(int(tf));
	//	cout<<sqrt(100000000)<<endl;
		cout<<an<<endl;
		t1=(-b+sqrt(((b*b)-(4*a*k))))/(double)(2*a);
		t2=(-b-sqrt(((b*b)-(4*a*k))))/(double)(2*a);
		cout<<a<<b<<k<<endl;
		if(t1>=0&&t2>=0){
			if(t1>t2)
			printf("%.8f\n",t1);
			//cout<<t1<<endl;
			else 
			printf("%.8f\n",t2);
		}
		else{
			if(t1<0){
				printf("%.8f\n",t2);
			}
			else{
				printf("%.8f\n",t1);
			}
		}
	}
}
