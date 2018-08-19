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
 <url:https://yukicoder.me/problems/no/119>
 問題文============================================================
 =================================================================
 解説=============================================================
 最小かっとまではわかったが
 辺の貼り方がうまくわからなかった。
 >> http://rsujskf.s602.xrea.com/?yukicoder_119
 ================================================================
 */

struct DINIC{
#define MAX_V 100
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

ll solve(){
    ll res = 0;
    int N; cin >> N;
    vector<int> B(N),C(N);
    for(int i = 0; i < N;i++) cin >> B[i] >> C[i];
    int M; cin >> M;
    vector<int> D(M),E(M);
    for(int i = 0; i < M;i++) cin >> D[i] >> E[i];
    
    int S = 2*N,T = S+1;
    DINIC dinic;
    for(int i = 0; i < N;i++) res += B[i]+C[i];
    for(int i = 0; i < N;i++){
        dinic.add_directed_edge(S,i,B[i]);
        dinic.add_directed_edge(i,i+N, INF);
        dinic.add_directed_edge(i+N,T,C[i]);
    }
    for(int i = 0; i < M;i++){
        dinic.add_directed_edge(D[i], E[i]+N,INF);
    }
    res -= dinic.max_flow(S, T);
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
