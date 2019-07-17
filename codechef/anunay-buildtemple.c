#include<stdio.h>
 
int move(int a[],int n){
int i=0,j=n-1,p=0,dv1=1,dv2=1;
while((i-1)!=(j+1)){
for(;i<n;i++){
if(a[i]<dv1){
while(a[i]!=0){a[i]--;p++;}
}
if(a[i]>dv1){
while(a[i]!=dv1){a[i]--;p++;}
}
if(a[i]!=0){dv1++;i++;break;}
 
}
for(;j>=0;j--){
if(a[j]<dv2){
while(a[j]!=0){a[j]--;p++;}
}
if(a[j]>dv2){
while(a[j]!=dv2){a[j]--;p++;}
}
if(a[j]!=0){dv2++;j--;break;}
}
}
return p;
}
 
 
 
 
 
int main(){
int t;
scanf("%d",&t);
int ans[t];
int i,j;
for(i=0;i<t;i++){
int n;
scanf("%d",&n);
int a[n];
for(j=0;j<n;j++){
scanf("%d",&a[j]);
}
ans[i]=move(a,n);
}
for(j=0;j<t;j++){
printf("%d\n",ans[j]);
}
return 0;
}
