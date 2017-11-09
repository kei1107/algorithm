#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
 <url:https://www.ioi-jp.org/camp/2007/2007-sp-tasks/2007-sp-day4_24.pdf>
 問題文============================================================
 
 複数のグラフが与えられる。
 全てのグラフを一つにするには幾つの辺を追加すればいいのか？
 =================================================================
 解説=============================================================
 
 unionfind
 内部集合の個数-1　が答え
 
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

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    int n; cin >> n;
    UnionFind uf(n);
    
    int m; cin >> m;
    for(int i = 0; i < m;i++){
        int s,t; cin >> s >> t;
        s--; t--;
        uf.unite(s, t);
    }
    cout << uf.count() - 1 << endl;
    return 0;
}
