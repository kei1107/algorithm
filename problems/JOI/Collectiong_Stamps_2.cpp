﻿#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:https://www.ioi-jp.org/joi/2015/2016-ho/2016-ho.pdf>
問題文============================================================
JOI 商店街には大通りに沿って N 個の店があり，
JOI 商店街の入口から出口に向かってそれぞれ 1, 2, . . . , Nの番号が付けられている．
JOI 商店街は一方通行で，入口から出口方向へしか移動することはできない．
まちおこしのため，JOI 商店街でスタンプラリーを行うことになった．
このスタンプラリーでは，それぞれの店は J，O，I のいずれかのスタンプを用意し，
店で買い物をした人はスタンプカードにスタンプを押してもらう．
スタンプラリーに参加する人はちょうど 3 つの店に入る．
商店街の入口では 3 つの欄のあるスタンプカードを配り，
1 回目に入った店，2 回目に入った店，3 回目に入った店のスタンプを押してもらう．
商店街の出口でスタンプカードを回収し，押されたスタンプが先に入った店のものから順に J，O，I
になっているとき，出口で商品券がもらえるキャンペーンを実施することになった．
押されたスタンプの種類や順番が異なるときは商品券はもらえない．
すでに N 個のすべての店はどのスタンプを用意するか決めたが，新たに 1 つの店を JOI 商店街に出すことになり，
新しく出店する場所と，その店が用意するスタンプを決めることになった．
新しい店を出す場所は，店 i と店 i + 1 の間 (1 ≦ i ≦ N − 1)，入口と店 1 の間，店 N と出口の間のいずれかから決める．
また，新しい店のスタンプは J，O，I の 3 通りから決める．
商品券をもらえるような店の選び方の数が大きいほど，スタンプラリーが盛り上がると商店街は考えた．
そこで，新しく出す店の場所と用意するスタンプを決めたときの，上記の店の選び方の数の最大値を求めたい．

=================================================================
解説=============================================================

作りたい文字はJOI.
ここで文字列のi文字目にあるOに注目すると、i-1文字目までにあるJの数と
i+1からN文字目までにあるIの数の積となる。

また、答えは、
元々の文字列でできるJOIの数＋新たに一文字追加してできるJOIの数
となる。
よって、元々の文字列でできるJOIの数は上記方法と累積和によりO(N)でハイ
新たに一文字追加する場合
Jは文字列の一番最初に追加するのが最適（考えれば。。。ハイ）
Iは文字列の一番最後に追加するのが最適（これも考えれば。。。。ハイ）
Oは各場所にて元々の文字列でできるJOIの数を計算した方法によりハイ

よって、全てO(N)で計算できるため、総計算量はO(N)

================================================================
*/

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	ll N; cin >> N;
	string S; cin >> S;
	vector<ll> J(N, 0), I(N, 0);
	for (int i = 0; i < N;i++) {
		if (i != 0) J[i] = J[i - 1], I[i] = I[i - 1];
		if (S[i] == 'J')J[i]++;
		if (S[i] == 'I')I[i]++;
	}
	ll cnt1 = 0;
	for (int i = 0; i < N;i++) {
		if (S[i] == 'O') {
			cnt1 += J[i] * (I[N - 1] - I[i]);
		}
	}

	ll res = cnt1;
	ll cnt2 = 0;
	for (int i = 0; i < N;i++) {
		if (S[i] == 'O') {
			cnt2 += (I[N - 1] - I[i]);
		}
	}
	res = max(res, cnt1 + cnt2);
	cnt2 = 0;
	for (int i = 0; i < N;i++) {
		if (S[i] == 'O') {
			cnt2 += J[i];
		}
	}
	res = max(res, cnt1 + cnt2);
	for (int i = 0; i < N;i++) {
		cnt2 = J[i] * (I[N - 1] - I[i]);
		res = max(res, cnt1 + cnt2);
	}
	cout << res << endl;
	return 0;
}