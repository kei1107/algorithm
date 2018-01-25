#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define INF 1<<30
#define LINF 1LL<<60

class WarshallFloyd{
public:
    ll V;
    vector<vector<ll>> d;
    WarshallFloyd(ll V):V(V){
        d.assign(V, vector<ll>(V,LINF));
        for(int i = 0; i < V;i++){
            d[i][i] = 0;
        }
    }
    
    void add_edge(ll u,ll v,ll cost,bool undirected = false){
        d[u][v] = min(d[u][v],cost);
        if(undirected){
            d[v][u] = min(d[v][u],cost);
        }
    }
    
    void calc(){
        for (int i = 0; i < V; i++)      // 経由する頂点
            for (int j = 0; j < V; j++)    // 開始頂点
                for (int k = 0; k < V; k++)  // 終端
                {
                    if(d[j][i] == LINF || d[i][k] == LINF)continue; // 負辺対策
                    d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
                }
    }
    
    inline ll get_dist(ll s,ll t) const {return d[s][t];} // // 負閉路 := d[i][i] < 0
};

