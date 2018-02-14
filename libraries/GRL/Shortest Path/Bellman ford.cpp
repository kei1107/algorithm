#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define INF 1<<30
#define LINF 1LL<<60

class Bellman_ford {
public:
    struct edge {
        ll u;
        ll v;
        ll cost;
        edge() {}
        edge(ll u, ll v, ll c) :u(u), v(v), cost(c) {}
    };
    
    ll V;
    vector<vector<edge> > G;
    vector<ll> dist;
    Bellman_ford(ll V) :V(V) {
        G.resize(V);
    }
    
    void add_edge(ll u, ll v, ll cost, bool undirected = false) {
        G[u].push_back(edge(u, v, cost));
        if (undirected) {
            G[v].push_back(edge(v, u, cost));
        }
    }
    
    bool calc_dist(ll s) {
        dist.assign(V,LINF);
        dist[s] = 0;
        
        for (int i = 0; i < V;i++) {
            bool updated = true;
            for (int v = 0; v < V;v++) {
                for (int j = 0; j < (int)G[v].size();j++){
                    edge& e = G[v][j];
                    if (dist[e.v] > dist[v] + e.cost) {
                        dist[e.v] = dist[v] + e.cost;
                        updated = false;
                        if (i == V - 1) return true; // 負閉路
                    }
                }
            }
            if(updated) return false;
        }
        return false;
    }
    
    inline ll get_dist(ll v) const { return dist[v]; }
};
