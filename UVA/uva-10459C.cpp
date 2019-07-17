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
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<int,pii>ppii;
typedef vector<int>vi;
typedef vector<vi>vvi;
typedef vector<pii>vpii;
const int N=100005;
int dr8[]={0,0,1,-1,1,1,-1,-1};
int dc8[]={1,-1,0,0,-1,1,-1,1};
int dr4[]={0,1,-1,0};
int dc4[]={1,0,0,-1};
void DFS(int node, const vector<vector<int> > &adj_list,
         vector<bool> &visited, 
         int len, int &long_dist, int start, vector<int> &path,
         set<int> &best, set<int> &worst) {
    path.push_back(node);
    visited[node] = true;

    if (len > long_dist) {
        best.clear();
        worst.clear();

        long_dist = len;
    }

    if (len == long_dist) {
        worst.insert(node);
        worst.insert(start);

        if (len % 2 == 0)
            best.insert(path[len / 2]);
        else {
            best.insert(path[len / 2]);
            best.insert(path[len / 2 + 1]);
        }
    }

    for (int dest : adj_list[node])
        if (!visited[dest]) {
            DFS(dest, adj_list, visited, len + 1, long_dist,
                start, path, best, worst);
        }

    visited[node] = false;
    path.pop_back();
}

int main() {
    int N;
    while (scanf("%d", &N) == 1) {
        vector<vector<int>> adj_list(N);
        for (int i = 0; i < N; i++) {
            int K;
            scanf("%d", &K);
            for (int j = 0; j < K; j++) {
                int node;
                scanf("%d", &node);
                adj_list[i].push_back(node - 1);
            }
        }

        vector<bool> visited(N, false);

        queue<pair<int, int>> q;
        visited[0] = true;
        q.push({0, 0});
        int long_dist = 0;
        
        int potential = 0;
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            int u = front.first;
            int len = front.second;
            if (len > long_dist) {
                long_dist = len;
                potential = u;
            }

            for (int v : adj_list[u])
                if (!visited[v]) {
                    visited[v] = true;
                    q.push({v, len + 1});
                }
        }


        visited.assign(N, false);
        vector<int> path;
        
        set<int> best, worst;

        DFS(potential, adj_list, visited, 0,
            long_dist, potential, path, best, worst);

        for (int node : worst)
            if (node != potential) {
                potential = node;
                break;
            }

        visited.assign(N, false);
        path.clear();
        DFS(potential, adj_list, visited, 0,
            long_dist, potential, path, best, worst);


        printf("Best Roots  :");
        for (int root : best)
            printf(" %d", root + 1);
        printf("\n");

        printf("Worst Roots :");
        for (int root : worst)
            printf(" %d", root + 1);
        printf("\n");
    }
    return 0;
}
