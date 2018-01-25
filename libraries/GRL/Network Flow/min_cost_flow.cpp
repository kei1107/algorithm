#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

struct Edge {
    //to : Edge(from -> to)   cap:capacity cost:cost   rev:reverse
    int to, cap, cost, rev;
    Edge(int to, int cap, int cost, int rev) :to(to), cap(cap), cost(cost), rev(rev) {}
};

#define P vector<vector<Edge>>
vector<int> dist;
bool bellman_ford(P& Graph, int s, int t, vector<int>& parent_v, vector<int>& parent_at) {
    dist = vector<int>(t + 1, INF);
    dist[s] = 0;
    for (int i = 0; i <= t;i++) {
        for (int v = 0; v <= t;v++) {
            if (dist[v] == INF)continue;
            for (int at = 0; at < Graph[v].size();at++) {
                Edge &e = Graph[v][at];
                if (e.cap > 0 && dist[e.to] > dist[v] + e.cost) {
                    //cout << i << " " << v << endl;
                    dist[e.to] = dist[v] + e.cost;
                    parent_v[e.to] = v;
                    parent_at[e.to] = at;
                    if (i == t) return false;
                }
            }
        }
    }
    return true;
}

int primal_dual(P& Graph, int s, int t, int F) {
    vector<int> parent_v(t + 1);
    vector<int> parent_at(t + 1);
    int min_cost_flow = 0;
    while (bellman_ford(Graph, s, t, parent_v, parent_at)) {
        if (dist[t] == INF) { return -1; }
        int path_flow = F;
        for (int v = t; v != s; v = parent_v[v]) {
            path_flow = min(path_flow, Graph[parent_v[v]][parent_at[v]].cap);
        }
        
        F -= path_flow;
        min_cost_flow += path_flow*dist[t];
        
        if (F == 0) { return min_cost_flow; }
        if (F < 0) { return -1; }
        
        for (int v = t; v != s; v = parent_v[v]) {
            Edge & e = Graph[parent_v[v]][parent_at[v]];
            e.cap -= path_flow;
            Graph[v][e.rev].cap += path_flow;
        }
    }
    return min_cost_flow;
}
int main() {
    int V, E, F; cin >> V >> E >> F;
    P G(V);
    for (int i = 0; i < E;i++) {
        int u, v, c, d; cin >> u >> v >> c >> d;
        G[u].emplace_back(Edge(v, c, d, G[v].size()));
        G[v].emplace_back(Edge(u, 0, -d, G[u].size() - 1));
    }
    cout << primal_dual(G, 0, V - 1, F) << endl;
    return 0;
}
