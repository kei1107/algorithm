/*
 * 2-sat
 * 
 * 変数 x0,x1,....,xN-1に対して
 * (xi = f) V (xj = g)
 * をいうクロージャを足し、すべて満たす変数の割り当てがあるかどうかを解く 
 */

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

struct two_sat {
  public:
    two_sat() : _n(0), scc(0) {}
    two_sat(int n) : _n(n), _answer(n), scc(2 * n) {}

    // (xi = f) V (xj = G)
    void add_clause(int i, bool f, int j, bool g) {
        assert(0 <= i && i < _n);
        assert(0 <= j && j < _n);
        scc.add_edge(2 * i + (f ? 0 : 1), 2 * j + (g ? 1 : 0));
        scc.add_edge(2 * j + (g ? 0 : 1), 2 * i + (f ? 1 : 0));
    }
    bool satisfiable() {
        scc.scc();
        for (int i = 0; i < _n; i++) {
            if(scc.get_group(2*i) == scc.get_group(2*i+1)) return false;
            _answer[i] = scc.get_group(2*i) < scc.get_group(2*i+1);
        }
        return true;
    }
    std::vector<bool> answer() { return _answer; }

  private:
    int _n;
    std::vector<bool> _answer;
    SCC scc;
};


// =================================================== //
// verified : https://atcoder.jp/contests/practice2/tasks/practice2_h
template<class Type>
Type solve(Type res = Type()){
    int N,D; cin >> N >> D;
    vector<ll> X(N),Y(N);
    for(int i = 0; i < N;i++) cin >> X[i] >> Y[i];

    // ts[i] = (i-th flag is located on x[i])
    two_sat ts(N);
    for(int i = 0; i < N;i++){
        for(int j = i+1; j < N;j++){
            if(abs(X[i] - X[j]) < D){
                // A[i]とA[j]が同時にtrue(Xの位置に旗をおく)になってはいけない
                // ￢A[i] または　￢A[j]である必要
                // ￢A[i] ∨ ￢A[j]
                // A[i]⇒￢A[j], A[j]⇒￢A[i]

                // cannot use both of x[i] and x[j]
                ts.add_clause(i,false,j,false);
            }
            if(abs(X[i] - Y[j]) < D){
                // ￢A[i] ∨ A[j]
                // A[i]⇒A[j], ￢A[j]⇒A[i]
                ts.add_clause(i,false,j,true);
            }
            if(abs(Y[i] - X[j]) < D){
                ts.add_clause(i,true,j,false);
            }
            if(abs(Y[i]-Y[j]) < D){
                ts.add_clause(i,true,j,true);
            }
        }
    }
    if(!ts.satisfiable()){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    auto answer = ts.answer();
    for(int i = 0; i < N;i++){
        if(answer[i]){
            cout << X[i] << endl;
        }else{
            cout << Y[i] << endl;
        }
    }
    return res;
}
