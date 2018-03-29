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
<url:https://onlinejudge.u-aizu.ac.jp/services/room.html#RitsCamp18Day3/problems/F>
問題文============================================================
 えびちゃんは有向グラフが大好きです。
 そんなえびちゃんの目の前に、N 頂点 M 辺の有向グラフが降ってきました。
 このグラフの頂点はそれぞれ 1 から N、辺はそれぞれ 1 から M で番号付けられています。
 そして、辺 i は頂点 ui から vi への向きに距離 di だけ伸びています。
 
 えびちゃんは、このグラフのある2頂点 s と t について、
 いくつかの辺に対して伸ばす操作を行い s-t 間の最短距離を伸ばしたいと考えました。
 すなわち、s-t 間の最短距離が、操作前のグラフでよりも、操作後のグラフでの方が長くなるようにしたいです。
 
 すべて辺をわずかでも伸ばしてしまえば目的を達成できますが、えびちゃんはそれでは面白くないと考え、
 操作のルールを以下のように定めました。
 
 各辺ごとに距離を伸ばしてよい（伸ばさない辺があってもよい）。
 伸ばす距離は正の整数から任意に選択できる。
 辺 i は距離 1 伸ばすごとに ci のコストがかかる。
 
 このとき、えびちゃんが s-t 間の最短距離を1以上伸ばすために必要な最小コストを求めてください。
=================================================================

解説=============================================================

 ダイクストラを用いて、最短経路に関するパスのみからなるグラフを作成する。
 
 答えはそのグラフに対する最大流（最小かっと）となる
 
================================================================
*/

struct DINIC{
#define MAX_V 5050
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


struct edge{
    ll u,v,d,c;
    edge(){}
    edge(ll u,ll v,ll d,ll c):u(u),v(v),d(d),c(c){}
};
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N,M,s,t; cin >> N >> M >> s >> t;
    s--; t--;
    
    vector<vector<edge>> G(N);
    vector<edge> edges(M);
    for(int i = 0; i < M;i++){
        ll u,v,d,c; cin >> u >> v >> d >> c;
        u--; v--;
        G[u].push_back(edge(u,v,d,c));
        edges[i] = edge(u,v,d,c);
    }
    
    
    // 最短経路 dijkstra
    vector<ll> dist(N,INF);
    dist[s] = 0;
    queue<ll> q; q.push(s);
    while(q.size()){
        ll n = q.front(); q.pop();
        for(edge& e:G[n]){
            if(dist[e.v] > dist[e.u] + e.d){
                dist[e.v] = dist[e.u] + e.d;
                q.push(e.v);
            }
        }
    }
    
    // 最小かっと
    DINIC Flow;
    for(edge e:edges){
        if(dist[e.u]+e.d == dist[e.v]){
            Flow.add_directed_edge(e.u, e.v, e.c);
        }
    }
    cout << Flow.max_flow(s,t) << endl;
    
    
	return 0;
}
