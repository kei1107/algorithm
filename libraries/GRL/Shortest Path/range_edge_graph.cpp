/*
 * 区間に辺を張るグラフ
 * 頂点数N,辺の数Q
 * init : O(N)
 * add_edge : O(log(N))
 * dijkstra : O((N+Qlog(N))log(N))
 */
template<class W_Type>
class range_edge_graph{
public:
    W_Type INF;
    int n;
    struct edge{
        int to;
        W_Type weight;
        edge() = default;
        edge(int to,W_Type weight):to(to),weight(weight){}
    };
    vector<vector<edge>> G;
    range_edge_graph(int _n){
        init(_n);
    }
    void init(int _n){
        INF = numeric_limits<W_Type>::max();
        n = _n;
        G.clear();
        G.resize(4*n);

        for(int i = 1; i < n;i++){
            int L = i<<1|0, R = i<<1|1;

            G[i].emplace_back(L,0);
            G[i].emplace_back(R,0);

            G[L+2*n].emplace_back(i+2*n,0);
            G[R+2*n].emplace_back(i+2*n,0);
        }

        for(int i = n; i < 2*n; i++){
            G[i].emplace_back(i+2*n,0);
        }
    }

    // from [l1,r1) to [l2,r2)
    void add_edge(int l1,int r1,int l2,int r2,W_Type w){
        int idx = (int)G.size();

        for(l1 += n, r1 += n; l1 < r1; l1 >>= 1, r1 >>= 1){
            if(l1 & 1){ 
                G[l1+2*n].emplace_back(idx,0);
                l1++;
            }
            if(r1 & 1){
                r1--;
                G[r1+2*n].emplace_back(idx,0);
            }
        }
        vector<edge> node;
        for(l2 += n, r2 += n; l2 < r2; l2 >>= 1, r2 >>= 1){
            if(l2 & 1){
                node.emplace_back(l2,w);
                l2++;
            }
            if(r2 & 1){
                r2--;
                node.emplace_back(r2,w);
            }
        }
        G.emplace_back(node);
    }

    vector<W_Type> dijkstra(int s){
        s += n;
        vector<W_Type> dist(G.size(),numeric_limits<W_Type>::max());

        dist[s] = 0;
        using Item = tuple<W_Type,int>;
        priority_queue<Item,vector<Item>,greater<Item>> pq;
        pq.emplace(0,s);
        while(pq.size()){
            W_Type w;
            int from;

            tie(w,from) = pq.top(); pq.pop();
            if(dist[from] < w) continue;
            for(edge& e: G[from]){
                if(dist[e.to] > dist[from] + e.weight){
                    dist[e.to] = dist[from] + e.weight;
                    pq.emplace(dist[e.to],e.to);
                }
            }
        }
        return vector<W_Type>(dist.begin() + n, dist.begin() + 2*n);
    }
};


// verified : https://atcoder.jp/contests/nikkei2019-2-qual/tasks/nikkei2019_2_qual_d
template<class Type>
Type solve(Type res = Type()){

    int n,m; cin >> n >> m;
    range_edge_graph<ll> G(n);
    for(int i = 0; i < m;i++){
        int l,r,c; cin >> l >> r >> c;
        l--; r--;
        G.add_edge(l,r+1,l,r+1,c);
    }
    res = G.dijkstra(0)[n-1];
    if(res == G.INF) res = -1;
    return res;
}
