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
 <url:http://poj.org/problem?id=1258>
 問題文============================================================
 N 個の農場を光ファイバーで繋ぐ． ある農場と別の農場を繋ぐのに必要なコストが与えられる．
 
 どの農場から別のどの農場への経路が存在するように繋いだとき，それに必要な最小のコストを答える．
 

 =================================================================
 
 解説=============================================================
 最小全域木やるだけ
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
    int N;
    while(cin >> N){
        UnionFind uf(N);
        priority_queue<edge,vector<edge>,greater<edge> > G;
        for(int i = 0; i < N;i++){
            for(int j = 0; j < N;j++){
                ll cost; cin >> cost;
                G.push(edge(i,j,cost));
            }
        }
        ll ans = 0;
        while (!G.empty()) {
            edge e = G.top(); G.pop();
            if (uf.same(e.u, e.v)) continue;
            uf.unite(e.u, e.v);
            ans += e.cost;
        }
        cout << ans << endl;
    }
    return 0;
}
