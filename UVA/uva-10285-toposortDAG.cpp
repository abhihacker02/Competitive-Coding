#include<bits/stdc++.h>
using namespace std;
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
#define mod 1000000007
#define mem(ar,x) memset(ar,x,sizeof ar)
#define present(container, element) (container.find(element) != container.end())
#define max3(a,b,c) return (lli(a)>lli(b)?(lli(a)>lli(c)?a:c):(lli(b)>lli(c)?b:c))
#define max4(a,b,c,d) return (max3(a,b,c)>lli(d)?(max3(a,b,c)):d)
#define min3(a,b,c) return (lli(a)<lli(b)?(lli(a)<lli(c)?a:c):(lli(b)<lli(c)?b:c))
#define min4(a,b,c,d) return (max3(a,b,c)<lli(d)?(max3(a,b,c)):d)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ll, ll> llp;
typedef pair<double, double> dd;
typedef pair<char, int> ci;
const int N=100005;
int dr8[]={0,0,1,-1,1,1,-1,-1};
int dc8[]={1,-1,0,0,-1,1,-1,1};
int dr4[]={0,1,-1,0};
int dc4[]={1,0,0,-1};
int t, r, c, i, j, num, tmp, ans;
int a[111][111];
char s[111];
vector<vector<ii> > adj;
vi dist, vis, topo;

void dfs(int u)
{
    vis[u]=1;
    for(int j=0;j<(int)adj[u].size();++j)
    {
        ii v=adj[u][j];
        if(!vis[v.first])
            dfs(v.first);
    }
    topo.push_back(u);
}

int main()
{
    dist.clear(), vis.clear();
    adj.clear(), adj.assign(111111, vector<ii>());
    dist.assign(111111, 0), vis.assign(111111, 0);
    scanf("%d", &t);
    while(t--)
    {
        s[0]='\0';
        scanf("%s %d %d", s, &r, &c);
        num=1;
        topo.clear();
        for(i=1;i<=r;++i)
            for(j=1;j<=c;++j)
                scanf("%d", &a[i][j]);
        for(i=1;i<=100000;++i)
            adj[i].clear();
        for(i=1;i<=r;++i)
            for(j=1;j<=c;++j)
            {
                if(j-1>=1 && a[i][j]>a[i][j-1])
                    adj[num].push_back(ii(num-1, -1));
                if(i-1>=1 && a[i][j]>a[i-1][j])
                    adj[num].push_back(ii(num-c, -1));
                if(j+1<=c && a[i][j]>a[i][j+1])
                    adj[num].push_back(ii(num+1, -1));
                if(i+1<=r && a[i][j]>a[i+1][j])
                    adj[num].push_back(ii(num+c, -1));
                ++num;
            }
        for(i=1;i<=100000;++i)
            dist[i]=1, vis[i]=0;
        for(i=1;i<num;++i)
            if(!vis[i])
                dfs(i);
        reverse(topo.begin(), topo.end());
        ans=1;
        for(i=0;i<(int)topo.size();++i)
        {
            int u=topo[i];
            for(j=0;j<(int)adj[u].size();++j)
            {
                ii v=adj[u][j];
                dist[v.first]=max(dist[v.first], dist[u]+1);
                ans=max(ans, dist[v.first]);
            }
        }
        printf("%s: %d\n", s, ans);
    }
    return 0;
}
