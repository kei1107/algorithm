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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1595>
 問題文============================================================
 =================================================================
 解説=============================================================
 ある頂点を根とした時、答えは
 
 2*全ての辺の数 - 最も遠い葉の距離
 
 となる。
 ここで、最も遠い葉の候補は木の直径を作る2点のどちらかである。
 よって、先に直径を作る２点を求めておく。
 
 ここで、その２点を u,vとする
 uから全頂点の距離distを求めておく
 ある頂点iを見た時
 最も遠い葉の距離は max(dist[i],dist[i]+dist[v]-dist[iとvのLCA]*2)
 であるのでもとまる

 ================================================================
 */

struct edge{
    ll u,v,c;
    edge():u(0),v(0),c(0){}
    edge(ll u,ll v,ll c):u(u),v(v),c(c){}
};
typedef vector<vector<edge>> Graph;
Graph G;
class LCA{
public:
    const ll n = 0;
    const ll log2_n = 0;
    vector<vector<ll>> parent;
    vector<ll> depth;
    LCA();
    LCA(const Graph &g,ll root):n((ll)g.size()),log2_n(log2(n)+1),parent(log2_n,vector<ll>(n)),depth(n){
        dfs(g,root,-1,0);
        for(int k = 0; k+1 < log2_n; k++){
            for(int v = 0; v < (int)g.size();v++){
                if(parent[k][v] < 0) parent[k+1][v] = -1;
                else parent[k+1][v] = parent[k][parent[k][v]];
            }
        }
    }
    
    void dfs(const Graph &g,ll v,ll p,ll d){
        parent[0][v] = p; depth[v] = d;
        for(auto &e :g[v]){
            if(e.v != p) dfs(g, e.v, v, d+1);
        }
    }
    
    ll get(ll u,ll v){
        if(depth[u] > depth[v]) swap(u,v);
        for(int k = 0; k < log2_n; k++){
            if(((depth[v]-depth[u])>>k) & 1) v = parent[k][v];
        }
        if(u == v) return u;
        for(int k = (int)log2_n - 1; k >= 0; k--){
            if(parent[k][u] != parent[k][v]){
                u = parent[k][u]; v = parent[k][v];
            }
        }
        return parent[0][u];
    }
};

void solve(){
    ll n; cin >> n;
    vector<vector<edge>> T(n);
    for(int i = 0; i < n - 1;i++){
        ll s,t; cin >> s >> t;
        s--; t--;
        T[s].emplace_back(edge(s,t,1));
        T[t].emplace_back(edge(t,s,1));
    }
    ll v1,v2;
    vector<ll> dist(n,INF);
    queue<ll> q;
    dist[0] = 0;
    q.push(0);
    while(q.size()){
        ll next = q.front(); q.pop();
        for(auto e:T[next]){
            if(dist[e.v] > dist[e.u] + e.c){
                dist[e.v] = dist[e.u] + e.c;
                q.push(e.v);
            }
        }
    }
    v1 = max_element(dist.begin(), dist.end()) - dist.begin();

    fill(dist.begin(),dist.end(),INF);
    dist[v1] = 0;
    q.push(v1);
    while(q.size()){
        ll next = q.front(); q.pop();
        for(auto e:T[next]){
            if(dist[e.v] > dist[e.u] + e.c){
                dist[e.v] = dist[e.u] + e.c;
                q.push(e.v);
            }
        }
    }
    v2 = max_element(dist.begin(), dist.end()) - dist.begin();
    
    LCA lca(T,v1);
    ll V = 2*(n-1);
    for(int i = 0; i < n;i++){
        if(i == v2){
            cout << V - dist[v2] << endl;
            continue;
        }
        ll L = lca.get(i,v2);
        cout << V - max((dist[i]+dist[v2] - 2*dist[L]),dist[i]) << endl;
    }
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
