#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

/*
 <url:https://yukicoder.me/problems/no/363>
 問題文============================================================
 =================================================================
 解説=============================================================
 ref : https://drive.google.com/file/d/0B8GpBQ5LDTd6QjZIY1VUckxWZ0U/view
 
 p-u ,p-vが門松列になっているかを判定する部分は事前に頂点uから親方向に門松列が
 いくつ続くかをdfsで求めた方がラク
 ================================================================
 */


map<ll,ll> A;
bool isKadomatsu(ll a,ll b,ll c){
    if(a == 0 || b == 0 || c == 0) return false;
    if(a == b || b == c || c == a) return false;
    if(a > b && c > b) return true;
    if(a < b && c < b) return true;
    return false;
}
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
    ll get_parent(ll v,ll d){
        for(int k = 0; k < log2_n; k++){
            if((d>>k) & 1) v = parent[k][v];
        }
        return v;
    }
};

vector<vector<int>> tG;
vector<int> checked;
void make_tree(int n,vector<vector<int>>& tG,vector<int>& checked){
    checked[n] = true;
    for(auto next:tG[n]){
        if(checked[next]) continue;
        G[n].push_back(edge(n,next,0));
        make_tree(next,tG,checked);
    }
}

void make_Kado(ll u,ll v,ll w,vector<int>& Kado){
    if(w != -1 && isKadomatsu(A[u], A[v], A[w])) Kado[u] = Kado[v] + 1;
    for(auto e:G[u]) if(e.v != v) make_Kado(e.v, u, v, Kado);
}
void solve(){
    int N; cin >> N;
    for(int i = 0; i < N;i++){
        ll _A; cin >> _A;
        A[i] = _A;
    }
    
    tG.resize(N);
    checked.resize(N);
    for(int i = 0; i < N-1;i++){
        int x,y; cin >> x >> y; x--;y--;
        tG[x].push_back(y); tG[y].push_back(x);
    }
    G.resize(N);
    int root = 0;
    make_tree(root,tG,checked);
    
    LCA lca(G,root);
    
    vector<int> Kado(N);
    make_Kado(root,-1,-1,Kado);
    
    // cout << kadomatsu << endl;
    // cout << A << endl;
    
    int Q; cin >> Q;
    while(Q--){
        ll u,v; cin >> u >> v; u--; v--;
        if(lca.depth[u]>lca.depth[v]) swap(u,v);
        ll p = lca.get(u,v);
        bool ok = true;
        
        if(lca.depth[v]-lca.depth[p] -1 > Kado[v] || lca.depth[u] - lca.depth[p] - 1 > Kado[u]){
            cout << "NO" << endl;
            continue;
        }
        
        //cout << ok << endl;
        //cout << p << " " << u << " " << v << endl;
        if(p == u){
            ok &= isKadomatsu(A[lca.get_parent(v, lca.depth[v]-lca.depth[u]-1)], A[u], A[v]);
            ok &= isKadomatsu(A[u],A[v], A[lca.parent[0][v]]);
        }else{
            ll pu = lca.get_parent(u, lca.depth[u]-lca.depth[p]-1);
            ll pv = lca.get_parent(v, lca.depth[v]-lca.depth[p]-1);
            ll qu = lca.parent[0][u];
            ll qv = lca.parent[0][v];
            
            
            ok &= isKadomatsu(A[pu], A[p], A[pv]);
            ok &= isKadomatsu(A[qu], A[u], A[v]);
            ok &= isKadomatsu(A[u], A[v], A[qv]);
        }
        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
