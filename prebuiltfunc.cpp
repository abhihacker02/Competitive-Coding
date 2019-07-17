//-Matrix exponentiation

#define DIM 26 // default to 2. Set value according to problem.
struct matrix{
  lli a[DIM][DIM];
	
	// constructor. Make an empty array.
	matrix() {
		memset(a, 0, sizeof(lli) * DIM * DIM);
	}
	
	// constant matrix (M). Set value according to problem.
	void unit_matrix() {
		a[0][0] = 26; a[0][1] = 52;
		a[1][0] = 0; a[1][1] = 1;
	}
	
	matrix operator* (matrix b) {
		matrix c;
		for (int k = 0; k < DIM; ++ k) { 
			for (int i = 0; i < DIM; ++i) {
				for (int j = 0; j < DIM; ++j) {
					c.a[i][j] = (c.a[i][j] + (a[i][k] * b.a[k][j])%mod) % mod;
				}
			}
		}
		return c;
	}
};
 
matrix pow_matrix(matrix a, lli n) {
	if (n <= 1) return a;
	
	matrix b = pow_matrix(a, n / 2);
	b = b * b;
	if (n & 1) b = b * a;
	
	return b;
}
//---------------------------------------------------

//factorial in logn-----------


long f(long n) {
	if (F.count(n)) return F[n];
	long k=n/2;
	if (n%2==0) { // n=2*k
		return F[n] = (f(k)*f(k) + f(k-1)*f(k-1)) % mod;
	} else { // n=2*k+1
		return F[n] = (f(k)*f(k+1) + f(k-1)*f(k)) % mod;
	}
}


//---------------



//most sig bi-----

int msb(unsigned x) {
	union { double a; int b[2]; };
	a = x;
	return (b[1] >> 20) - 1023;
}

//

//Union find algo

int root(int i)
{
    while(par[ i ] != i){
    	i = par[ i ];
    }
    return i;
}	
bool find(int A,int B)
{
    if( root(A)==root(B) )
    	return true;
    else
    	return false;
}
void initialize()
{
	for(int i = 0;i<=n;i++){
	par[ i ] = i ;
	size[ i ] = 1;
	}
}
void un(int A,int B)
{
    int root_A = root(A);
    int root_B = root(B);
    if(size[root_A] < size[root_B ]){
		par[ root_A ] = par[root_B];
		size[root_B] += size[root_A];
	}
    else{
		par[ root_B ] = par[root_A];
		size[root_A] += size[root_B];
	}
}
///---------------------

//Kruskal algo

	vector< pair<int, pii> > EdgeList; 
	for (int i = 0; i < m; i++){
		cin>>u>>v>>w;
		EdgeList.push_back(make_pair(w, pii(u, v))); 
	} 
	sort(EdgeList.begin(), EdgeList.end()); 
	int mst_cost = 0; 
	for (int i = 0; i < m; i++){
		pair<int, pii> front = EdgeList[i];
		if(!find(front.second.first, front.second.second)) { 
			mst_cost += front.first;
			un(front.second.first, front.second.second); 
		}	 
	}

//----------
//Z algo

void Zarr(string str) 
{ 
    int n = str.length(); 
    int L, R, k; 
    L = R = 0; 
    for (int i = 1; i < n; ++i) 
    {
        if (i > R) 
        { 
            L = R = i; 
            while (R<n && str[R-L] == str[R]) 
                R++; 
            Z[i] = R-L; 
            R--; 
        } 
        else
        { 
            k = i-L; 
            if (Z[k] < R-i+1) 
                Z[i] = Z[k]; 
            else
            { 
                L = i; 
                while (R<n && str[R-L] == str[R]) 
                    R++; 
                Z[i] = R-L; 
                R--; 
            } 
        } 
    } 
} 

//---------------

//checking subsequence
bool isSubSequence(string str1, string str2, int m, int n) 
{ 
   int m=str1.length();
   int n=str2.length();
   int j = 0; 
   for (int i=0; i<n&&j<m; i++) 
       if (str1[j] == str2[i]) 
         j++; 
  
   // If all characters of str1 were found in str2 
   return (j==m); 
} 
//-----------------


//finding primes less than a number

lli sq=sqrt(n)+2;
for(int i=2;i<=sq;i++){
	if(n%i==0){
		prime.pb(i);
		while(n%i==0){
			n=n/i;
		}
	}
	if(n==1) break;
}
if(n!=1) prime.pb(n);

//--------------
//NCR table-----------------

int NcR() {
    for (int i = 2; i < 5002; i++)
    {
        int val = 1;
        for (int k = 0; k <= i; k++)
        {
            if(k==0||k==i) dp[i][k]=1;
            else{
                dp[i][k]=(1ll*dp[i-1][k-1]+dp[i-1][k])%mod;
            }
        }
    }
}

//---------------------------
//Lazy Propagation-------------------------------

void build(int node, int start, int end)
{
    if(start == end)
    {
        // Leaf node will have a single element
        tree[node] = A[start];
    }
    else
    {
        int mid = (start + end) / 2;
        // Recurse on the left child
        build(2*node, start, mid);
        // Recurse on the right child
        build(2*node+1, mid+1, end);
        // Internal node will have the sum of both of its children
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

void updateRange(int node, int start, int end, int l, int r, int val)
{
    if(lazy[node] != 0)
    { 
        // This node needs to be updated
        tree[node] += (end - start + 1) * lazy[node];    // Update it
        if(start != end)
        {
            lazy[node*2] += lazy[node];                  // Mark child as lazy
            lazy[node*2+1] += lazy[node];                // Mark child as lazy
        }
        lazy[node] = 0;                                  // Reset it
    }
    if(start > end or start > r or end < l)              // Current segment is not within range [l, r]
        return;
    if(start >= l and end <= r)
    {
        // Segment is fully within range
        tree[node] += (end - start + 1) * val;
        if(start != end)
        {
            // Not leaf node
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }
    int mid = (start + end) / 2;
    updateRange(node*2, start, mid, l, r, val);        // Updating left child
    updateRange(node*2 + 1, mid + 1, end, l, r, val);   // Updating right child
    tree[node] = tree[node*2] + tree[node*2+1];        // Updating root with max value 
}

int queryRange(int node, int start, int end, int l, int r)
{
    if(start > end or start > r or end < l)
        return 0;         // Out of range
    if(lazy[node] != 0)
    {
        // This node needs to be updated
        tree[node] += (end - start + 1) * lazy[node];            // Update it
        if(start != end)
        {
            lazy[node*2] += lazy[node];         // Mark child as lazy
            lazy[node*2+1] += lazy[node];    // Mark child as lazy
        }
        lazy[node] = 0;                 // Reset it
    }
    if(start >= l and end <= r)             // Current segment is totally within range [l, r]
        return tree[node];
    int mid = (start + end) / 2;
    int p1 = queryRange(node*2, start, mid, l, r);         // Query left child
    int p2 = queryRange(node*2 + 1, mid + 1, end, l, r); // Query right child
    return (p1 + p2);
}
//---------------------------------------------

//GCD---------------------

lli gcd (lli a, lli b) {
  lli r, i;
  while(b!=0){
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}

//--------------------------
//ALL FACTORS OF A NUMBER-------------------------------------------------------------------

int square_root = (int) sqrt(num) + 1;
for (int i = 1; i < square_root; i++) { 
    if (num % i == 0&&i*i!=num)
        cout << i << num/i << endl;
    if (num % i == 0&&i*i==num)
        cout << i << '\n';
}

//----------------------------------------------------------------------------
//Fermats theorem---------------------------------------------------------------
int power(int x, int y, int p)
{
    int res = 1;   
    x = x % p; 
    while (y > 0)
    {
        if (y & 1)
            res = (1LL*res*x) % p;
 
        y = y>>1;
        x = (1LL*x*x) % p;
    }
    return res;
}
 
// Returns n^(-1) mod p
int modInverse(int n, int p)
{
    return power(n, p-2, p);
}
 
// Returns nCr % p using Fermat's little
// theorem.
int nCrModPFermat(int n, int r, int p)
{
   // Base case
   if (r==0)
      return 1;
 
    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
    int fac[n+1];
    fac[0] = 1;
    for (int i=1 ; i<=n; i++)
        fac[i] = fac[i-1]*i%p;
 
    return (fac[n]* modInverse(fac[r], p) % p *
            modInverse(fac[n-r], p) % p) % p;
}

//------------------------------------------------------------------------------


//SIEVE OF PRIMES---------------------------------------------------------------------

void SieveOfEratosthenes(int n)
{
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
 
    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true){
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
}

//----------------------------------------------------------------------------------

//FIBONACCI--------------------------------------------------------------------------

void fibo(int k){
	fib[0]=0;fib[1]=1;
	FOR(2,k){
		fib[i]=fib[i-1]+fib[i-2];
	}
}

//------------------------------------------------------------------------------------

//DIJKSTRA--------------------------------------------------------------------------------

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
      
//-----------------------------------------------------------------------------------

//RSQ---------------------------------------------------------------------------------

void build(int node,int l,int r){
	if(l==r) {
		tree[node]=a[l];return;
	}
	int mid=(l+r)/2;
	build(2*node,l,mid);
	build((2*node)+1,mid+1,r);
	tree[node]=tree[2*node]+tree[(2*node)+1];
}
void upd(int node,int in,int val,int l,int r){
	tree[node]+=val-a[in];
	if(l==r){
		tree[node]=val;
		a[in]=val;
		return ;
	}
	int mid=(l+r)/2;
	if(in<=mid){
		upd((node*2),in,val,l,mid);
	}
	else{
		upd((node*2)+1,in,val,mid+1,r);
	}
}
int query(int node,int ql,int qr,int l,int r){
	if(qr<l||ql>r) return 0;
	if(ql<=l&&qr>=r) return tree[node];
	int mid=(l+r)/2;
	return (query((2*node),ql,qr,l,mid)+query((2*node)+1,ql,qr,mid+1,r));
}

//-----------------------------------------------------------------------------------

//SOS DP==(DP+Bitmask)---------------------------------------------------------------

for(int i = 0; i<(1<<N); ++i)
	F[i] = A[i];
for(int i = 0;i < N; ++i) for(int mask = 0; mask < (1<<N); ++mask){
	if(mask & (1<<i))
		F[mask] += F[mask^(1<<i)];
}

//--------------------------------------------------------------------

//DFS----------------------------------------------------------------------------------

void dfs(int u){
	vis[u]=1;
	for(int i=0;i<gr[u].size();i++){
		int v=gr[u][i];
		if(!vis[v]){
			dfs(v);
		}
	}
}

//-----------------------------------------------------------------------------------
