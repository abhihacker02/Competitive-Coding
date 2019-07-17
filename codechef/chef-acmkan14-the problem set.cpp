#include<bits/stdc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define SUM(v) accumulate(v.begin(),v.end(),lli(0))
#define rev(n) for(int i=n;i>=0;i--)
#define FOR0(n) for(int i=0;i<n;i++)
#define FOR(a,n) for(int i=a;i<n;i++)
#define FORQ(a,n) for(int i=a;i<=n;i++)
#define inf 1000000009
#define inff 0x3f3f3f3f
#define sz(a) int((a).size())
#define all(c) c.begin(), c.end()
#define ff first
#define ss second
#define endl "\n"
#define mod 1000000007
#define mem(ar,x) memset(ar,x,sizeof ar)
#define present(container, element) (container.find(element) != container.end())
#define max3(a,b,c) return (lli(a)>lli(b)?(lli(a)>lli(c)?a:c):(lli(b)>lli(c)?b:c))
#define max4(a,b,c,d) return (max3(a,b,c)>lli(d)?(max3(a,b,c)):d)
#define min3(a,b,c) return (lli(a)<lli(b)?(lli(a)<lli(c)?a:c):(lli(b)<lli(c)?b:c))
#define min4(a,b,c,d) return (max3(a,b,c)<lli(d)?(max3(a,b,c)):d)
typedef long long int lli;
typedef pair<lli,lli> pii;
typedef pair<int,pii>ppii;
typedef vector<int>vi;
typedef vector<vi>vvi;
typedef vector<pii>vpii;
const int N=100005;
int dr8[]={0,0,1,-1,1,1,-1,-1};
int dc8[]={1,-1,0,0,-1,1,-1,1};
int dr4[]={0,1,-1,0};
int dc4[]={1,0,0,-1};
lli a[N];int n,q;
struct nd{
	lli el,sum,mn,mx,in,dc;
//	nd(int v){
//		el=v;
//		mn=v;mx=v;in=1;dc=1;sum=v;
//	}
};
nd tree[4*N];
void build(int node,lli l,lli r){
	if(l==r) {
		lli val=a[l];
		tree[node].el=val;
		tree[node].mn=val;
		tree[node].mx=val;
		tree[node].dc=1;
		tree[node].sum=val;
		tree[node].in=1;
		return;
	}
	lli mid=(l+r)/2;
	build(2*node,l,mid);
	build((2*node)+1,mid+1,r);
	tree[node].sum=tree[2*node].sum+tree[(2*node)+1].sum;
	tree[node].mx=max(tree[2*node].mx,tree[(2*node)+1].mx);
	tree[node].mn=min(tree[2*node].mn,tree[(2*node)+1].mn);
	if(tree[2*node].in==1&&tree[(2*node)+1].in==1&&tree[node*2].mx<=tree[(2*node)+1].mn)
		tree[node].in=1;
	else 
		tree[node].in=0;
	if(tree[2*node].dc==1&&tree[(2*node)+1].dc==1&&tree[node*2].mn>=tree[(2*node)+1].mx)
		tree[node].dc=1;
	else 
		tree[node].dc=0;
}
void upd(lli node,lli in,lli val,lli l,lli r){
	if(l==r){
		tree[node].el=val;
		tree[node].mn=val;
		tree[node].mx=val;
		tree[node].dc=1;
		tree[node].sum=val;
		tree[node].in=1;
		a[in]=val;
		return ;
	}
	lli mid=(l+r)/2;
	if(in<=mid){
		upd((node*2),in,val,l,mid);
	}
	else{
		upd((node*2)+1,in,val,mid+1,r);
	}
	tree[node].sum=tree[2*node].sum+tree[(2*node)+1].sum;
	tree[node].mx=max(tree[2*node].mx,tree[(2*node)+1].mx);
	tree[node].mn=min(tree[2*node].mn,tree[(2*node)+1].mn);
	if(tree[2*node].in==1&&tree[(2*node)+1].in==1&&tree[node*2].mx<=tree[(2*node)+1].mn)
		tree[node].in=1;
	else 
		tree[node].in=0;
	if(tree[2*node].dc==1&&tree[(2*node)+1].dc==1&&tree[node*2].mn>=tree[(2*node)+1].mx)
		tree[node].dc=1;
	else 
		tree[node].dc=0;
}
lli qmin(lli node,lli ql,lli qr,lli l,lli r){
	if(qr<l||ql>r) return 0;
	if(ql<=l&&qr>=r) return tree[node].mn;
	lli mid=(l+r)/2;
	return min(qmin((2*node),ql,qr,l,mid),qmin((2*node)+1,ql,qr,mid+1,r));
}
lli qmax(lli node,lli ql,lli qr,lli l,lli r){
	if(qr<l||ql>r) return 0;
	if(ql<=l&&qr>=r) return tree[node].mx;
	lli mid=(l+r)/2;
	return max(qmax((2*node),ql,qr,l,mid),qmax((2*node)+1,ql,qr,mid+1,r));
}
lli qsum(lli node,lli ql,lli qr,lli l,lli r){
	if(qr<l||ql>r) return 0;
	if(ql<=l&&qr>=r) return tree[node].sum;
	lli mid=(l+r)/2;
	return (qsum((2*node),ql,qr,l,mid)+qsum((2*node)+1,ql,qr,mid+1,r));
}
pii qin(lli node,lli ql,lli qr,lli l,lli r){
	if(qr<l||ql>r) return mp(-1*inf,inf);
	if(ql<=l&&qr>=r){
		if(tree[node].in==1)
		return mp(tree[node].mx,tree[node].mn);
		else return mp(inf,-1*inf);
	}
	lli mid=(l+r)/2;
	pii ll=qin((2*node),ql,qr,l,mid);
	pii rr=qin((2*node)+1,ql,qr,mid+1,r);
	if(ll.ff<=rr.ss) return mp(max(ll.ff,rr.ff),min(ll.ss,rr.ss));
	else return mp(inf,-1*inf);
}
pii qdc(lli node,lli ql,lli qr,lli l,lli r){
	if(qr<l||ql>r) return mp(-1*inf,inf);
	if(ql<=l&&qr>=r){
		if(tree[node].dc==1)
		return mp(tree[node].mx,tree[node].mn);
		else return mp(inf,-1*inf);
	}
	lli mid=(l+r)/2;
	pii ll=qdc((2*node),ql,qr,l,mid);
	pii rr=qdc((2*node)+1,ql,qr,mid+1,r);
	if(ll.ss>=rr.ff) return mp(max(ll.ff,rr.ff),min(ll.ss,rr.ss));
	else return mp(inf,-1*inf);
}
int main(){
	fast
	char ch;lli x,y;
	cin>>n>>q;
	FOR0(n) cin>>a[i];
	build(1,0,n-1);
	while(q--){
		cin>>ch>>x>>y;
		if(ch=='U'){
			upd(1,x-1,y,0,n-1);
		}
		else if(ch=='S'){
			cout<<qsum(1,x-1,y-1,0,n-1)<<endl;
		}
		else if(ch=='M'){
			cout<<qmax(1,x-1,y-1,0,n-1)<<endl;
		}
		else if(ch=='I'){
			pii p=qin(1,x-1,y-1,0,n-1);
			if(p.ff==inf||p.ss==inf||p.ff==-1*inf||p.ss==-1*inf) cout<<0<<endl;
			else cout<<1<<endl;
		}
		else if(ch=='D'){
			pii p=qdc(1,x-1,y-1,0,n-1);
			if(p.ff==inf||p.ss==inf||p.ff==-1*inf||p.ss==-1*inf) cout<<0<<endl;
			else cout<<1<<endl;
		}
	}
}

