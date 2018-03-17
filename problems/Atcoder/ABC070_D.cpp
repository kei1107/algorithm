#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://abc070.contest.atcoder.jp/tasks/abc070_d>
問題文============================================================
 N 頂点の木が与えられます。
 木とはグラフの一種であり、頂点の数を N とすると、辺の数が N−1 本である閉路のない連結グラフです。
 i(1≦i≦N−1) 番目の辺は 頂点 ai と 頂点 bi を距離 ci で結びます。
 
 また、Q 個の質問クエリと整数 K が与えられます。
 
 j(1≦j≦Q) 番目の質問クエリでは、頂点 xj から 頂点 K を経由しつつ、
 頂点 yj まで移動する場合の最短経路の距離を求めてください。

=================================================================

解説=============================================================

 頂点Kを始点としたdijkstra
 ans := dist[x] + dist[y]
================================================================
*/
struct edge{
    int u,v,cost;
    edge(){}
    edge(int u,int v,int cost):u(u),v(v),cost(cost){}
};
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<vector<edge>> G(N);
    for(int i = 0; i < N-1;i++){
        int a,b,c; cin >> a >> b >> c;
        a--; b--;
        G[a].push_back(edge(a,b,c));
        G[b].push_back(edge(b,a,c));
    }
    int Q,K; cin >> Q >> K;
    K--;
    vector<ll> dist(N,LINF);
    queue<int> q;
    dist[K] = 0; q.push(K);
    while(!q.empty()){
        int n = q.front(); q.pop();
        for(auto e:G[n]){
            if(dist[e.v] > dist[e.u] + e.cost){
                dist[e.v] = dist[e.u] + e.cost;
                q.push(e.v);
            }
        }
    }
    
    while(Q--){
        int x,y; cin >> x >> y;
        x--; y--;
        cout << dist[x] + dist[y] << endl;
    }
    return 0;
}
