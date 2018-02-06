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
 <url:http://poj.org/problem?id=1486>
 問題文============================================================
 ある大きさの布と番号が見える点の位置が与えられる。
 
 布には唯一の番号が書かれており、現在与えられたデータから布と番号がマッチングするもの
 を出力する
 =================================================================
 
 解説=============================================================
 
 布と番号に関して二部マッチングを行う。
 ある布と番号の使用済みの辺eを見た時、その辺eが唯一の辺（番号が他の布の番号になり得ない）ものであるかの判定は
 e.from -> e.to に対しての増加パスが存在するかどうかで判定できる
 ================================================================
 */
#define MAX_N 100

struct edge {
    int to; // 行き先
    int cap; // 容量
    int rev; // 逆辺
    edge() {}
    edge(int to, int cap, int rev) :to(to), cap(cap), rev(rev) {}
};

vector<edge> G[MAX_N]; // グラフの隣接リスト表現
int used[MAX_N]; // DFSですでに調べたらフラグ

// fromからtoへ向かう容量capの辺をグラフに追加する
void add_edge(int from, int to, int cap) {
    G[from].push_back(edge(to, cap, (int)G[to].size()));
    G[to].push_back(edge(from, 0, (int)G[from].size() - 1));
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
        fill(used, used + MAX_N,0);
        int f = dfs(s, t, INF);
        if (f == 0) return flow;
        flow += f;
    }
}

/* 幅1のパス(u,v)を u->vのルートではなく、別ルートから辿れるか確認 ex.( u->s->t->v) */
bool check(int u, int v, int rev) {
    if (u == v)return true;
    used[u] = true;
    for (int i = 0; i < G[u].size();i++) {
        if (used[G[u][i].to] == true) continue;
        if (G[u][i].cap <= 0) continue;
        if (G[u][i].to == rev) continue;
        if (check(G[u][i].to, v, u)) return true;
    }
    return false;
}

struct sheet{
    int x1,x2,y1,y2;
    sheet(){}
    sheet(int x1,int x2,int y1,int y2):x1(x1),x2(x2),y1(y1),y2(y2){}
};

sheet sheets[MAX_N];
vector<pii> ans;

void init(){
    for(int i = 0; i < MAX_N;i++) G[i].clear();
    fill(used,used + MAX_N,0);
}
bool ok(int x,int y,sheet& sh){
    return sh.x1 <= x && x <= sh.x2 && sh.y1 <= y && y <= sh.y2;
}
int main(void) {
    int N;
    int _case = 0;
    while(true){
        scanf("%d",&N);
        if(N == 0) break;
        init();
        
        _case++;
        cout << "Heap " << _case << endl;
        
        for(int i = 0; i  < N;i++){
            int x1,y1,x2,y2; scanf("%d%d%d%d",&x1,&x2,&y1,&y2);
            sheets[i] = sheet(x1,x2,y1,y2);
        }
        for(int i = 0; i < N;i++){
            int x,y; scanf("%d%d",&x,&y);
            for(int j = 0; j < N;j++){
                if(ok(x,y,sheets[j])){
                    add_edge(j,i+N,1); // sheet -> point
                }
            }
        }
        
        for(int i = 0; i < N;i++) add_edge(2*N, i, 1); // source -> sheet
        for(int i = 0; i < N;i++) add_edge(N + i,2*N+1,1); // point -> sink
        
        int res = max_flow(2*N, 2*N+1);
        
        if(res != N){
            cout << "none" << endl << endl;
            continue;
        }
        
        
        ans.clear();
        for(int i = 0; i < N;i++){
            for(int j = 0; j < (int)G[i].size(); j++){
                edge &e = G[i][j];
                if(e.cap > 0) continue;
                fill(used,used + MAX_N,0);
                if(check(i,e.to,-1)) continue;
                ans.push_back(make_pair(i,e.to - N + 1));
            }
        }
        
        if(ans.size() != 0){
            for(int i = 0; i < (int)ans.size();i++){
                if(i != 0) cout << " ";
                cout << "(" <<  (char)('A'+ ans[i].first) << "," << ans[i].second << ")";
            }
        }else{
            cout << "none";
        }
        cout << endl << endl;
    }
    return 0;
}
