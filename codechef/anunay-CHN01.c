#include<stdio.h>
 
int main(){
int t;
scanf("%d",&t);
int i,j,k,l;
for(i=0;i<t;i++){
int a,b,c;
scanf("%d%d%d",&a,&b,&c);
int x,y,z;
x=c;
y=(2*b-a-c)/3;
z=(2*a-b-c)/3;
int m=x+y+z;
printf("%d\n",m);
}
return 0;
}
