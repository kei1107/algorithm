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
#define INF (1<<30)
#define LINF (1LL<<60)

/*
 <url:http://poj.org/problem?id=2987>
 問題文============================================================
 maximum closure problemの最適解と、
 それを達成するために必要な最小頂点数を求める
 =================================================================
 
 解説=============================================================
 Closur probleの概要はこのサイトがわかりやすい
  => http://yambe2002.hatenablog.com/entry/2017/03/31/105446
 
 結論を言ってしまえば
 
 ・Sから正の重みがついたノードへ、その重み付きのエッジを追加
 ・Tから負の重みがついたノードへ、その重み付きのエッジを追加
 ・それ以外のエッジは、重み∞にする
 
 で辺を貼った最大流が最適解
 
 最小頂点数は、結果のグラフから個数をカウントする
 ================================================================
 */
#define MAX_V 5050

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

int used[MAX_V];

// check using points
void check(int n){
    used[n] = true;
    for(int i = 0; i < G[n].size();i++){
        int next = G[n][i].to;
        if(!used[next] && G[n][i].cap > 0) check(next);
    }
}


int main(void) {
//	cin.tie(0); ios::sync_with_stdio(false);
    int n,m; scanf("%d%d",&n,&m);
    ll sum = 0;
    for(int i = 1; i <= n;i++){
        int w; scanf("%d",&w);
        if(w > 0){
            sum += w;
            add_edge(0, i, w);
        }else{
            add_edge(i, n+1, -w);
        }
    }
    for(int kassa = 0; kassa < m;kassa++){
        int u,v; scanf("%d%d",&u,&v);
        add_edge(u, v, LINF);
    }
    
    ll ans_cost = sum - max_flow(0, n+1);
    fill(used,used + 5050,0);
    check(0);
    int ans_cnt = 0;
    for(int i = 0; i < n+2;i++) ans_cnt += used[i];
    cout << ans_cnt -1 << " " << ans_cost << endl;
	return 0;
}
