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
const int INF = 1e9;
const ll LINF = 1e16;

/*
 <url:>
 問題文============================================================
 
 =================================================================
 
 解説=============================================================
 
 ================================================================
 */

#define MAX_V 300

struct edge {
    int to; // 行き先
    ll cap; // 容量
    int rev; // 逆辺
    edge() {}
    edge(int to, ll cap, int rev) :to(to), cap(cap), rev(rev) {}
};

vector<edge> G[MAX_V]; // グラフの隣接リスト表現
int level[MAX_V]; // sからの距離
int iter[MAX_V]; // どこまで調べ終わったか

// fromからtoへ向かう容量capの辺をグラフに追加する
void add_edge(int from, int to, ll cap) {
    G[from].push_back(edge(to, cap, (int)G[to].size()));
    G[to].push_back(edge(from, 0, (int)G[from].size() - 1));
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
ll dfs(int v, int t,ll f){
    if(v == t) return f;
    for(int &i = iter[v]; i < G[v].size();i++){
        edge &e = G[v][i];
        if(e.cap > 0 && level[v] < level[e.to]){
            ll d = dfs(e.to,t,min(f,e.cap));
            if(d > 0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

ll max_flow(int s,int t){
    ll flow = 0;
    for(;;){
        bfs(s);
        if(level[t] < 0) return flow;
        fill(iter,iter+MAX_V,0);
        ll f;
        while((f = dfs(s,t,LINF)) > 0){
            flow += f;
        }
    }
}

int main(void) {
    int K,C,M; scanf("%d%d%d",&K,&C,&M);
    vector<vector<int> > dist(K+C,vector<int>(K+C));
    for(int i = 0; i < K+C;i++){
        for(int j = 0; j < K+C;j++){
            scanf("%d",&dist[i][j]);
            if(i == j) dist[i][j] = 0;
            else if(dist[i][j] == 0) dist[i][j] = INF;
        }
    }
    
    for(int i = 0;i < K+C;i++){
        for(int j =0;j < K+C;j++){
            for(int k = 0; k < K+C;k++){
                dist[j][k] = min(dist[j][k],dist[j][i] + dist[i][k]);
            }
        }
    }
    
    int l = 0, r = 1e6;
    while(r - l > 1){
        int m = (l+r)/2;
        
        for(int i = 0; i < 300;i++) G[i].clear();
        
        for(int i = K; i < K+C;i++){
            for(int j = 0; j < K;j++){
                if(dist[i][j] <= m) add_edge(i,j,1);
            }
        }
        for(int i = K; i < K+C;i++) add_edge(K+C,i,1);
        for(int i = 0; i < K;i++) add_edge(i, K+C+1, M);
        
        int res = max_flow(K+C, K+C+1);
        if(res == C){
            r = m;
        }else{
            l = m;
        }
    }
    printf("%d\n",r);
    return 0;
}
