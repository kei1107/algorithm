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
 <url:https://onlinejudge.u-aizu.ac.jp/services/room.html#ACPC2018Day2/problems/I>
 問題文============================================================
 =================================================================
 解説=============================================================
 頑張って流す
 
 各単語について決めうちする
 
 注目した単語をcとすると
 
 cから始まり、cで終わらない単語は、最後cで終わるのを妨害する単語であるため
 source -> 末尾単語　へ
 
 cから始まらず、cで終わる単語は、目的の単語であるため
 c -> sink へ
 cから始まらず、cで終わらない単語は、中継点になりうる単語であるため
 先頭単語 -> 末尾単語 へ
 
 この状態でsourceからsinkへフローを流せば 最後がcで終わる個数がわかる。
 ここで、 cから始まり、cで終わらない単語よりも多ければ、
 しりとりをその単語で終えることができる
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
    
    void init(){
        for(int i = 0; i < MAX_V;i++) G[i].clear();
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
DINIC dinic;
int S = 26,T = S+1;
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    ll N; cin >> N;
    vector<string> s(N); for(auto &in:s) cin >> in;

    set<char> st;
    for(auto& str:s) st.insert(str.back());

    for(auto& c:st){
        dinic.init();

        int key = c - 'a';

        ll sum = 0;
        for(int i = 0; i < N;i++){
            int front = s[i].front() - 'a';
            int back = s[i].back() - 'a';

            if(key == front && back != key){
                sum += 1;
                dinic.add_directed_edge(S, back, 1);
            }
            if(key != front){
                if(back == key){
                    dinic.add_directed_edge(front, T, 1);
                }else{
                    dinic.add_directed_edge(front, back, 1);
                }
            }
        }
        ll mflow = dinic.max_flow(S, T);
        if(mflow >= sum){
            cout << c << endl;
        }
    }
    return 0;
}
