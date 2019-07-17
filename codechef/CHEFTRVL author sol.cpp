#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;

#define pb push_back
#define mp make_pair
#define eb emplace_back
#define mt make_tuple
#define f first
#define s second

#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

template<typename T1, typename T2> inline bool upmax(T1& a, T2 b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T1, typename T2> inline bool upmin(T1& a, T2 b) { if (b < a) { a = b; return 1; } return 0; }

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

// const int INF = (int)2e9;
const int maxn = 2e5 + 5;

void gen(vector<vector<int> > & g, vector<int> & a) {
    int n = rand() % 10 + 1;
    g.resize(n);
    a.resize(n);

    for (int i = 1; i < n; i++) {
        int u = rand() % i;
        g[u].pb(i);
        g[i].pb(u);
    }
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100;
    }
}

long long dp[maxn][2][2], ans;

void dfs(int v, int p, const vector<vector<int> >& g, const vector<int>& a) {
    dp[v][a[v]][0] = 1;
    for (int to : g[v]) {
        if (to != p) {
            dfs(to, v, g, a);
            rep(a_to, 0, 2)
                rep(d_to, 0, 2) 
                    rep(a_v, 0, 2)
                        rep(d_v, 0, 2) {
                            if ((a_to ^ d_to ^ a_v ^ d_v) == 1) {
                                ans += dp[v][a_v][d_v] * dp[to][a_to][d_to ^ 1];
                            }
                        }
            rep(a_to, 0, 2)
                rep(d_to, 0, 2) {
                    dp[v][a_to][d_to ^ 1] += dp[to][a_to][d_to];
                }
        }
    }
}

long long solve(int n, const vector<vector<int> >& g, const vector<int>& a) {
    vector<int> b(n);

    for (int i = 0; i < n; i++) {
        b[i] = __builtin_popcount(a[i]) % 2;
        dp[i][0][0] = dp[i][0][1] = dp[i][1][0] = dp[i][1][1] = 0;
    }

    ans = 0;
    dfs(0, -1, g, b);
    return ans;
}

int depth[maxn];

void calc(int v, int p, const vector<vector<int> > & g) {
    for (int to : g[v]) {
        if (to != p) {
            depth[to] = depth[v] ^ 1;
            calc(to, v, g);
        }
    }
}

long long brute(int n, const vector<vector<int> >& g, const vector<int>& a) {
    long long ans = 0;
    depth[0] = 0;
    calc(0, -1, g);
    rep(i, 0, n)
        rep(j, 0, n)
            if (i <= j && __builtin_popcount(a[i] ^ a[j]) % 2 != (depth[i] ^ depth[j]))
                ans += 1;
    return ans;
}

int main() {
    bool stress = 0;

    if (stress) {
        srand(time(0));
        for (int it = 0; it < 10000; it++) {
            vector<vector<int> > g;
            vector<int> a;
            gen(g, a);

            // cerr << g.size() - a.size() << endl;

            if (solve(a.size(), g, a) != brute(a.size(), g, a)) {
                cout << a.size() << endl;
                for (int i = 0; i < g.size(); i++)
                    for (auto e : g[i])
                        if (e < i)
                            cout << e + 1 << ' ' << i + 1 << endl;
                for (auto e : a)
                    cout << e << ' ';
                return 228;
            }
        }
        cout << "ok";
    } else {
        // freopen("input.txt", "r", stdin);
        int n;
        ios_base::sync_with_stdio(0);
        
        int t;
        cin >> t;
        
        for (int i = 0; i < t; i++) {
            
            cin >> n;
    
            vector<vector<int> > g(n);
            vector<int> a(n);
    
            rep(i, 0, n - 1) {
                int u, v;
                cin >> u >> v;
                u--, v--;
                // cout << g.size();
                g[u].pb(v);
                g[v].pb(u);
                // exit(0);
            }
    
            rep(i, 0, n) {
                cin >> a[i];
            }
    
            cout << solve(n, g, a) << "\n";
        }
        return 0;
    }
}
