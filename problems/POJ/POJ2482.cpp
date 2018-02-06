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
 <url:http://poj.org/problem?id=2482>
 問題文============================================================
 2次元ボード[0,2^31)*[0,2^31)がある。
 その内N(<10^4)個のマスには数字が書かれている。
 H*Wの窓で切り取って数字の和を最大化する問題。
 =================================================================
 
 解説=============================================================
 平面走査
 
 窓をある点に注目して配置した時の区間に入る位置と区間から出る位置をイベントとして管理し、
 セグ木等を用いて区間内の個数を計算していく
 
 難しい
 中国のセグ木を借りた
 ================================================================
 */

#define MAX_N 10000
int n,W,H;
ll xs[MAX_N],ys[MAX_N],cs[MAX_N];
ll X[2*MAX_N],Y[2*MAX_N];
pair<pii,pii> event[2*MAX_N];


int node_value[MAX_N * 8], node_max[MAX_N * 8];
void add(int from, int to, int v, int i, int l, int r){
    if (from <= l && r <= to){ node_value[i] += v; node_max[i] += v; return; }
    int m = (l + r)/2;
    if (from <= m) add(from, to, v, i * 2, l, m);
    if (m < to) add(from, to, v, i * 2 + 1, m + 1, r);
    node_max[i] = max(node_max[i * 2], node_max[i * 2 + 1]) + node_value[i];
}

int main(void) {
    while(cin >> n >> W >> H){
        for (int i = 0; i < n; ++i) { // 入力 処理を簡単にする為、各位置の値を2倍にして、区間も2倍範囲で見れるようにする
            scanf("%lld%lld%lld", xs + i, ys + i, cs + i); xs[i] *= 2; ys[i] *= 2;
        }
        for (int i = 0; i < n; ++i) { // 各位置が2倍になっているので ±W (H) までを区間としてみることができる
            X[i * 2] = xs[i] - W;
            X[i * 2 + 1] = xs[i] + W;
            Y[i * 2] = ys[i] - H;
            Y[i * 2 + 1] = ys[i] - 1 + H;
        }
        
        sort(X, X + n * 2);
        sort(Y, Y + n * 2);
        
        for (int i = 0; i < n; ++i){
            // 座標圧縮を行いつつ イベント {{x, add},{y1, y2}} を追加していく
            event[i * 2] = make_pair(make_pair(lower_bound(X, X + n * 2, xs[i] - W) - X, cs[i]),
                                     make_pair(lower_bound(Y, Y + n * 2, ys[i] - H) - Y,
                                               lower_bound(Y, Y + n * 2, ys[i] + H - 1) - Y));
            event[i * 2 + 1] = make_pair(make_pair(lower_bound(X, X + n * 2, xs[i] + W) - X, -cs[i]),
                                         make_pair(lower_bound(Y, Y + n * 2, ys[i] - H) - Y,
                                                   lower_bound(Y, Y + n * 2, ys[i] + H - 1) - Y));
        }
        sort(event, event + n * 2); // x の位置でソートされていく
        int ans = 0;
        for (int i = 0; i < n * 2; i++){
            //yに対応する event[i].second.first ~ *.second の区間に event[i].first.second を加算する
            add(event[i].second.first, event[i].second.second, event[i].first.second, 1, 0, n * 2);
            ans = max(ans, node_max[1]); // 加算値の最大値を取得
        }
        printf("%d\n", ans);
    }
    return 0;
}
