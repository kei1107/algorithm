/*
 DINIC
 */
struct DINIC{
#define MAX_V 10050
    typedef long long ll;
    typedef ll CapType;
    struct edge {
        int to; // 行き先
        CapType cap; // 容量
        int rev; // 逆辺
        edge() {}
        edge(int to, CapType cap, int rev) :to(to), cap(cap), rev(rev) {}
    };
    vector<edge> G[MAX_V]; // グラフの隣接リスト表現
    ll level[MAX_V]; // sからの距離
    ll iter[MAX_V]; // どこまで調べ終わったか
    
    // fromからtoへ向かう容量capの辺をグラフに追加する
    void add_directed_edge(int from, int to, CapType cap) {
        pos.emplace_back(from,(int)G[from].size());
        G[from].push_back(edge(to, cap, (int)G[to].size()));
        G[to].push_back(edge(from, 0, (int)G[from].size() - 1));
    }
    void add_undirected_edge(int from, int to, CapType cap) {
        G[from].push_back(edge(to, cap, (int)G[to].size()));
        G[to].push_back(edge(from, cap, (int)G[from].size() - 1));
    }
    
    // sからの最短距離をBFSで計算する
    void bfs(int s){
        fill(level,level+MAX_V,-1);
        queue<int> q;
        level[s] = 0;
        q.push(s);
        while(!q.empty()){
            int v = q.front(); q.pop();
            for(int i = 0; i < (int)G[v].size();i++){
                edge& e = G[v][i];
                if(e.cap > 0 && level[e.to] < 0){
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
    }
    
    // 増加パスをDFSで探す
    CapType dfs(int v, int t,CapType f){
        if(v == t) return f;
        for(ll &i = iter[v]; i < G[v].size();i++){
            edge &e = G[v][i];
            if(e.cap > 0 && level[v] < level[e.to]){
                CapType d = dfs(e.to,t,min(f,e.cap));
                if(d > 0){
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
    
    CapType max_flow(int s,int t){
        CapType flow = 0;
        for(;;){
            bfs(s);
            if(level[t] < 0) return flow;
            fill(iter,iter+MAX_V,0);
            CapType f;
            while((f = dfs(s,t,LINF)) > 0){
                flow += f;
            }
        }
    }

    struct edge_with_flow{
        int from,to;
        CapType cap,flow;
        edge_with_flow(){}
        edge_with_flow(int from,int to,CapType cap,CapType flow):from(from),to(to),cap(cap),flow(flow){}
    };
    vector<pii> pos;

    //  有方向グラフにのみ適用
    //  各辺を {from,to,cap,flow:実際に流れた流量}として取り出す
    vector<edge_with_flow> edges(){
        vector<edge_with_flow> ret;
        for(int i = 0; i < (int)pos.size(); i++){
            auto e = G[pos[i].first][pos[i].second];
            auto re = G[e.to][e.rev];
            ret.emplace_back(pos[i].first, e.to, e.cap + re.cap, re.cap);
        }
        return ret;
    }
};

// ==================================================================================
// verified: aoj
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    int V,E; cin >> V >> E;
    DINIC Flow;
    for(int i = 0; i < E;i++){
        int u,v; ll cap; cin >> u >> v >> cap;
        Flow.add_directed_edge(u,v,cap);
    }
    cout << Flow.max_flow(0, V-1) << endl;
    return 0;
}
// ==================================================================================
// verified: alc + 復元(有向辺) https://atcoder.jp/contests/practice2/tasks/practice2_d
template<class Type>
Type solve(Type res = Type()){
    int N,M; cin >> N >> M;
    vector<vector<char>> masu(N,vector<char>(M));
    for(auto& vec:masu) for(auto& in:vec) cin >> in;

    DINIC dinic;
    int S = N*M,T = S+1;
    
    auto sub2ind = [&](int i,int j){
        return i*M+j;
    };

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M;j++){
            if(masu[i][j] == '#') continue;
            int V = sub2ind(i,j);
            if((i+j)%2 == 0){
                dinic.add_directed_edge(S,V,1);
            }else{
                dinic.add_directed_edge(V,T,1);
            }
        }   
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M;j++){
            if((i+j)%2 == 1 || masu[i][j] == '#') continue;
            int U = sub2ind(i,j);
            int D[4] = {1,0,-1,0};
            for(int k = 0; k < 4;k++){
                int ii = i + D[k];
                int jj = j + D[k^1];

                if(ii < 0 || ii >= N || jj < 0 || jj >= M) continue;

                int V = sub2ind(ii,jj);

                dinic.add_directed_edge(U,V,1);
            }
        }
    }

    cout << dinic.max_flow(S,T) << endl;
    auto edges = dinic.edges();
    for(auto e:edges){
        if(e.from == S || e.to == T || e.flow == 0) continue;

        pii p1 = make_pair(e.from/M,e.from%M);
        pii p2 = make_pair(e.to/M,e.to%M);

        if(p1.first == p2.first - 1){
            masu[p1.first][p1.second] = 'v';
            masu[p2.first][p2.second] = '^';
        }else if(p1.first == p2.first + 1){
            masu[p1.first][p1.second] = '^';
            masu[p2.first][p2.second] = 'v';
        }else if(p1.second == p2.second - 1){
            masu[p1.first][p1.second] = '>';
            masu[p2.first][p2.second] = '<';
        }else if(p1.second == p2.second + 1){
            masu[p1.first][p1.second] = '<';
            masu[p2.first][p2.second] = '>';
        }
    }
    for(int i = 0; i < N;i++){
        for(int j = 0; j  < M; j++){
            cout << masu[i][j];
        }cout << endl;
    }
    return res;
}

