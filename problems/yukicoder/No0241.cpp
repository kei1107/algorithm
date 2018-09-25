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
 <url:https://yukicoder.me/problems/no/241>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */

struct edge {
    int to; // 行き先
    int cap; // 容量
    int rev; // 逆辺
    edge() {}
    edge(int to, int cap, int rev) :to(to), cap(cap), rev(rev) {}
};

vector<vector<edge>> G; // グラフの隣接リスト表現
vector<int> used; // DFSですでに調べたらフラグ

// fromからtoへ向かう容量capの辺をグラフに追加する
void add_edge(int from, int to, int cap) {
    G[from].push_back(edge(to, cap, G[to].size()));
    G[to].push_back(edge(from, 0, G[from].size() - 1));
}

// 増加パスをDFSで探す
int dfs(int v, int t, int f) {
    if (v == t) return f;
    used[v] = true;
    for (int i = 0; i < G[v].size(); i++) {
        edge &e = G[v][i];
        if (!used[e.to] && e.cap > 0) {
            int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

// sからtへの最大流を求める
int max_flow(int s, int t) {
    int flow = 0;
    for (;;) {
        fill(used.begin(), used.end(), 0);
        int f = dfs(s, t, INF);
        if (f == 0) return flow;
        flow += f;
    }
}

void solve(){
    int N; cin >> N;
    vector<int> A(N); for(auto& in:A) cin >> in;
    int S = 2*N,T = S+1;
    G.resize(2*N+2); used.resize(2*N+2);
    for(int i = 0; i < N;i++){
        add_edge(S, i, 1);
        add_edge(i+N, T, 1);
        
        for(int j = 0; j < N;j++){
            if(A[i] == j) continue;
            add_edge(i,j+N,1);
        }
    }
    int mflow = max_flow(S, T);
    if(mflow != N){
        cout << -1 << endl;
        return;
    }
    for(int i = 0; i < N;i++){
        for(auto e:G[i]){
            if(e.cap == 0){
                cout << e.to-N << endl;
                break;
            }
        }
    }
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
