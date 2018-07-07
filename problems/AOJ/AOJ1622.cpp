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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1622&lang=jp>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 ４隅の点連結度を調べれば良い
 ここで 左上から時計回りに順番に点連結度が２であればYESになる
 ================================================================
 */

struct DINIC{
    typedef long long ll;
    typedef ll CapType;
    struct edge {
        int to; // 行き先
        CapType cap; // 容量
        int rev; // 逆辺
        edge() {}
        edge(int to, CapType cap, int rev) :to(to), cap(cap), rev(rev) {}
    };
    vector<vector<edge>> G; // グラフの隣接リスト表現
    vector<ll> level; // sからの距離
    vector<ll> iter; // どこまで調べ終わったか
    
    DINIC (int V){
        G.resize(V);
        level.resize(V);
        iter.resize(V);
    }
    
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
        fill(level.begin(),level.end(),-1);
//        fill(level,level+MAX_V,-1);
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
            fill(iter.begin(),iter.end(),0);
//            fill(iter,iter+MAX_V,0);
            CapType f;
            while((f = dfs(s,t,LINF)) > 0){
                flow += f;
            }
        }
    }
};

int N,M;
int d[5] = {1,0,-1,0,1};
int func(int i,int j){ return i*M+j;}
bool check(int S,int T,vector<vector<char>>& masu){
    DINIC dinic(N*M*2);
    for(int i = 0; i < N;i++){
        for(int j = 0; j < M;j++){
            dinic.add_directed_edge(func(i,j) + N*M, func(i,j), 1);
            if(masu[i][j] == '#') continue;
            for(int k = 0; k < 4;k++){
                int ny = i + d[k], nx = j + d[k+1];
                if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
                if(masu[ny][nx] == '#') continue;
                dinic.add_directed_edge(func(i,j),func(ny,nx)+N*M,1);
            }
        }
    }
    return dinic.max_flow(S, T) == 2;
}
string solve(){
    string res;
    vector<vector<char>> masu(N,vector<char>(M,'#'));
    for(int i = 0; i < N;i++) for(int j = 0; j < M;j++) cin >> masu[i][j];
    bool flag = check(func(0,0),func(0,M-1)+N*M,masu) &&
                check(func(0,M-1),func(N-1,M-1)+N*M,masu) &&
                check(func(N-1,M-1),func(N-1,0)+N*M,masu) &&
                check(func(N-1,0),func(0,0)+N*M,masu);
    res = flag?"YES":"NO";
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    while(cin >> N >> M,N){
        cout << solve() << endl;
    }
    return 0;
}
