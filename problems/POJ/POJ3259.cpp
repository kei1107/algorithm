#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <bitset>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <numeric>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <deque>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
 <url:>
 問題文============================================================
 
 =================================================================
 
 解説=============================================================
 負閉路検出
 ================================================================
 */

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
        dist.assign(V, INF);
        dist[s] = 0;
        
        for (int i = 0; i < V;i++) {
            for (int v = 0; v < V;v++) {
                for(int k = 0; k < (int)G[v].size();k++){
                    if (dist[v] != INF && dist[G[v][k].v] > dist[v] + G[v][k].cost) {
                        dist[G[v][k].v] = dist[v] + G[v][k].cost;
                        if (i == V - 1) return true;
                    }
                }
            }
        }
        return false;
    }
    
    inline ll get_dist(ll v) const { return dist[v]; }
};
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll F; cin >> F;
    for(int f = 0; f < F;f++){
        ll N,M,W; cin >> N >> M >> W;
        Bellman_ford Bf(N);
        for(int i = 0; i < M;i++){
            ll s,e,t; cin >> s >> e >> t;
            s--; e--;
            Bf.add_edge(s, e, t,true);
        }
        for(int i = 0; i < W;i++){
            ll s,e,t; cin >> s >> e >> t;
            s--; e--;
            Bf.add_edge(s, e, -t,false);
        }
        cout << (Bf.calc_dist(0)?"YES":"NO") << endl;
    }
    return 0;
}
