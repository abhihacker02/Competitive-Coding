#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define FOR0(n) for(int i=0;i<n;i++)
#define FOR(a,n) for(int i=a;i<n;i++)
#define FORQ(a,n) for(int i=a;i<=n;i++)
#define inf 1e14
#define sz size()
#define all(c) c.begin(), c.end()
#define fs first
#define sc second
#define mem(ar,x) memset(ar,x,sizeof ar)
#define present(container, element) (container.find(element) != container.end())
#define max3(a,b,c) return (lli(a)>lli(b)?(lli(a)>lli(c)?a:c):(lli(b)>lli(c)?b:c))
#define max4(a,b,c,d) return (max3(a,b,c)>lli(d)?(max3(a,b,c)):d)
#define min3(a,b,c) return (lli(a)<lli(b)?(lli(a)<lli(c)?a:c):(lli(b)<lli(c)?b:c))
#define min4(a,b,c,d) return (max3(a,b,c)<lli(d)?(max3(a,b,c)):d)
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<int,pii>ppii;
typedef vector<int>vi;
typedef vector<vi>vvi;
typedef vector<pii>vpii;
const int N=100005;
int dr8[]={0,0,1,-1,1,1,-1,-1};
int dc8[]={1,-1,0,0,-1,1,-1,1};
int dr[]={0,1,-1,0};
int dc[]={1,0,0,-1};
int vis[N];
vi gr[N];
int tr[4*N];
int a[N];
lli D[N];
int n;
lli fib[1005];
//FIBONACCI--------------------------------------------------------------------------
void fibo(int k){
	fib[0]=0;fib[1]=1;
	FOR(2,k){
		fib[i]=fib[i-1]+fib[i-2];
	}
}

//------------------------------------------------------------------------------------

//DIJKSTRA--------------------------------------------------------------------------------
/*
priority_queue<pii,vector<pii>, greater<pii> > Q; 
      // priority_queue with reverse comparison operator, 
      // so top() will return the least distance
      // initialize the start vertex, suppose it’s zero
      D[0] = 0;
      Q.push(pii(0,0));
      // iterate while queue is not empty
      while(!Q.empty()) {
         // fetch the nearest element
            pii top = Q.top();
            Q.pop();           
            // v is vertex index, d is the distance
            int v = top.second, d = top.first;
            // this check is very important
            // we analyze each vertex only once
            // the other occurrences of it on queue (added earlier) 
            // will have greater distance
            if(d <= D[v]) {
                  // iterate through all outcoming edges from v
                  tr(G[v], it) {
                        int v2 = it->first, cost = it->second;
                        if(D[v2] > D[v] + cost) {
                              // update distance if possible
                              D[v2] = D[v] + cost;
                              // add the vertex to queue
                              Q.push(pii(D[v2], v2));

                        }
                  }
            }
      }
      */
//-----------------------------------------------------------------------------------

//RMQ---------------------------------------------------------------------------------
/*
void build(int id = 1,int l = 0,int r = n){
	if(r - l < 2){	//	l + 1 == r
		tr[id] = a[l];
		return ;
	}
	int mid = (l+r)/2;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid, r);
	tr[id] = tr[id * 2] + tr[id * 2 + 1];
}
void modify(int p,int x,int id = 1,int l = 0,int r = n){
	tr[id] += x - a[p];
	if(r - l < 2){	//	l = r - 1 = p
		a[p] = x;
		return ;
	}
	int mid = (l + r)/2;
	if(p < mid)
		modify(p, x, id * 2, l, mid);
	else
		modify(p, x, id * 2 + 1, mid, r);
}

int query(int x,int y,int id = 1,int l = 0,int r = n){
	if(x >= r or l >= y)	return 0;
	if(x <= l && r <= y)	return s[id];
	int mid = (l+r)/2;
	return sum(x, y, id * 2, l, mid) +
	       sum(x, y, id * 2 + 1, mid, r);
}
*/
//-----------------------------------------------------------------------------------

//DFS----------------------------------------------------------------------------------
/*
void dfs(int u){
	vis[u]=1;
	for(int i=0;i<gr[u].size();i++){
		int v=gr[u][i];
		if(!vis[v]){
			dfs(v);
		}
	}
}
*/
//-----------------------------------------------------------------------------------

int main(){
	//This solution is correct but only it does not uses BigInt class therefore wrong answer.
	fast
	fibo(1004);
	lli ans[1005];
	ans[0]=1,ans[1]=2,ans[2]=lli(3);
	FORQ(3,1004){
		ans[i]=((ans[i-1]-fib[i-1])*2)+fib[i-1];
	}
	while(scanf("%d",&n)!=EOF){
		cout<<ans[n]<<endl;
	}
	
}
