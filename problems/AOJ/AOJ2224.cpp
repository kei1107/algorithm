#include "bits/stdc++.h"
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
 
 ================================================================
 */

struct UnionFind {
    vector<int> par;
    int n, cnt;
    UnionFind(const int& x = 0) { init(x); }
    void init(const int& x) { par.assign(cnt = n = x, -1); }
    inline int find(const int& x) { return par[x] < 0 ? x : par[x] = find(par[x]); }
    inline bool same(const int& x, const int& y) { return find(x) == find(y); }
    inline bool unite(int x, int y) {
        if ((x = find(x)) == (y = find(y))) return false;
        --cnt;
        if (par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    inline int count() const { return cnt; }
    inline int count(int x) { return -par[find(x)]; }
};

struct edge {
    ll u;
    ll v;
    ll cost;
    edge() {}
    edge(ll u, ll v, ll c) :u(u), v(v), cost(c) {}
    bool operator < (const edge& o) const {
        return cost < o.cost;
    }
    bool operator > (const edge& o)const {
        return cost > o.cost;
    }
};
ll hyp(ll x1,ll y1,ll x2,ll y2){
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll V, E; cin >> V >> E;
    UnionFind uf(V);
    vector<pll> ps(V);
    for(auto& in:ps){
        cin >> in.first >> in.second;
    }
    priority_queue<edge> G;
    double all_sum = 0;
    for (int i = 0; i < E;i++) {
        ll s, t, w; cin >> s >> t;
        s--; t--;
        w = hyp(ps[s].first,ps[s].second,ps[t].first,ps[t].second);
        all_sum += sqrt(w);
        G.push(edge(s, t, w));
    }
    double sum = 0;
    while (!G.empty()) {
        auto e = G.top(); G.pop();
        if (uf.same(e.u, e.v)) continue;
        uf.unite(e.u, e.v);
        sum += sqrt(e.cost);
    }
 //   cout << sum << " " << all_sum << endl;
    cout << fixed << setprecision(10) << all_sum - sum << endl;
    return 0;
}
