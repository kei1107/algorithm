class SCC {
public:
    typedef int TYPE;
    TYPE V;
    vector<vector<TYPE>> G;
    vector<vector<TYPE>> rG;
    vector<vector<TYPE>> group_G;
    vector<vector<TYPE>> group_rG;
    vector<TYPE> group;
    vector<TYPE> List;
    
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
        for (TYPE& next : rG[u]){ if (visited[next] != 1) dfs2(next, group_num); }
    }
    
    void make_group() {
        group.clear(); group.assign(V, -1);
        visited.clear(); visited.assign(V, 0);
        for (int i = 0; i < V;i++){ if (visited[i] != 1) dfs1(i); }
        
        reverse(List.begin(), List.end());
        
        visited.clear(); visited.assign(V, 0);
        group_num = 0;
        for (TYPE& v : List) { if (visited[v] != 1) dfs2(v, group_num++); }
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
};
