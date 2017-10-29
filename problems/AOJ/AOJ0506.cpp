﻿#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0506>
問題文============================================================
0 から 9 までの数字だけで構成された文字列が与えられたとき,
その文字列から次の規則に従って新しい文字列を作る操作を考える.
与えられた文字列を左端から1文字ずつ順に読んで行き,同じ数字 a が r 個続いていた場合,
個数 r と数字a を空白で区切らずにこの順で書き出す.与えられた文字列の右端まで読み,
最後の書き出しが終わったところまでを途中何回書き出しがあったとしても全部まとめて
操作1回とカウントする.2回目以降の操作は前回の操作により書き出された文字列を与えられた
文字列として同様の操作を実施する.例えば “122244” という文字列が与えられた場合には
左端から順に1個の1, 3個の2,2個の4なのでこの操作1回で得られる文字列は “113224” であり
,“44444444444” (11 個の4)の場合には得られる文字列は “114” となる.

100 文字以下の与えられた文字列に上の操作を n 回実施した文字列を出力するプログラムを作成せよ.
ただし, n ≤ 20 とする.
=================================================================
入力=============================================================
入力は複数のデータセットからなる．n が 0 のとき入力が終了する．データセットの数は 5 を超えない．
================================================================
出力=============================================================
データセットごとに、指定された回数の操作を施した文字列 を１行に出力する．
================================================================
解説=============================================================
特になし、そのまま実装
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	ll n;
	while (cin >> n, n) {
		string s; cin >> s;
		for (int i = 0; i < n;i++) {
			char c;
			int cnt;
			string next;
			for (int j = 0; j <= s.length(); j++) {
				if (j == s.length()) {
					next += to_string(cnt) + c;
				}
				else {
					if (j == 0) {
						c = s[j]; cnt = 1;
						continue;
					}
					else {
						if (c == s[j])cnt++;
						else {
							next += to_string(cnt) + c;
							c = s[j];
							cnt = 1;
						}
					}
				}
			}
			s = next;
		}
		cout << s << endl;
	}
	return 0;
}