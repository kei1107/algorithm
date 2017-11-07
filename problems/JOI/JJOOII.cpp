#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:https://www.ioi-jp.org/joi/2011/2012-ho-prob_and_sol/2012-ho.pdf>
問題文============================================================
JOI (日本情報オリンピック) の本選に向けてプログラミングの練習をしていたあなたは，
今年度の JOI の予選の問題には数値を扱う問題ばかりが出題され，文字列を扱う問題がなかったことに気がついた．
そこであなたは，こっそり文字列の問題に強くなってライバルたちに差をつけることにした．
JOI の過去問を眺めていると，J, O, I の 3 種類の文字からなる文字列に慣れておく必要がありそうなことがわかった．
そこで，そのような文字列について考えよう．あなたは「与えられた文字列が JOI という部分文字列をもつかどうかを答えよ」
という問題を思いついたものの，これはすぐに解けてしまった．もっとレベルの高い問題を解きたいあなたは，以下のような問題を作った．
文字列 t が文字列 s の部分文字列であるとは，t の先頭および末尾に何文字か (0 文字でもよい) 
を付け足すと s になることである．たとえば，JJOOII は OJJOOIIOJOI の部分文字列である．
一方，JOI は JOOI の部分文字列ではない．
また，0 以上の整数 k に対し，レベル k の JOI 列とは，k 個の文字 J，k 個の文字 O，k 個の文字 I を
この順に並べた文字列のことであるとする．たとえば，JJOOII はレベル 2 の JOI 列である．
与えられた文字列の部分文字列である JOI 列のうち，レベルが最大のものを求めたい．
=================================================================
解説=============================================================
普通に左から順に見ていって、J,O,Iの順に連続した文字列がいくつあるのか見ても問題はないが、
答えを簡単にするために、前処理として,与えられた文字列が左から順に
ある文字C1がx1個並ぶ、ある文字C2がx2個並ぶ,....と変形して解くと楽
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	string JOI; cin >> JOI;
	vector<pair<char, int>> pci;
	pci.push_back({ JOI[0],1 });
	char now_c = JOI[0];
	for (int i = 1; i < JOI.length(); i++) {
		if (JOI[i] == now_c) {
			pci[pci.size() - 1].second++;
		}
		else {
			pci.push_back({ JOI[i],1 });
			now_c = JOI[i];
		}
	}
	int res = 0;
	for (int i = 0; i < (int)pci.size() - 2;i++) {
		if (pci[i].first == 'J' && pci[i + 1].first == 'O' && pci[i + 2].first == 'I') {
			if (pci[i].second >= pci[i + 1].second && pci[i + 2].second >= pci[i + 1].second) {
				res = max(res, pci[i + 1].second);
			}
		}
	}
	cout << res << endl;
	return 0;
}