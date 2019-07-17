#include<stdio.h>
#include<stdlib.h>
 
int max(int a[],int n){
int i,m,p=0;
m=a[0];
for(i=0;i<n;i++){
if(a[i]>m){
m=a[i];
p=i;
}
}
return p;
}
 
int min(int a[],int n){
int i,m,p=0;
m=a[0];
for(i=0;i<n;i++){
if(a[i]<m){
m=a[i];
p=i;
}
}
return p;
}
 
void rem(int a[],int n,int i){
if(n==0){
return;
}
int j;
for(j=i;j<n-1;j++){
int temp;
temp=*(a+j);
*(a+j)=*(a+j+1);
*(a+j+1)=temp;
}
 
}
int  sol(int a[],int n,int k){
if(n==0){return 0;}
int i,x;
x=n;
int var=0;
while(x>0){
 
for(i=0;i<x;i++){
if(a[i]>=k){
var++;
rem(a,x,i);x--;
i--;
}
}
rem(a,x,min(a,x));x--;
if(x<=0){
break;
}
a[max(a,x)]++;
}
return var;
}
 
 
int main(){
int t;
scanf("%d",&t);
int i,j;
int ans[500000];
int tmp=0;
  for(i=0;i<t;i++){
   int n,q;
scanf("%d%d",&n,&q);
 
int s[n];
for(j=0;j<n;j++){
scanf("%d",&s[j]);
}
for(j=0;j<q;j++){
int k;
int sq[n];
memcpy(sq,s,4*n);
scanf("%d",&k);
ans[tmp]=sol(sq,n,k);tmp++;
}
}
int o;
for(o=0;o<tmp;o++){
printf("%d\n",ans[o]);
}
return 0;
} 
