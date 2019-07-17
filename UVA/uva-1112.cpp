#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector <ii> vii;
typedef vector <int> vi;
#define INF 1000000000


void dijkstra(int s, vi *dist, vector<vii> *graph){
    priority_queue< ii, vector<ii>, greater<ii> > pq; 
    pq.push(ii(0, s));
    while (!pq.empty()) {
        ii front = pq.top(); 
        pq.pop();
        int d = front.first, u = front.second;
        if (d == dist->at(u))
            for (int j = 0; j < (int)graph->at(u).size(); j++) {
                ii v = graph->at(u)[j];                       // all outgoing edges from u
                if (dist->at(u) + v.second < dist->at(v.first)) {
                    dist->at(v.first) = dist->at(u) + v.second;                 // relax operation
                    pq.push(ii(dist->at(v.first), v.first));
                }
            } 
    }
}

int main(){
    string st;int N,cases=1;scanf("%d",&N);
    getline(cin,st);
    while(N--){
    	//if(N>0) getline(cin,s);
        int n,m,s,t,c=0;
        scanf("%d %d %d %d",&n,&s,&t,&m);
        vector<vii> graph (n,vii());
        int u,v,w;
        for (int i = 0; i < m; ++i)
        {
            scanf("%d %d %d", &u, &v, &w);
            //"connected by a bidirectional cable"
            graph[u-1].push_back(ii(v-1, w)); 
            //graph[v].push_back(ii(u, w));
        }
        for(int i=1;i<=n;i++){
        vi dist(n, INF);
        dist[i-1] = 0;
        if(i-1!=s-1)
        dijkstra(i-1,&dist,&graph);
        if(dist[s-1]<=t) c++;}
        if(N>0) printf("%d\n\n",c);
        else printf("%d",c);
        if(N>0) getline(cin,st);
    }


 return 0;   

}
