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

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll V, E; cin >> V >> E;
    UnionFind uf(V);
    priority_queue<edge,vector<edge>,greater<edge> > G;
    for (int i = 0; i < E;i++) {
        ll s, t, w; cin >> s >> t >> w;
        s--; t--;
        G.push(edge(s, t, w));
    }
    ll ans = 0;
    while (!G.empty()) {
        edge e = G.top(); G.pop();
        if (uf.same(e.u, e.v)) continue;
        uf.unite(e.u, e.v);
        ans = max(ans,e.cost);
    }
    cout << ans << endl;
    return 0;
}
