#include "bits/stdc++.h"
#include "atcoder/all"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T>& V){ for(size_t i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> >& Mat){ for(size_t i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T>& mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }
template<typename T>vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}
/*
 <url:https://atcoder.jp/contests/abc193/tasks/abc193_f>
 問題文============================================================
 F - Zebraness 
 =================================================================
 解説=============================================================
 ================================================================
 */

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

    //  有向グラフにのみ適用
    //  各辺を {from,to,cap,flow:実際に流れた流量,コスト}として取り出す
    //  無向グラフで利用する場合は、両方向からadd_(directed)_edgeをする。
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


template<class Type>
Type solve(Type res = Type()){
    int N; cin >> N;
    int S = N*N,T = S+1;

    vector<vector<char>> c(N,vector<char>(N));
    for(auto& vec:c) for(auto& in:vec) cin >> in;
    DINIC dinic;

    int dx[] = {1,0};
    int dy[] = {0,1};
    for(int i = 0; i < N;i++){
        for(int j = 0; j < N;j++){
            int id = i*N + j;

            if(c[i][j] == 'W') dinic.add_directed_edge((i+j)%2==0?S:id,(i+j)%2==0?id:T,INF);
            if(c[i][j] == 'B') dinic.add_directed_edge((i+j)%2==0?id:S,(i+j)%2==0?T:id,INF);

            for(int k = 0; k < 2; k++){
                int ni = i + dx[k];
                int nj = j + dy[k];
                if(ni < 0 || nj < 0 || ni >= N || nj >= N) continue;

                int nid = ni*N + nj;
                dinic.add_undirected_edge(id,nid,1);
            }
        }
    }
    ll cost = dinic.max_flow(S,T);
    res = 2*(N-1)*N - cost;
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    //solve<ll>(0);
    cout << fixed << setprecision(12) << solve<ll>() << endl;
    return 0;
}