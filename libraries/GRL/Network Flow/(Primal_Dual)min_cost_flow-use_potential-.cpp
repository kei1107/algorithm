/*
 Primal_Dual
 */
typedef ll PD_Type;
const PD_Type PD_INF = INF;
struct Primal_Dual{
    typedef pair< PD_Type, int > pii;
    
    struct edge{
        int to, rev;
        PD_Type    cap, cost;
        edge() {}
        edge(int to, PD_Type cap, PD_Type cost, int rev) :to(to), cap(cap), cost(cost), rev(rev) {}
    };
    vector< vector< edge > > graph;
    vector< int > prevv, preve;
    vector< PD_Type > potential, min_cost;
    Primal_Dual(int V) : graph(V) {}
    
    void add_edge(int from, int to, PD_Type cap, PD_Type cost){
        pos.emplace_back(from,(int)graph[from].size());
        graph[from].push_back(edge(to, cap, cost, (int)graph[to].size()));
        graph[to].push_back(edge(from, 0, -cost, (int)graph[from].size() - 1));
    }
    
    PD_Type min_cost_flow(int s, int t, int f){
        int V = (int)graph.size();
        PD_Type ret = 0;
        priority_queue< pii, vector< pii >, greater< pii > > que;
        potential.assign(V, 0);
        preve.assign(V, -1);
        prevv.assign(V, -1);
        
        while (f > 0) {
            min_cost.assign(V, PD_INF);
            que.push(pii(0, s));
            min_cost[s] = 0;
            
            while (!que.empty()) {
                pii p = que.top();
                que.pop();
                if (min_cost[p.second] < p.first) continue;
                for (int i = 0; i < (int)graph[p.second].size(); i++) {
                    edge &e = graph[p.second][i];
                    PD_Type nextCost = min_cost[p.second] + e.cost + potential[p.second] - potential[e.to];
                    if (e.cap > 0 && min_cost[e.to] > nextCost) {
                        min_cost[e.to] = nextCost;
                        prevv[e.to] = p.second; preve[e.to] = i;
                        que.push(pii(min_cost[e.to], e.to));
                    }
                }
            }
            if (min_cost[t] == PD_INF) return -1;
            for (int v = 0; v < V; v++) potential[v] += min_cost[v];
            PD_Type addflow = f;
            for (int v = t; v != s; v = prevv[v]) {
                addflow = min(addflow, graph[prevv[v]][preve[v]].cap);
            }
            f -= addflow;
            ret += addflow * potential[t];
            for (int v = t; v != s; v = prevv[v]) {
                edge &e = graph[prevv[v]][preve[v]];
                e.cap -= addflow;
                graph[v][e.rev].cap += addflow;
            }
        }
        return ret;
    }

    struct edge_with_flow{
        int from,to;
        PD_Type cap,flow,cost;
        edge_with_flow(){}
        edge_with_flow(int from,int to,PD_Type cap,PD_Type flow,PD_Type cost):from(from),to(to),cap(cap),flow(flow){}
    };
    vector<pii> pos;

    //  有方向グラフにのみ適用
    //  各辺を {from,to,cap,flow:実際に流れた流量,コスト}として取り出す
    vector<edge_with_flow> edges(){
        vector<edge_with_flow> ret;
        for(int i = 0; i < (int)pos.size(); i++){
            auto e = graph[pos[i].first][pos[i].second];
            auto re = graph[e.to][e.rev];
            ret.emplace_back(pos[i].first, e.to, e.cap + re.cap, re.cap, e.cost);
        }
        return ret;
    }
};

// ===================================================================== //
// verified : https://atcoder.jp/contests/practice2/tasks/practice2_d
template<class Type>
Type solve(Type res = Type()){
    int N,K; cin >> N >> K;
    auto A = make_v<ll>(N,N);
    for(auto& vec:A) for(auto& in:vec) cin >> in;

    Primal_Dual PD(2*N+2);
    int S = 2*N,T = S+1;

    PD.add_edge(S,T,INF,0);
    for(int i = 0; i < N;i++){
        PD.add_edge(S,i,K,0);
        PD.add_edge(N+i,T,K,0);
    }
    for(int i = 0; i < N;i++){
        for(int j = 0; j < N;j++){
            PD.add_edge(i,N+j,1,-A[i][j]);
        }
    }
    cout << -PD.min_cost_flow(S,T,N*K) << endl;
    
    vector<vector<char>> masu(N,vector<char>(N,'.'));
    auto edges = PD.edges();
    for(auto e: edges){
        if(e.from == S || e.to == T || e.flow == 0) continue;
        masu[e.from][e.to-N] = 'X';
    }
    for(int i = 0; i < N;i++){
        for(int j = 0; j < N;j++){
            cout << masu[i][j];
        }cout << endl;
    }
    return res;
}
