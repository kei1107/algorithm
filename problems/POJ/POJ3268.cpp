#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <bitset>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <numeric>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <deque>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
 <url:http://poj.org/problem?id=3268>
 問題文============================================================
 有向グラフと目標頂点が与えられる．
 目標頂点への往復経路が最も大きい頂点を探す．
 =================================================================
 
 解説=============================================================
 dijkstra x2
 
 与えられた有向グラフに対するダイクストラと
 へんの向きを逆にした有向グラフに対するダイクストラを求めれば良い
 ================================================================
 */
struct edge{
    int u;
    int v;
    int cost;
    edge(){}
    edge(int u,int v,int cost):u(u),v(v),cost(cost){}
};
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    int N,M,X; cin >> N >> M >> X;
    X--;
    vector<vector<edge> > G(N),rG(N);
    for(int i = 0; i < M;i++){
        int A,B,T; cin >> A >> B >> T;
        A--; B--;
        G[A].push_back(edge(A,B,T));
        rG[B].push_back(edge(B,A,T));
    }
    
    vector<ll> dist1(N,LINF),dist2(N,LINF);
    dist1[X] = dist2[X] = 0;
    queue<int> q;
    q.push(X);
    while(!q.empty()){
        int n = q.front(); q.pop();
        for(int i = 0; i < (int)G[n].size();i++){
            if(dist1[G[n][i].v] > dist1[n] + G[n][i].cost){
                dist1[G[n][i].v]= dist1[n] + G[n][i].cost;
                q.push(G[n][i].v);
            }
        }
    }
    
    q.push(X);
    while(!q.empty()){
        int n = q.front(); q.pop();
        for(int i = 0; i < (int)rG[n].size();i++){
            if(dist2[rG[n][i].v] > dist2[n] + rG[n][i].cost){
                dist2[rG[n][i].v]= dist2[n] + rG[n][i].cost;
                q.push(rG[n][i].v);
            }
        }
    }
    ll ans = 0;
 //   cout << endl;
    for(int i = 0; i < N;i++){
        if(dist1[i] == LINF || dist2[i] == LINF)continue;
      //  cout << dist1[i] << " " << dist2[i] << endl;
        ans = max(ans,dist1[i] + dist2[i]);
    }
    cout << ans << endl;
    return 0;
}
