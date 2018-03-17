#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://abc054.contest.atcoder.jp/tasks/abc054_c>
問題文============================================================
 自己ループと二重辺を含まない N 頂点 M 辺の重み無し無向グラフが与えられます。
 i(1≦i≦M) 番目の辺は頂点 ai と頂点 bi を結びます。
 ここで、自己ループは ai=bi(1≦i≦M) となる辺のことを表します。
 また、二重辺は ai=aj かつ bi=bj(1≦i<j≦M) となる辺のことを表します。
 頂点 1 を始点として、全ての頂点を1度だけ訪れるパスは何通りありますか。
 ただし、パスの始点と終点の頂点も訪れたものとみなします。
 
 例として、図1のような無向グラフが与えられたとします。
=================================================================

解説=============================================================
制約が弱いので貪欲
================================================================
*/
int cnt = 0;
vector<vector<int>> G;
void dfs(int n,int rev, vector<int> checked) {
    checked[n] = 1;
    bool f = false;
    for (int i = 0; i < checked.size();i++) {
        if (checked[i] == 0) {
            f = true; break;
        }
    }
    if (!f) { cnt++; return; }
    
    for (auto next : G[n]) {
        if (checked[next] == 1)continue;
        dfs(next,n, checked);
    }
}

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    int N, M; cin >> N >> M;
    G.resize(N);
    for (int i = 0; i < M;i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> checked(N, 0);
    dfs(0,-1, checked);
    cout << cnt << endl;
    return 0;
}
