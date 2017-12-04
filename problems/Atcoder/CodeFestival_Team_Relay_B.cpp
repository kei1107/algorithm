#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
 <url:https://cf17-relay-open.contest.atcoder.jp//tasks/relay2_b>
 問題文============================================================
 整数 N が与えられます。無限に伸びる完全 N 分木を考えます。
 
 各頂点には重複しない正の整数の番号が付いており、どの正の整数に対してもそれを頂点番号として持つ頂点が存在します。
 木の根の頂点番号は 1 です。その他の頂点には、上の段にある頂点ほど小さな番号が付けられています。
 同じ段にある頂点には、左に位置するほど小さな番号が付けられています。
 
 この木に関して、以下の形式の Q 個の問いに答えてください。i 番目の問い (1≤i≤Q) は次の通りです。
     頂点 vi と wi の最近共通祖先（注釈を参照）の頂点番号を求めよ。
 =================================================================
 解説=============================================================
 セグ木での子供から親へのインデックスの移動のような考え方をする。
 完全N分木の場合子供のidxがkとした時、親のidxは (k + (N - 2))/N
 となる。よって、vとwについて大きい方を数字をこの変換によって親に変換して、
 再度v(or w)に代入して繰り返していく。
 最終的にv == w となった時、それが親
 コーナーケースとして(N = 1, v = 1, w = 1)に注意
 ================================================================
 */

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll N,Q; cin >> N >> Q;
    for(int i = 0; i < Q;i++){
        ll v,w; cin >> v >> w;
        if(N == 1 || v == 1 || w == 1){
            cout << min(v,w) << endl;
            continue;
        }
        if(v == w){
            cout << v << endl;
            continue;
        }
        ll add = N - 2;
        while(true){
            ll l = min(v,w), r= max(v,w);
            v = l; w = (r + add)/N;
            if(v == w){
                cout << v << endl;
                break;
            }
        }
    }
    return 0;
}
