#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
 <url:https://www.ioi-jp.org/camp/2010/2010-sp-tasks/2010-sp-day3_22.pdf>
 問題文============================================================
 N(1<=N<=10^5)頂点及びM(1<=N<=10^5)辺の無向グラフが与えられる
 このうち任意のK(1<=K<=N)個の頂点を定め、全ての頂点がそのK個の頂点のいづれかに
 到達できるようにするのに必要な無向グラフの辺のコストの総和の最小値を求める
 =================================================================
 解説=============================================================
 
 UnionFindで最小木を生成していく、その時、unionFind内部の集合の数がK個になれば
 その時までに用いた辺のコストが答え
 
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

struct edge{
    int u;
    int v;
    int cost;
    edge(){}
    edge(int u,int v,int c):u(u),v(v),cost(c){}
    bool operator < (const edge& o) const{
        return cost < o.cost;
    }
};

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll N,M,K; cin >> N >> M >> K;
    vector<edge> E;
    for(int i = 0; i < M;i++){
        ll u,v,c; cin >> u >> v >> c;
        u--; v--;
        E.push_back(edge(u,v,c));
    }
    sort(E.begin(),E.end());
    
    UnionFind uf(N);
    ll res = 0;
    for(int i = 0;i < M;i++){
        if(uf.count() == K)break;
        if(uf.same(E[i].u,E[i].v)) continue;
        uf.unite(E[i].u,E[i].v);
        res += E[i].cost;
    }
    cout << res << endl;
    return 0;
}
