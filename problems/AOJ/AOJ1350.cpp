#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

/*
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1350>
 問題文============================================================
 
 最小全域木を構成する辺のうち、必ず、必要となる辺の総数及びコストの総和を求めよ
 
 =================================================================
 解説=============================================================
 
 最小全域木の辺のある辺を取り除いて、全域木を作った時、コストの総和が一致するか
 どうかで判定ができる
 
 ================================================================
 */

struct UnionFind {
    vector<int> data;
    UnionFind(int size) { init(size); }
    void init(int size) { data.clear(); data.resize(size, -1); }
    bool unite(int x, int y) {
        x = root(x); y = root(y);
        if (x != y) {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y]; data[y] = x;
        }
        return x != y;
    }
    bool same(int x, int y) {
        return root(x) == root(y);
    }
    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    int size(int x) {
        return -data[root(x)];
    }
};

struct edge {
    int u, v, cost;
    bool use;
    edge() {}
    edge(int u, int v, int cost, bool use = true) :u(u), v(v), cost(cost),use(use) {}
    bool operator<(const edge& o) const { return this->cost < o.cost; }
    bool operator>(const edge& o) const { return this->cost > o.cost; }
};

vector<ll> solve(){
    vector<ll> res{0,0};
    int N, M; cin >> N >> M;
    priority_queue<edge, vector<edge>, greater<edge>> pq;
    for (int i = 0; i < M; i++) {
        int u, v, c; cin >> u >> v >> c;
        u--; v--;
        pq.push(edge(u, v, c));
    }
    UnionFind UF(N);
    ll minCost = 0;
    vector<edge> edges1, edges2;
    while (pq.size()) {
        edge e = pq.top(); pq.pop();
        if (!UF.same(e.u, e.v)) {
            UF.unite(e.u, e.v);
            minCost += e.cost;
            edges1.push_back(e);
        }
        else {
            edges2.push_back(e);
        }
    }
    
    ll ans1 = 0;
    ll ans2 = 0;
    for (int i = 0; i < edges1.size(); i++) {
        UF.init(N);
        for (int j = 0; j < i; j++) pq.push(edges1[j]);
        for (int j = i + 1; j < edges1.size(); j++) pq.push(edges1[j]);
        
        for (edge e : edges2) pq.push(e);
        
        ll SumCost = 0;
        while (pq.size()) {
            edge e = pq.top(); pq.pop();
            if (!UF.same(e.u, e.v)) {
                UF.unite(e.u, e.v);
                SumCost += e.cost;
            }
        }
        
        if (UF.size(0) != N) {
            ans1++;
            ans2 += edges1[i].cost;
            continue;
        }
        
        if (SumCost > minCost) {
            ans1++;
            ans2 += edges1[i].cost;
            continue;
        }
    }
    res = vector<ll>{ans1,ans2};
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
