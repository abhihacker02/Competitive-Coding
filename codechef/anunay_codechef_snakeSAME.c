#include<stdio.h>
 
#define mx(a,b) (a>b)?a:b
 
#define mn(a,b) (a>b)?b:a
 
int main(){
int t;
scanf("%d",&t);
int i,j;
int ans[t];
for(i=0;i<t;i++){
int x11,y11,x12,y12;
int x21,y21,x22,y22;
int x111,y111,x121,y121;
int x211,y211,x221,y221;
scanf("%d",&x111);
scanf("%d",&y111);
scanf("%d",&x121);
scanf("%d",&y121);
scanf("%d",&x211);
scanf("%d",&y211);
scanf("%d",&x221);
scanf("%d",&y221);
x11=mn(x111,x121);
x12=mx(x111,x121);
y11=mn(y111,y121);
y12=mx(y111,y121);
x21=mn(x211,x221);
x22=mx(x211,x221);
y21=mn(y211,y221);
y22=mx(y211,y221);
 
if(y11==y12){
if(y21==y22&&y21==y11){if((x21<x12&&x22>x12)||(x22>x11&&x21<x11)){ans[i]=1;}
else{ans[i]=0;}
}
else{
if(y21==y22){ans[i]=0;}
if(x21==x22){if((x21==x11||x21==x12)&&(y11==y21||y11==y22)){ans[i]=1;}
else{ans[i]=0;}
}
}
}
if(x11==x12){
if(x21==x22&&x21==x11){if((y21<y12&&y22>y12)||(y22>y11&&y21<y11)){ans[i]=1;}
else{ans[i]=0;}
}
else{
if(x21==x22){ans[i]=0;}
if(y21==y22){if((y21==y11||y21==y12)&&(x11==x21||x11==x22)){ans[i]=1;}
else{ans[i]=0;}
}
}
}
if(ans[i]!=0&&ans[i]!=1){ans[i]=0;}
}
int o;
for(o=0;o<t;o++){
if(ans[o]==1){printf("yes\n");}
 
if(ans[o]==0){printf("no\n");}
}
return 0;
} 
