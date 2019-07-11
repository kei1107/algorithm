#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
 LCA V1
 */
class LCA{
public:
    ll V; // 頂点数
    vector<vector<ll>> T; // Tree
    vector<pll> ET; // Euler Tour ET(dep, n)
    vector<int> visited;
    vector<ll> Ind; // 各頂点に対応するETのindexを保持
    
    ll N; // SegTreeの要素数
    vector<pll> node; // SegTree
    
    LCA(ll V):V(V){
        T.resize(V); Ind.resize(V);
    }
    
    void add_edge(ll u,ll v){
        T[u].emplace_back(v);
        T[v].emplace_back(u);
    }
    
    void fit(ll root){
        visited.clear(); visited.assign(V,0);
        dfs(root,0);
        ll N_ = ET.size();
        N = 1;
        while(N < N_) N*=2;
        node.clear(); node.assign(2*N - 1,make_pair(INF,INF));
        for(int i = 0; i < N_;i++) node[N-1+i] = ET[i];
        for(ll k = N - 2; k>=0;k--) node[k] = min(node[2*k+1],node[2*k+2]);
    }
    
    void dfs(ll n,ll dep){
        visited[n] = 1;
        ET.emplace_back(make_pair(dep, n));
        Ind[n] = (int)ET.size() - 1;
        for(auto next:T[n]){
            if(visited[next] == 1)continue;
            dfs(next,dep +1);
            ET.emplace_back(make_pair(dep,n));
        }
    }
    
    
    pll RMQ(ll a,ll b){ return RMQ(a,b,0,0,N); }
    pll RMQ(ll a,ll b,ll k,ll l, ll r){
        if(r <= a || b <= l)return make_pair(INF,INF);
        if(a <= l && r <= b)return node[k];
        auto vl = RMQ(a,b,2*k+1,l,(l+r)/2);
        auto vr = RMQ(a,b,2*k+2,(l+r)/2,r);
        return min(vl,vr);
    }
    
    ll query(ll s,ll t){
        ll idx1 = Ind[s],idx2 = Ind[t];
        if(idx1 > idx2) swap(idx1,idx2);
        
        return RMQ(idx1,idx2+1).second;
    }
};

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n; cin >> n;
    
    LCA lca(n);
    
    for(int i = 0; i < n;i++){
        ll k; cin >> k;
        for(int j = 0; j < k;j++){
            ll c; cin >> c;
            lca.add_edge(i, c);
        }
    }
    
    lca.fit();
    
    ll q; cin >> q;
    for(int i = 0; i < q;i++){
        ll u, v; cin >> u >> v;
        cout << lca.query(u,v) << endl;
    }
    return 0;
}



// ================================== //

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream &operator << (ostream& out,const pair<S,T>& o){
    out << "(" << o.first << "," << o.second << ")"; return out;
}

/*
 LCA V2
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

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C&lang=jp
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n; cin >> n;
    G.resize(n);
    for(int i = 0; i < n;i++){
        ll k; cin >> k;
        for(int j = 0; j < k;j++){
            ll c; cin >> c;
            G[i].push_back(edge(i,c,0));
            G[c].push_back(edge(c,i,0));
        }
    }
    LCA lca(G,0);
    ll q; cin >> q;
    while(q--){
        ll u,v; cin >> u >> v;
        cout << lca.get(u,v) << endl;
    }
    return 0;
}

