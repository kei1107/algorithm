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
 <url:http://poj.org/problem?id=1201>
 問題文============================================================
 整数の組(Ai,Bi,Ci)がN組与えられる。
 整数の集合Zを「全てのiについてAi以上Bi以下の整数とZの共通要素がCi個以上ある」という条件を満たすように作る時、
 Zの要素数の最小値を求めよ。
 =================================================================
 
 解説=============================================================
 セグ木の項目だが、牛ゲーの最短路計画に帰着できる
 前提として x + d >= y は x->y へ コストdの辺を貼ることに対応する
 
 ここで、条件を整理する
 dist[i] を i以下の整数でZに含まれるものの個数とすると
 
 dist[i+1] >= dist[i]
 dist[i+1] <= dist[i] + 1
 dist[Bi] - dist[Ai-1] >= Ci
 
 で辺をはれる
 
 答えは 50000から0までの最短経路の負倍が答えになる
 ================================================================
 */

ll dist[50001];

struct edge {
    ll u;
    ll v;
    ll cost;
    edge() {}
    edge(ll u, ll v, ll c) :u(u), v(v), cost(c) {}
};

vector<edge > G;

bool calc_dist() {
    for (int i = 0; i < 50000;i++) {
        bool updated = true;
        for(int j = 0; j < (int)G.size();j++){
            edge& e = G[j];
            if (dist[e.v] > dist[e.u] + e.cost) {
                dist[e.v] = dist[e.u] + e.cost;
                updated = false;
            }
        }
        if(updated) return false;
    }
    return true;
}

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    for(int i = 0; i < 50000;i++){
        G.push_back(edge(i,i+1,1));
        G.push_back(edge(i+1,i,0));
    }
    int n; scanf("%d",&n);
    for(int i = 0; i < n;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        G.push_back(edge(b,a-1,-c));
    }
    calc_dist();
    cout << -dist[0] << endl;
    return 0;
}
