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
template<class T> ostream& operator << (ostream& out,const vector<T>& V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> >& Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T>& mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }
template<typename T>vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}
/*
 <url:https://codeforces.com/problemset/problem/1304/E>
 問題文============================================================
 E. 1-Trees and Queries
 =================================================================
 解説=============================================================
 ================================================================
 */

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
        visited.clear(); visited.assign(V,-1);
        dfs(root,0);
        ll N_ = ET.size();
        N = 1;
        while(N < N_) N*=2;
        node.clear(); node.assign(2*N - 1,make_pair(INF,INF));
        for(int i = 0; i < N_;i++) node[N-1+i] = ET[i];
        for(ll k = N - 2; k>=0;k--) node[k] = min(node[2*k+1],node[2*k+2]);
    }
    
    void dfs(ll n,int dep){
        visited[n] = dep;
        ET.emplace_back(make_pair(dep, n));
        Ind[n] = (int)ET.size() - 1;
        for(auto next:T[n]){
            if(visited[next] != -1)continue;
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
    
    int dist(int u,int v){
        return visited[u] + visited[v] - 2*visited[query(u,v)];
    }
};

template<class Type>
Type solve(Type res = Type()){
    int n; cin >> n;
    LCA lca(n);
    for(int i = 0; i < n-1; i++){
        int u,v; cin >> u >> v;
        u--; v--;
        lca.add_edge(u, v);
    }
    lca.fit(0);
    
    int q; cin >> q;
    while(q--){
        int x,y,a,b,k;
        cin >> x >> y >> a >> b >> k;
        x--; y--; a--; b--;
        
        {// a -> b
            int K = lca.dist(a,b);
            
            if(K <= k){
                if((k-K)%2 == 0){
                    cout << "YES" << endl;
                    continue;
                }
            }
        }
        {// a -> x -> y -> b
            int K = lca.dist(a,x) + 1 + lca.dist(y, b);
            
            if(K <= k){
                if((k-K)%2 == 0){
                    cout << "YES" << endl;
                    continue;
                }
            }
        }
        {// a -> y -> x -> b
            int K = lca.dist(a,y) + 1 + lca.dist(x, b);
            
            if(K <= k){
                if((k-K)%2 == 0){
                    cout << "YES" << endl;
                    continue;
                }
            }
        }
        
        cout << "NO" << endl;
    }
    
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve(0);
    // cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
