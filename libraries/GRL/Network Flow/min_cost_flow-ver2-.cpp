#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60
#define MAX_V 100000

struct edge{
    int to;
    int cap;
    int cost;
    int rev;
    edge(){}
    edge(int to,int cap,int cost,int rev):to(to),cap(cap),cost(cost),rev(rev){}
};

int V;
vector<edge> G[MAX_V];
int dist[MAX_V];
int prevv[MAX_V],preve[MAX_V];

void add_edge(int from,int to,int cap,int cost){
    G[from].push_back(edge(to,cap,cost,(int)G[to].size()));
    G[to].push_back(edge(from,0,-cost,(int)G[from].size()-1));
}

int min_cost_flow(int s,int t,int f){
    int res=0;
    while(f>0){
        fill(dist,dist+V,INF);
        dist[s]=0;
        bool update = true;
        while(update){
            update = false;
            for(int v=0; v<V ;v++){
                if(dist[v]==INF) continue;
                for(int i=0; i<G[v].size(); i++){
                    edge &e = G[v][i];
                    if(e.cap > 0 && dist[e.to] > dist[v]+e.cost) {
                        dist[e.to] = dist[v] + e.cost;
                        prevv[e.to] = v;
                        preve[e.to] = i;
                        update = true;
                    }
                }
            }
        }
        if(dist[t]==INF) return -1;
        
        int d = f;
        for(int v=t; v!=s; v=prevv[v])d=min(d,G[prevv[v]][preve[v]].cap);
        f -= d;
        res += d*dist[t];
        for(int v=t; v!=s; v=prevv[v]){
            edge &e = G[prevv[v]][preve[v]];
            e.cap -= d;
            G[v][e.rev].cap += d;
        }
    }
    return res;
}

int main() {
    int E, F; cin >> V >> E >> F;
    for (int i = 0; i < E;i++) {
        int u, v, c, d; cin >> u >> v >> c >> d;
        add_edge(u,v,c,d);
    }
    cout << min_cost_flow(0,V-1,F) << endl;
    return 0;
}
