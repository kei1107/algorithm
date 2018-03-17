#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://abc075.contest.atcoder.jp/tasks/abc075_c>
問題文============================================================
 自己ループと二重辺を含まない N 頂点 M 辺の無向連結グラフが与えられます。
 i(1≦i≦M) 番目の辺は頂点 ai と頂点 bi を結びます。
 
 グラフから辺を取り除いたとき、グラフ全体が非連結になるような辺のことを橋と呼びます。
 与えられた M 本のうち橋である辺の本数を求めてください。
 
=================================================================

解説=============================================================
橋の判定
 
 lowlinkやるだけ
================================================================
*/
class Bridge {
public:
    vector<vector<int>> G;
    vector<int> ord, low;
    vector<pair<int, int>> bridges;
    int k;
    
    Bridge(int N):k(0) {
        G.resize(N); ord.resize(N, -1); low.resize(N, -1);
    }
    void clear() { G.clear();ord.clear();low.clear(); }
    void add_edge(int s, int t) {
        G[s].emplace_back(t);
        G[t].emplace_back(s);
    }
    
    bool is_bridge(int u, int v)const {
        if (ord[u] > ord[v])swap(u, v);
        return ord[u] < low[v];
    }
    
    /* Lowlink */
    void dfs(int u,int rev = -1) {
        ord[u] = low[u] = k;
        k++;
        for (auto v : G[u]) {
            if (v == rev)continue;
            if (ord[v] < 0) {
                dfs(v, u);
                low[u] = min(low[u], low[v]);
            }
            else {
                low[u] = min(low[u], ord[v]);
            }
            if (is_bridge(u, v)) {
                int s = u, t = v;
                if (s > t) swap(s, t);
                bridges.push_back({ s,t });
            }
        }
    }
    
    void solve() {
        dfs(0);
        sort(bridges.begin(), bridges.end());
    }
};
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    int N,M; cin >> N >> M;
    Bridge bridge(N);
    for(int i = 0; i < M;i++){
        int s,t; cin >> s >> t;
        bridge.add_edge(s-1,t-1);
    }
    bridge.solve();
    cout << bridge.bridges.size() << endl;
	return 0;
}
