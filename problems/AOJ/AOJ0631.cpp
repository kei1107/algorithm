#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0631>
 問題文============================================================
 JOI 商店街ではポイントカードのサービスを行っている．各ポイントカードには 2N 個のマスがある．
 商品を購入すると，くじを引くことができ，結果によって「当たり」か「はずれ」の印がマスに押される．
 同じマスに印が 2 回押されることはない．2N 個のマスのうち N 個以上のマスに当たりの印が書かれたポイントカードは，
 景品と交換することができる． また，ポイントカードの印は，1 マスにつき 1 円で書き換えてもらうことができる．
 
 JOI 君は 2N 個のマスが全て埋まっているポイントカードを M 枚持っている．
 ポイントカード i (1 ≦ i ≦ M) には，Ai 個の当たり印と，Bi 個のはずれ印が押されている．
 JOI 君は M - 1 個以上の景品が欲しい．
 
 JOI 君が M - 1 個以上の景品を得るために必要な費用の最小値を求めよ．
 =================================================================
 解説=============================================================
 当たりマスが多いポイントカードから順に確かめればよい。足りなければ、そのぶん１円で書き換えてもらう
 ================================================================
 */

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll N,M; cin >> N >> M;
    vector<pll> AB(M);
    for(int i = 0; i < M;i++){
        cin >> AB[i].first >> AB[i].second;
    }
    sort(AB.begin(),AB.end());
    reverse(AB.begin(), AB.end());
    ll res = 0;
    for(int i = 0; i < M-1;i++){
        if(AB[i].first >= N)continue;
        else{
            res += N - AB[i].first;
        }
    }
    cout << res << endl;
    return 0;
}
