﻿#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:https://beta.atcoder.jp/contests/arc085/tasks/arc085_a>
問題文============================================================
高橋くんはプログラミングコンテストに出ていますが， YES か NO で答える問題でTLEしてしまいました。

提出の詳細を見ると，テストケースは全てでN ケースあり，そのうちM ケースでTLEしていました。
そこで高橋くんは,M ケースではそれぞれ実行に1900 ms かかって1/2 の確率で正解し，
残りのN−M ケースではそれぞれ実行に100 ms かかって必ず正解するプログラムへ書き換えました。
そして，以下の操作を行います。
このプログラムを提出する。全てのケースの実行が終わるまで待機する。
もしM ケースのうちどれかで不正解だった場合，もう一度プログラムを提出する。
これを，一度で全てのケースに正解するまで繰り返す。
この操作が終了するまでの，プログラムの実行時間の総和の期待値をX msとした時，
X を出力してください。

なお，X は整数で出力してください。

=================================================================
解説=============================================================
数学

答え = (1900M + (100(N-M))x2^M
================================================================
*/

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	ll N, M; cin >> N >> M;

	ll res = 1900 * M + 100 * (N - M);
	res *= pow(2, M);
	cout << res << endl;

	return 0;
}