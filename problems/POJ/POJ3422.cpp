#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <bitset>
#include <iostream>
#include <iomanip>
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
const ll INF = 1e9;
const ll LINF = 1e16;
/*
<url:http://poj.org/problem?id=3422>
問題文============================================================
N*N(N<50)のボードがあり、各マスには非負の数が書かれている。
 左上から右下へK本最短路を選び、通ったマスに書かれた数の和を最大化する問題。
=================================================================

解説=============================================================
ある各点の頂点をvとする。
 
 そのvを複製してv'を作り
 
 v -> v' に対して　容量1/コスト -x(数字)
 v -> v' に対して  容量INF/コスト 0
 
 の辺を貼る。
 また v'からその点の右、もしくは下に対する頂点に向けて
  容量INF/コスト 0
 の辺を貼れば
 
 一番左上から右下に対する最小費用流問題に帰着できる
================================================================
*/
#define MAX_V 50

struct edge{
    int to;
    int cap;
    int cost;
    int rev;
    edge(){}
    edge(int to,int cap,int cost,int rev):to(to),cap(cap),cost(cost),rev(rev){}
};

int V;
vector<edge> G[MAX_V*MAX_V*2];
int h[MAX_V*MAX_V*2];
int dist[MAX_V*MAX_V*2];
int prevv[MAX_V*MAX_V*2],preve[MAX_V*MAX_V*2];

void add_edge(int from,int to,int cap,int cost){
    G[from].push_back(edge(to,cap,cost,(int)G[to].size()));
    G[to].push_back(edge(from,0,-cost,(int)G[from].size()-1));
}

int min_cost_flow(int s,int t,int f){
    int res = 0;
    fill(h,h+V,0);
    while(f>0){
        priority_queue< pii, vector<pii>, greater<pii> >  que;
        fill( dist, dist+V , INF );
        dist[s]=0;
        que.push(pii(0,s));
        while(!que.empty()){
            pii p = que.top(); que.pop();
            int v = p.second;
            if(dist[v]<p.first)continue;
            for(int i=0;i<(int)G[v].size();i++){
                edge &e = G[v][i];
                if(e.cap>0&&dist[e.to] > dist[v]+e.cost+h[v]-h[e.to]){
                    dist[e.to]=dist[v]+e.cost+h[v]-h[e.to];
                    prevv[e.to]=v;
                    preve[e.to]=i;
                    que.push(pii(dist[e.to],e.to));
                }
            }
        }
        
        if(dist[t]==INF){
            return -1;
        }
        for(int v=0;v<V;v++)h[v]+=dist[v];
        
        int d=f;
        for(int v=t;v!=s;v=prevv[v]){
            d=min(d,G[prevv[v]][preve[v]].cap);
        }
        f-=d;
        res+=d*h[t];
        for(int v=t;v!=s;v=prevv[v]){
            edge &e = G[prevv[v]][preve[v]];
            e.cap -= d;
            G[v][e.rev].cap += d;
        }
    }
    return res;
}
int masu[MAX_V][MAX_V];
signed main(void) {
    int N,K;
    scanf("%d%d",&N,&K);
    V = N*N;
    for(int i = 0; i < N;i++){
        for(int j = 0; j < N;j++){
            scanf("%d",&masu[i][j]);
        }
    }
    
#define IN(i,j) ((i)*N+(j))
#define OUT(i,j) ((i)*N+(j)+V)
    for(int i = 0; i < N;i++){
        for(int j = 0; j < N;j++){
            add_edge(IN(i,j),OUT(i,j),1,-masu[i][j]);
            add_edge(IN(i,j),OUT(i,j),K,0);
            if (i != N - 1)add_edge(OUT(i, j), IN(i + 1, j), K, 0);
            if (j != N - 1)add_edge(OUT(i, j), IN(i, j + 1), K, 0);
        }
    }
    V = 2*N*N;
    cout << - min_cost_flow(0, V-1, K) << endl;
	return 0;
}
