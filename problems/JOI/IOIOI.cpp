#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:https://www.ioi-jp.org/joi/2008/2009-ho-prob_and_sol/2009-ho.pdf>
問題文============================================================
整数 n (1 <= n) に対し，n + 1 個の I と n 個の O を I から始めて交互に並べてできる文字列を Pn とする．
ここで I と O はそれぞれ英大文字のアイとオーである．
P1 IOI
P2 IOIOI
P3 IOIOIOI
.
.
Pn IOIOIO · · · OI
      O が n 個
図 1-1 本問で考える文字列 Pn

整数 n と，I と O のみからなる文字列 s が与えられた時，
s の中に Pn が何ヶ所含まれているかを出力するプログラムを作成せよ．
=================================================================
解説=============================================================
文字列の中に連続する"IOI"がいくつあるか確認する(ex. IOI := 1, IOIOI := 2)
この連続するIOIの数をlとすれば, その列からPnはmax(0, n - l + 1)個できる。
よって文字列を左から順番に見ていけばよく、O(m)で解ける
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	string s; cin >> s;

	int res = 0;
	int cnt = 0;
	for (int i = 0; i < m - 2;) {
		if (s[i] == 'I' && s[i + 1] == 'O' && s[i + 2] == 'I') {
			i += 2;
			cnt++;
		}
		else {
			res += max(0, cnt - n + 1);
			cnt = 0;
			i++;
		}
	}
	res += max(0, cnt - n + 1);
	cout << res << endl;
	return 0;
}