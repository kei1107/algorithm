template<typename CType>
class Dijkstra{
public:
    struct edge{
        size_t u,v;
        CType cost;
        edge() {}
        edge(size_t u,size_t v,CType c):u(u),v(v),cost(c) {}
    };

    size_t V;
    size_t now_root;

    vector<vector<edge>> G;
    vector<CType> dist;

    Dijkstra(size_t V):V(V){
        G.resize(V);
        dist.resize(V);
        init();
    }
    void init(CType init_val = numeric_limits<CType>::max()){
        fill(dist.begin(),dist.end(),init_val);
    }

    void add_directed_edge(size_t u,size_t v,CType cost){
        G[u].emplace_back(edge(u,v,cost));
    }
    void add_undirected_biedge(size_t u,size_t v,CType cost){
        add_directed_edge(u,v,cost);
        add_directed_edge(v,u,cost);
    }

    void fit(size_t root){
        now_root = root;
        dist[now_root] = 0;

        using Item = tuple<CType,size_t>;
        priority_queue<Item,vector<Item>,greater<Item>> pq;
        pq.emplace(0,now_root);

        while(pq.size()){
            auto [cost,n] = pq.top(); pq.pop();
            if(cost > dist[n]) continue;
            for(auto e:G[n]){
                if(dist[e.v] > dist[e.u] + e.cost){
                    dist[e.v] = dist[e.u] + e.cost;
                    pq.emplace(dist[e.v],e.v);
                }
            }
        }
    }
    CType operator[](int i) { return dist[i]; }
};


// verified : https://atcoder.jp/contests/abc191/tasks/abc191_e
template<class Type>
Type solve(Type res = Type()){
    int N,M; cin >> N >> M;
    Dijkstra<int> dijkstra(N);

    using edge_type = tuple<int,int,int>;
    vector<edge_type> edges;
    for(int i = 0; i < M;i++){
        int A,B,C; cin >> A >> B >> C;
        A--; B--;
        dijkstra.add_directed_edge(A,B,C);
        edges.emplace_back(A,B,C);
    }

    for(int n = 0; n < N; n++){
        dijkstra.init();
        dijkstra.fit(n);

        int T = numeric_limits<int>::max();
        for(auto [u,v,cost]: edges){
            if(dijkstra[u] == numeric_limits<int>::max()) continue;
            if(v != n) continue;
            T = min(T,dijkstra[u] + cost);
        }
        if(T == numeric_limits<int>::max()) T = -1;
        cout << T << endl;
    }

    return res;
