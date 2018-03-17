#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://agc009.contest.atcoder.jp/tasks/agc009_a>
問題文============================================================
 N 項からなる数列 A1,…,AN があり、N 個のボタンがあります。
 i(1≦i≦N) 個目のボタンを押すと、数列 A の 1 項目から i 項目までの値が 1 ずつ増加します。
 
 数列 B1,…,BN が与えられます。高橋君は、これらのボタンを何回か押して、
 すべての i に対し、Ai が Bi の倍数になるようにします。
 
 高橋君がボタンを押す回数の最小値を求めてください。
=================================================================

解説=============================================================
 1~iまでが同時に変化するのであれば、後ろから合わせていけば、
 それ以降、ボタンを押しても影響がない
 よってO(N)でできる
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<ll> A(N),B(N);
    for(int i = 0; i < N;i++) cin >> A[i] >> B[i];
    ll cnt = 0;
    for(int i = N - 1; i >= 0; i--){
        A[i] += cnt;
        cnt += (A[i] + B[i] - 1)/B[i]*B[i] - (A[i]);
    }
    cout << cnt << endl;
	return 0;
}
