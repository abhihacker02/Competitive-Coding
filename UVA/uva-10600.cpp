#include <string.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>


using namespace std;

#define FOR( i, L, U ) for(int i=(int)L ; i<=(int)U ; i++ )
#define FORD( i, U, L ) for(int i=(int)U ; i>=(int)L ; i-- )
#define SQR(x) ((x)*(x))

#define INF INT_MAX


#define READ(filename)  freopen(filename, "r", stdin);
#define WRITE(filename)  freopen(filename, "w", stdout);

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<vector<int> > vvi;
typedef vector<vector<int> > vvc;
typedef map<int, int> mii;
typedef map<string, int> msi;
typedef map<int, string> mis;
typedef map<string, string> mss;
typedef map<string, char> msc;

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define MAX_EDGES 1000000
#define MAX_NODES 101
struct Edge{
    int  st;
    int en;
    int w;
} ;
vi second;
Edge edge[MAX_EDGES];
bool inmst[MAX_EDGES];
int nodes,edges;
int pre[MAX_NODES];
bool comp(Edge a,Edge b){
    return a.w < b.w;
}
int findPre(int u){
    if(pre[u]==u)return u;
    else return pre[u] = findPre(pre[u]);
}
void resetPre(){
    for(int i=0;i<=nodes;i++)pre[i] = i;
}
void secondMST(int offEdge){
    int takenEdges=0,smstw=0;
    resetPre();
    for(int i=0;i<edges;i++){
            int stp,enp;
            stp = findPre(edge[i].st);
            enp = findPre(edge[i].en);
            if(stp!=enp && i!=offEdge){
                smstw +=edge[i].w;
                pre[stp] = enp;
                takenEdges++;
            }
        }
  if(takenEdges==nodes-1)  second.push_back(smstw);
}
int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int i,takenEdges,test,cs=0;
    int mstw;
    scanf("%d", &test);
    while(test--){
        scanf("%d %d", &nodes, &edges);
        for(i=0;i<edges;i++){
            scanf("%d %d %d", &edge[i].st, &edge[i].en, &edge[i].w);
            inmst[i] = false;
        }
        sort(edge,edge+edges,comp);
        resetPre();
        mstw = 0;

        for(i=0;i<edges;i++){
            int stp,enp;
            stp = findPre(edge[i].st);
            enp = findPre(edge[i].en);
            if(stp!=enp){
                mstw +=edge[i].w;
                pre[stp] = enp;
                inmst[i]=true;
            }
        }

        second.clear();
        for(i=0;i<edges;i++)
            if(inmst[i])
                secondMST(i);

        sort(second.begin(),second.end());
        printf("%d %d\n", mstw, second[0]);

    }
	return 0;
}
