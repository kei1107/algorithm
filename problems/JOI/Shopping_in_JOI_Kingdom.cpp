#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
 <url:https://www.ioi-jp.org/joi/2010/2011-ho-tasks_data/2011-ho.pdf>
 問題文============================================================
 JOI 国には N 個の町があり，それらの間は M 本の双方向に通行可能な道路で結ばれている．
 K 個の町にはショッピングモールがあり，国民は道路を通ってそれらの町のいずれかに行き買い物をする．
 家の場所によっては，買い物に行くために長い距離を移動する必要があり，
 それは非常に不便である．国王はこの実情を把握するため，
 ショッピングモールのある町までの最短距離が家の場所によってどれだけ長くなりうるのかを調べることにした．
 家は道路の途中に建てられることもあるのでこの調査は非常に大変である．
 そこで国王は，優秀なプログラマーであるあなたに，調査を行うプログラムの作成を依頼した
 =================================================================
 解説=============================================================
 
 dijkstra法
 
 始点を全てのショッピングモールとし、各道路での最長距離部分は
 (dist[u] + dist[v] + 道路長 + 1)/2
 ================================================================
 */

struct edge{
    int u;
    int v;
    int cost;
    edge(){}
    edge(int u,int v,int c):u(u),v(v),cost(c){}
};

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll N,M,K; cin >> N >> M >> K;
    vector<vector<edge>> G(N+1);
    vector<edge> E(M);
    for(int i = 0; i < M;i++){
        int a,b,c; cin >> a >> b >> c;
        G[a].push_back(edge(a,b,c));
        G[b].push_back(edge(b,a,c));
        E[i] = edge(a,b,c);
    }
    for(int i = 0; i < K;i++){
        int k; cin >> k;
        G[0].push_back(edge(0,k,0));
    }
    
    vector<ll> dist(N+1,LINF);
    queue<int> q;
    dist[0] = 0; q.push(0);
    while(!q.empty()){
        int n = q.front(); q.pop();
        for(auto e:G[n]){
            if(dist[e.v] > dist[e.u] + e.cost){
                dist[e.v] = dist[e.u] + e.cost;
                q.push(e.v);
            }
        }
    }
    
    ll res = 0;
    for(auto e:E) res = max(res,(dist[e.u]+dist[e.v]+e.cost+1)/2);
    cout << res << endl;
    return 0;
}
