#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

/*
 <url:https://yukicoder.me/problems/no/177>
 問題文============================================================
 =================================================================
 解説=============================================================
 典型的な最大流問題
 
 始点 S と 終点 Tの新たな頂点を設け
 
 Sから原画マンの頂点に対して、その原画マンが描くことのできるカット数を容量
 作画監督からTに対して、その作画監督が仕上げることができるカット数を容量
 とした辺を貼る。
 
 あとは、作画監督と絵柄が合う原画マンとの間に無限容量の辺を貼る。
 このグラフで得られる最大流が仕上げることのできる最大カット数となるので、
 得られた最大流がWを超えているかいないかで判断できる
 ================================================================
 */

struct DINIC{
#define MAX_V 200
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
};
string solve(){
    int W,N,M;
    cin >> W >> N;
    vector<int> J(N); for(auto& in:J) cin >> in;
    cin >> M;
    vector<int> C(M); for(auto& in:C) cin >> in;
    int S = N+M,T = S+1;
    DINIC dinic;
    
    for(int i = 0; i < N;i++) dinic.add_directed_edge(S, i, J[i]);
    for(int i = 0; i < M;i++) dinic.add_directed_edge(N+i, T, C[i]);
    
    for(int i = 0; i < M;i++){
        int Q; cin >> Q;
        vector<int> X(N,1);
        for(int j = 0; j < Q; j++){
            int x; cin >> x; x--;
            X[x] = 0;
        }
        for(int j = 0; j < N;j++){
            if(X[j]) dinic.add_directed_edge(j, N+i, INF);
        }
    }
    
    if(dinic.max_flow(S, T) >= W){
        return "SHIROBAKO";
    }else{
        return "BANSAKUTSUKITA";
    }
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
