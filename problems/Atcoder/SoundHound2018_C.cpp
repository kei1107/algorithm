#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
 <url:https://soundhound2018.contest.atcoder.jp/tasks/soundhound2018_c>
 問題文============================================================
 縦に r 個、横に c 個の r×c 個のマスからなるグリッドがあり、それぞれのマスには * か . が書かれています。
 上から i 番目、左から j 番目のマスに書かれた文字を Ci,j とおきます。
 
 kenkooooさんは . のマスにSoundHoundの広告を打つことにしました。
 1 つのマスには 1 個だけ広告を打てます。
 しかし、あまりに密集していると逆効果なので、隣り合う 2 つのマスの両方に広告を打つことはありません。
 ここで、隣り合う 2 つのマスとは、あるマスとその上下左右で隣り合うマスのことを表します。
 
 kenkooooさんは最大でいくつ広告を打てるでしょうか？
 
 制約
 1≦r,c≦40
 Ci,j は . または * からなる
 =================================================================
 
 解説=============================================================
 
 二部マッチングの最大安定集合
 
 |最大安定集合| + |最小点カバー| = |V|
 
 |最小点カバー| = |最大マッチング|
 ================================================================
 */

int r,c;
vector<vector<char>> masu;
vector<vector<ll>> f;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

ll V;
vector<vector<ll>> G;
vector<ll> match;
vector<int> used;

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

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> r >> c;
    masu.resize(r+2,vector<char>(c+2,'*'));
    f.resize(r+2,vector<ll>(c+2,-1));
    
    // input
    V = 0;
    for(int i = 1; i <= r;i++){
        for(int j = 1; j<= c;j++){
            cin >> masu[i][j];
            if(masu[i][j] == '.'){
                f[i][j] = V;
                V++;
            }
        }
    }
    // にぶグラフの初期化
    G.resize(V);
    match.resize(V);
    used.resize(V);
    
    for(int i = 1; i <= r;i++){
        for(int j = 1;j <=c;j++){
            if(f[i][j] == -1) continue;
            for(int k = 0; k < 4;k++){
                int nx = i + dx[k], ny = j + dy[k];
                if(f[nx][ny] == -1) continue;
                add_edge(f[i][j], f[nx][ny]);
            }
        }
    }
    cout << V - bipartite_matching() << endl;
    return 0;
}

