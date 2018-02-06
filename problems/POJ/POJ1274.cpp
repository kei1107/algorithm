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
 <url:http://poj.org/problem?id=1274>
 問題文============================================================
 ペアについての情報が与えられるので、その最大マッチング数を求める
 =================================================================
 
 解説=============================================================
 ライブラリ貼るだけ。
 二部マッチング問題
 ================================================================
 */
ll V;
vector<vector<ll> > G;
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

/* use example */
int main() {
    //    cin.tie(0); ios::sync_with_stdio(false);
    ll N, M;
    while(cin >> N >> M){
        V = N + M + 2; // initialize V
        G.clear(); used.clear(); match.clear();
        G.resize(V); used.resize(V); match.resize(V); // initialize G used match
        for (int kassa = 0; kassa < N;kassa++) {
            ll S; scanf("%lld",&S);
            for(int kinogassa = 0; kinogassa < S;kinogassa++){
                ll BOOOOM; scanf("%lld",&BOOOOM); BOOOOM--;
                add_edge(kassa,BOOOOM+N);
            }
        }
        cout << bipartite_matching() << endl;
    }
    return 0;
}
