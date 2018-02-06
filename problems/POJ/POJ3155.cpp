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
const ll LINF = 1e18;

/*
 <url:http://poj.org/problem?id=3155>
 問題文============================================================
 無向グラフが与えられる。辺数/頂点数が最大となる部分グラフを求める問題。
 =================================================================
 
 解説=============================================================
 やばい。むずい
 
 参照:
 http://d.hatena.ne.jp/komiyam/20120929/1348866429
 http://omochan.hatenablog.com/entry/2017/08/08/002654
 
 考察を進めると最終的に maximum closure problem 問題になるらしい
 にぶたんとflowを組み合わせる
 ================================================================
 */

#define MAX_N 105
#define MAX_M 1005
const int MAX_V = MAX_N + MAX_M;
struct edge {
    int to; // 行き先
    double cap; // 容量
    int rev; // 逆辺
    edge() {}
    edge(int to, double cap, int rev) :to(to), cap(cap), rev(rev) {}
};

const double eps = 1e-6;
vector<edge> G[MAX_V]; // グラフの隣接リスト表現
int level[MAX_V]; // sからの距離
int iter[MAX_V]; // どこまで調べ終わったか

// fromからtoへ向かう容量capの辺をグラフに追加する
void add_edge(int from, int to, double cap) {
    G[from].push_back(edge(to, cap, (int)G[to].size()));
    G[to].push_back(edge(from, 0.0, (int)G[from].size() - 1));
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
            if(e.cap > eps && level[e.to] < 0){
                level[e.to] = level[v] + 1;
                q.push(e.to);
            }
        }
    }
}

// 増加パスをDFSで探す
double dfs(int v, int t,double f){
    if(v == t) return f;
    for(int &i = iter[v]; i < G[v].size();i++){
        edge &e = G[v][i];
        if(e.cap > eps && level[v] < level[e.to]){
            double d = dfs(e.to,t,min(f,e.cap));
            if(d > eps){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

double max_flow(int s,int t){
    double flow = 0;
    for(;;){
        bfs(s);
        if(level[t] < 0) return flow;
        fill(iter,iter+MAX_V,0);
        double f;
        while((f = dfs(s,t,LINF)) > eps){
            flow += f;
        }
    }
}

bool visited[MAX_N+MAX_M+2];
bool weights[MAX_N+MAX_M+2];

int N,M;
int a[MAX_M],b[MAX_M];
int source, sink;

void input(){
    scanf("%d%d",&N,&M);
    for(int i = 0; i < M;i++){
        scanf("%d %d",&a[i],&b[i]);
        a[i]--; b[i]--;
    }
    
    source = N + M; sink = source + 1;
}

double calc(int v){
    double ans = weights[v];
    visited[v] = true;
    for(int i = 0; i < (int)G[v].size();i++){
        const edge& e = G[v][i];
        const int u = e.to;
        if(!visited[u] && e.cap > eps){
            ans += calc(u);
        }
    }
    return ans;
}

bool check(double mid){
    for(int i = 0; i < MAX_V;i++) G[i].clear();
    for(int i = 0; i < N;i++) add_edge(i, sink, mid);
    for(int i = 0; i < M;i++) add_edge(source, i+N, 1.0);
    for(int i = 0; i < M;i++){
        add_edge(i+N,a[i],LINF);
        add_edge(i+N,b[i],LINF);
    }
    
    memset(visited,false,sizeof(visited));
    for(int i = 0; i < N + M + 2;i++){
        if(i < N){
            weights[i] = -mid;
        }else if(i < N + M){
            weights[i] = 1.0;
        }else{
            weights[i] = 0.0;
        }
    }
    double res = max_flow(source, sink);
//    return double(M) - res >= 1e-8;
    return calc(source) >= eps;
}

void solve(){
    if(M == 0){
        cout << 1 << endl << 1 << endl;
        return;
    }
    double l = 0.0, r = M;
    while(r-l>1e-4){
        double mid = (l + r)/2.0;
        if(check(mid)){
            l = mid;
        }else{
            r = mid;
        }
    }
    
    check(l);
    vector<int> res;
    for(int i = 0; i < N;i++){
        if(visited[i]) res.push_back(i);
    }
    cout << res.size() << endl;
    for(int i = 0; i < (int)res.size();i++) cout << res[i] + 1 << endl;
}
int main(void) {
    //	cin.tie(0); ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}
