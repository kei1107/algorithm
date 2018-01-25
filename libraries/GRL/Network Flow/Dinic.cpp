// Directed

#define INF (1<<30)
#define LINF (1LL<<60)
#define MAX_V 5050
struct edge {
    int to; // 行き先
    ll cap; // 容量
    int rev; // 逆辺
    edge() {}
    edge(int to, ll cap, int rev) :to(to), cap(cap), rev(rev) {}
};

vector<edge> G[MAX_V]; // グラフの隣接リスト表現
int level[MAX_V]; // sからの距離
int iter[MAX_V]; // どこまで調べ終わったか

// fromからtoへ向かう容量capの辺をグラフに追加する
void add_edge(int from, int to, ll cap) {
    G[from].push_back(edge(to, cap, (int)G[to].size()));
    G[to].push_back(edge(from, 0, (int)G[from].size() - 1));
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
ll dfs(int v, int t,ll f){
    if(v == t) return f;
    for(int &i = iter[v]; i < G[v].size();i++){
        edge &e = G[v][i];
        if(e.cap > 0 && level[v] < level[e.to]){
            ll d = dfs(e.to,t,min(f,e.cap));
            if(d > 0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

ll max_flow(int s,int t){
    ll flow = 0;
    for(;;){
        bfs(s);
        if(level[t] < 0) return flow;
        fill(iter,iter+MAX_V,0);
        ll f;
        while((f = dfs(s,t,LINF)) > 0){
            flow += f;
        }
    }
}

// ================================================== //

// UnDirected

#define INF (1<<30)
#define LINF (1LL<<60)
#define MAX_V 5050
struct edge {
    int to; // 行き先
    ll cap; // 容量
    int rev; // 逆辺
    edge() {}
    edge(int to, ll cap, int rev) :to(to), cap(cap), rev(rev) {}
};

vector<edge> G[MAX_V]; // グラフの隣接リスト表現
int level[MAX_V]; // sからの距離
int iter[MAX_V]; // どこまで調べ終わったか

// fromからtoへ向かう容量capの辺をグラフに追加する
void add_edge(int from, int to, ll cap) {
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
ll dfs(int v, int t,ll f){
    if(v == t) return f;
    for(int &i = iter[v]; i < G[v].size();i++){
        edge &e = G[v][i];
        if(e.cap > 0 && level[v] < level[e.to]){
            ll d = dfs(e.to,t,min(f,e.cap));
            if(d > 0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

ll max_flow(int s,int t){
    ll flow = 0;
    for(;;){
        bfs(s);
        if(level[t] < 0) return flow;
        fill(iter,iter+MAX_V,0);
        ll f;
        while((f = dfs(s,t,LINF)) > 0){
            flow += f;
        }
    }
}
