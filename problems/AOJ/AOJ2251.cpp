#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e16;

/*
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2251>
 問題文============================================================
 N 個の家を M 本の道が双方向に距離 d[i] で繋いでいる．
 
 L 個の「家 p[i] に時刻 t[i] にプレゼントを届けよ」というリクエストをすべて満たすのに必要な最小のサンタの数を答える．
 
 サンタは時刻 0 にいずれかの家からスタートし，単位時間あたりに単位距離進むことができる．
 一人のサンタが何個のリクエストを処理してもかまわない．

 =================================================================
 
 解説=============================================================
 DAGの最小パス被膜
 
 家iからjに対してその最短距離dとする
 dが t[j] - t[i] 以下であるということは i -> j に対してサンタが一人でプレゼントを届ける
 ことができるということになる
 
 この条件をもとに辺を貼る。
 するとこの問題はDAGの最小パス被膜に帰着でき
 
 頂点数 - マッチング数　が　全頂点を被膜するのに必要な最小の辺の数（サンタの数）となる
 
 こういった考察はこのpdfが参考になる: https://www.ioi-jp.org/camp/2016/2016-sp-tasks/2016-sp-d1-matryoshka-review.pdf
 ================================================================
 */

#define MAX_L 1000

ll V;
vector<vector<ll> > G(2*MAX_L);
vector<ll> match(2*MAX_L);
vector<int> used(2*MAX_L);

void add_edge(ll u, ll v) {
    G[u].push_back(v);
    G[v].push_back(u);
}

bool dfs(ll v) {
    used[v] = 1;
    for (int i = 0; i < G[v].size(); i++) {
        ll u = G[v][i], w = match[u];
        if (w < 0 || ((used[w] == 0) && dfs(w))) {
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    return false;
}

ll bipartite_matching() {
    ll res = 0;
    for (int i = 0; i < (int)match.size();i++)match[i] = -1;
    for (int v = 0;v < V;v++) {
        if (match[v] < 0) {
            for (int i = 0; i < (int)used.size();i++)used[i] = 0;
            if (dfs(v))res++;
        }
    }
    return res;
}

#define MAX_N 100
int dist[MAX_N][MAX_N];
pii query[MAX_L];

void init(){
    for(int i = 0; i < 2*MAX_L;i++) G[i].clear();
    fill(used.begin(),used.end(),0);
    fill(match.begin(),match.end(),0);
    
    for(int i = 0; i < MAX_N;i++)for(int j = 0; j < MAX_N;j++) dist[i][j] = INF;
    for(int i = 0; i < MAX_N;i++) dist[i][i] = 0;
}


int main(void) {
    //	cin.tie(0); ios::sync_with_stdio(false);
    int N,M,L;
    while(true){
        scanf("%d%d%d",&N,&M,&L);
        if(N == 0 && M == 0 && L == 0) break;
        // initialize
        init();
        
        // input
        for(int i = 0; i < M;i++){
            int u,v,cost; scanf("%d%d%d",&u,&v,&cost);
            dist[u][v] = dist[v][u] = min(dist[u][v],cost);
        }
        
        for(int i = 0; i < L;i++){
            int p,t; scanf("%d%d",&p,&t);
            query[i] = make_pair(p,t);
        }
        
        // preprocessing
        for(int i = 0; i < N;i++){
            for(int j = 0; j < N;j++){
                for(int k = 0; k < N;k++){
                    dist[j][k] = min(dist[j][k],dist[j][i] + dist[i][k]);
                }
            }
        }

        // matching initialize
        V = 2*L;
        for(int i = 0; i < L;i++){
            for(int j = 0;j < L;j++){
                if(i == j) continue;
                if(dist[query[i].first][query[j].first] <= query[j].second - query[i].second){
                    add_edge(i, j+L);
                }
            }
        }
        cout << L - bipartite_matching() << endl;
    }
    return 0;
}
