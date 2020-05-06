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


/// ====================================================================== ///
//  codeforces : https://codeforces.com/problemset/problem/1328/E
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
