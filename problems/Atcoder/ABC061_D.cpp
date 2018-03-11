#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://abc061.contest.atcoder.jp/tasks/abc061_d>
問題文============================================================
 N 頂点 M 辺の重み付き有向グラフがあります。
 i(1≦i≦M) 番目の辺は 頂点 ai から 頂点 bi を重み ci で結びます。
 このグラフと駒を利用して、次の1人ゲームを行います。
 
 最初、駒を頂点 1 に置いて、プレイヤーのスコアを 0 とします。
 プレイヤーは、次の条件で駒を繰り返し移動させることができます。
 
 頂点 ai に駒があるとき、i 番目の辺を利用して頂点 bi に移動する。移動後にプレイヤーのスコアが ci 加算される。
 
 頂点 N に駒があるときのみ、ゲームを終了できます。
 なお、与えられる有向グラフの上で頂点 1 から頂点 N に移動できることは保障されています。
 
 プレイヤーがゲーム終了時のスコアを出来るだけ大きくするような行動を取ったとき、ゲーム終了時のスコアはいくつになるでしょうか?
 ゲーム終了時のスコアをいくらでも大きくできる場合は inf と出力してください。
=================================================================

解説=============================================================
 
 ベルマンフォード法
 
 コストの符号を反転させた値を辺とすれば、ゲーム終了のスコアが特定の値になる場合は
 その答えは -1 * dist[0->V-1] となる。
 
 ゲーム終了時のスコアをいくらでも大きくできる場合に関して、
 閉路が0 -> V-1 へのルートに関係ない部分でできる場合があるので、その判定に注意
 
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
                        if (i == V - 1 && e.v == V-1) return true; // 負閉路
                    }
                }
            }
            if(updated) return false;
        }
        return false;
    }
    
    inline ll get_dist(ll v) const { return dist[v]; }
};
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N,M; cin >> N >> M;
    Bellman_ford Bf(N);
    for(int i = 0; i < M;i++){
        ll a,b,c; cin >> a >> b >> c; a--; b--;
        Bf.add_edge(a, b, -c);
    }
    
    if(Bf.calc_dist(0)){
        cout << "inf" << endl;
    }else{
        cout << -Bf.get_dist(N-1) << endl;
    }
	return 0;
}
