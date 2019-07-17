#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define mx 500005
int tree[2*mx];
int ar[mx];
int L,R;
int gcd(int a , int b)
{
	if(a==1||b==1) return 1;
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}
void build(int node, int start, int end)
    {
        if(start == end)
            tree[node] = ar[start];
        else
        {
            int mid = (start + end) / 2;
            build(2*node, start, mid);
            build(2*node+1, mid+1, end);
            tree[node] =gcd(tree[2*node],tree[2*node+1]);
        }
    }
void update(int node, int start, int end, int idx, int val)
{
    if(start == end)
    {
        ar[idx]=val;
        tree[node]=val;
    }
    else
    {
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
        {
            update(2*node, start, mid, idx, val);
        }
        else
        {
            update(2*node+1, mid+1, end, idx, val);
        }
        tree[node] = gcd(tree[2*node],tree[2*node+1]);
    }
}
int query(int node, int start, int end, int l, int r,int num)
{
	int mid = (start + end) / 2;
    if(r < start or end < l)
    {
        return 0;
    }
    if(start==end){
    	if(gcd(num,tree[node])==1) return 1;else return 0;
	}
    if(l <= start and end <= r)
    {
        if(gcd(num,tree[node])!=1) return 0;
        else 
        return query(2*node,start,mid,l,r,num)+query(2*node+1,mid+1,end,l,r,num);
    }
    int p1 = query(2*node, start, mid, l, r,num);
    int p2 = query(2*node+1, mid+1, end, l, r,num);
    return p1+p2;
}
int main(){
    //std::ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,q,t,x,y,num;
    scanf("%d",&n);
    //int a[n];
    for(int i=1;i<=n;i++) scanf("%d",&ar[i]);
	  scanf("%d",&q);
    build(1,1,n);
    for(int i=0;i<q;i++){
        scanf("%d",&t);
        if(t==1){
        	scanf("%d %d",&x,&y);
            update(1,1,n,x,y);
        }
        else{
        	scanf("%d %d %d",&x,&y,&num);
            printf("%d\n",query(1,1,n,x,y,num));
        }
    }
    
}
