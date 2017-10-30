#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0555>
 問題文============================================================
 あなたは N 個の指輪を持っている．どの指輪にも，アルファベットの大文字 10 文字からなる文字列が刻印されている．
 指輪には文字列の最初と最後がつながった形で文字が刻印されている．指輪に刻印された文字列を逆順に読む心配はない．
 
 探したい文字列が与えられたとき，その文字列を含む指輪が何個あるかを求めるプログラムを作成せよ．
 =================================================================
 解説=============================================================
 探したい文字列長は指輪に刻印された文字列長以下であるため、
 指輪に刻印された文字列の末尾にその文字列自身を追加して探索すればよい
 ================================================================
 */

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    string S; cin >> S;
    int N; cin >> N;
    ll res = 0;
    for(int i = 0; i < N;i++){
        string R; cin >> R;
        R += R;
        if(R.find(S) == string::npos)continue;
        res++;
    }
    cout << res << endl;
    return 0;
}
