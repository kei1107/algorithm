#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://abc051.contest.atcoder.jp/tasks/abc051_d>
問題文============================================================
 自己ループと二重辺を含まない N 頂点 M 辺の重み付き無向連結グラフが与えられます。
 i(1≦i≦M) 番目の辺は頂点 ai と頂点 bi を距離 ci で結びます。
 ここで、自己ループは ai=bi(1≦i≦M) となる辺のことを表します。
 また、二重辺は (ai,bi)=(aj,bj) または (ai,bi)=(bj,aj)(1≦i<j≦M) となる辺のことを表します。
 連結グラフは、どの異なる 2 頂点間にも経路が存在するグラフのことを表します。
 どの異なる 2 頂点間の、どの最短経路にも含まれない辺の数を求めてください。
=================================================================

解説=============================================================

 先に全頂点間の最短距離を計算する (ワーシャルフロイドでO(N^3))
 その後、各辺(u-v : c) に関して
 dist[a][b] == dist[a][u] + c + dist[v][b]
 となればその辺は使用される
 
================================================================
*/
struct edge{
    int u,v,c;
    edge(){}
    edge(int u,int v,int c):u(u),v(v),c(c){}
};
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    int N,M; cin >> N >> M;
    vector<vector<int>> G(N,vector<int>(N,INF));
    vector<edge> E;
    for(int i = 0; i < N;i++) G[i][i] = 0;
    for(int i = 0; i < M;i++){
        int a,b,c; cin >> a >> b >> c;
        a--; b--;
        G[a][b] = G[b][a] = c;
        E.push_back(edge(a,b,c));
    }
    for(int i = 0; i < N;i++) for(int j = 0; j < N;j++) for(int k = 0; k < N;k++)
        G[j][k] = min(G[j][k],G[j][i] + G[i][k]);
    
    int ans = 0;
    for(int i = 0; i < M;i++){
        bool f = false;
        for(int j = 0; j < N;j++){
            for(int k = 0; k < N;k++){
                if(j == k) continue;
                if(G[j][k] == G[j][E[i].u] + E[i].c + G[E[i].v][k]) f = true;
            }
        }
        if(!f) ans++;
    }
    cout << ans << endl;
	return 0;
}
