#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

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
    
    void fit(){
        visited.clear(); visited.assign(V,0);
        dfs(0,0);
        ll N_ = ET.size();
        N = 1;
        while(N < N_) N*=2;
        node.clear(); node.assign(2*N - 1,make_pair(INF,INF));
        for(int i = 0; i < N_;i++) node[N-1+i] = ET[i];
        for(int k = N - 2; k>=0;k--) node[k] = min(node[2*k+1],node[2*k+2]);
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
    
    ll solve(ll s,ll t){
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
        cout << lca.solve(u,v) << endl;
    }
    return 0;
}
