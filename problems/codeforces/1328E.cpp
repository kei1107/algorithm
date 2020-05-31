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
 <url:https://codeforces.com/problemset/problem/1328/E>
 問題文============================================================
 E. Tree Queries
 =================================================================
 解説=============================================================
 ================================================================
 */

/**
 * 木グラフに対して与えられた頂点集合がある頂点を根とした1本のパス上に存在するかどうかを判定する。
 * init -> add_edge -> fit -> query
 */
class IsAncestor{
public:
    int T;
    vector<int> par,dep;
    vector<int> tin,tout;
    vector<vector<int>> G;
    
    IsAncestor(int N){init(N);};
    void init(int N){
        T = 0;
        par = dep = tin = tout = vector<int>(N);
        G = vector<vector<int>>(N);
    }
    void add_edge(int u,int v){
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    void dfs(int n,int parent = -1,int depth = 0){
        par[n] = parent;
        dep[n] = depth;
        tin[n] = T++;
        for(auto next:G[n]){
            if(next == parent) continue;
            dfs(next,n,depth+1);
        }
        tout[n] = T++;
    }
    void fit(int root = 0){
        dfs(root);
    }
    bool query(vector<int>& vs){
        int max_depth = vs[0];
        for(auto v:vs) if(dep[max_depth] < dep[v]) max_depth = v;
        bool ok = true;
        for(auto v:vs) ok &= query(v,max_depth);
        return ok;
    }
    bool query(int u,int v){
        if(dep[u] > dep[v]) swap(u,v);
        return tin[u] <= tin[v] && tout[v] <= tout[u];
    }
};

template<class Type>
Type solve(Type res = Type()){
    int n,m; cin >> n >> m;
    IsAncestor T(n);
    for(int i = 0; i < n-1;i++){
        int u,v; cin >> u >> v;
        u--; v--;
        T.add_edge(u, v);
    }
    T.fit();

    while(m--){
        int k; cin >> k;
        vector<int> vs(k);
        for(auto& in:vs){ cin >> in; in--;}
        for(auto& v:vs){
            if(T.par[v] == -1) continue;
            v = T.par[v];
        }
        cout << (T.query(vs)?"YES":"NO") << endl;
    }
    
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve(0);
    // cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
