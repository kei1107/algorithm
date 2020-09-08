/*
 SCC:強連結成分分解
 有向グラフにおいて「お互いに行き来できる ⟺ 同じグループ」を満たすように頂点をグループ分け
 */
class SCC {
public:
    typedef int TYPE;
    TYPE V;
private:    
    vector<vector<TYPE>> G;             // 入力グラフ
    vector<vector<TYPE>> rG;            // 入力の逆辺グラフ
    vector<vector<TYPE>> group_G;       // 強連結成分同士の有向辺グラフ
    vector<vector<TYPE>> group_rG;      // 強連結成分同士の無向辺グラフ
    vector<vector<TYPE>> each_group_G;  // 各強連結成分内のグラフ（トポロジカル順）
    vector<TYPE> group;                 // 各頂点の強連結成分グループ番号
    vector<TYPE> List;
public:    
    vector<int> visited;
    int group_num;
    
    SCC(TYPE V) :V(V),group_num(0) {
        G.resize(V); rG.resize(V);
    }
    
    void init(TYPE V){
        G.clear(); G.resize(V);
        rG.clear(); rG.resize(V);
    }
    
    void add_edge(TYPE u, TYPE v) {
        G[u].emplace_back(v); rG[v].emplace_back(u);
    }
    
    void dfs1(TYPE u) {
        visited[u] = 1;
        for (TYPE& next : G[u]){ if (visited[next] != 1) dfs1(next); }
        List.emplace_back(u);
    }
    
    void dfs2(TYPE u,TYPE group_num) {
        visited[u] = 1; group[u] = group_num;
        each_group_G.back().emplace_back(u);
        for (TYPE& next : rG[u]){ if (visited[next] != 1) dfs2(next, group_num); }
    }
    
    void scc() {
        group.clear(); group.assign(V, -1);
        visited.clear(); visited.assign(V, 0);
        for (int i = 0; i < V;i++){ if (visited[i] != 1) dfs1(i); }
        
        reverse(List.begin(), List.end());
        
        visited.clear(); visited.assign(V, 0);
        group_num = 0;
        for (TYPE& v : List) { 
            if (visited[v] != 1){
                each_group_G.emplace_back(vector<TYPE>());
                dfs2(v, group_num++); 
            }
        }

        make_group_graph();
    }
    
    void make_group_graph(){
        group_G.clear(); group_G.resize(group_num);
        group_rG.clear(); group_rG.resize(group_num);
        for(int u = 0; u < V;u++){
            for(TYPE& v: G[u]){
                if(!same(u,v)){
                    group_G[group[u]].emplace_back(group[v]);
                    group_rG[group[v]].emplace_back(group[u]);
                }
            }
        }
    }
    
    TYPE get_group(TYPE n){ return group[n]; }
    bool same(TYPE u,TYPE v) {
        return group[u] == group[v];
    }
    
    vector<vector<TYPE>>& get_G() { return G; }
    vector<vector<TYPE>>& get_rG() { return rG; }
    vector<vector<TYPE>>& get_group_G() { return group_G; }
    vector<vector<TYPE>>& get_group_rG() { return group_rG; }
    vector<vector<TYPE>>& get_each_group_G() { return each_group_G; }
};

// verified : https://atcoder.jp/contests/practice2/tasks/practice2_g
template<class Type>
Type solve(Type res = Type()){
    int N,M; cin >> N >> M;
    SCC scc(N);
    for(int i = 0; i < M; i++){
        int a,b; cin >> a >> b;
        scc.add_edge(a,b);
    }
    scc.scc();
    auto G = scc.get_each_group_G();

    printf("%d\n",G.size());
    for(auto g:G){

        printf("%d ",g.size());
        for(auto v:g) printf("%d ",v);
        printf("\n");
    }
    return res;
}
int main(void) {
    // cin.tie(0); ios::sync_with_stdio(false);
    solve<ll>(0);
    // cout << fixed << setprecision(12) << solve<ll>() << endl;
    return 0;
}
