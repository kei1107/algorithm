#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:https://www.ioi-jp.org/camp/2008/2008-sp-tasks/2008-sp_tr-day3_22.pdf>
問題文============================================================

JOI の M 理事長は IOI2008 で日本の選手が活躍できるように毎日ピラミッドの写真にお祈りをしていた．
ある晩彼の夢にスフィンクスが現われてこういった．

 我に金塊を捧げよ，さすれば願いをかなえよう，ただし，金塊の重さは 1kg より軽く，
 分母が M 以下の分数のうち小さいものから数えて k 番目の分数になるようにせよ.
 これより軽くても重くても願いはかなえられないであろう．
とても多忙な M 理事長は代表候補であるあなた達にこの問題を解くように指示をした．
=================================================================
解説=============================================================
ファレイ数列。。。というらしい。　知識ゲー
→<https://ja.wikipedia.org/wiki/%E3%83%95%E3%82%A1%E3%83%AC%E3%82%A4%E6%95%B0%E5%88%97>
================================================================
*/

ll res_n = 0, res_m = 0;
ll m, k;
ll cnt = 0;
void farey(ll ln, ll lm, ll rn, ll rm) {
	ll tn = ln + rn, tm = lm + rm;
	if (tm > m)return;
	if (cnt > k)return;
	farey(ln, lm, tn, tm);
	cnt++;
	if (cnt == k) {
		res_n = tn; res_m = tm;
		return;
	}
	farey(tn, tm, rn, rm);
}

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	cin >> m >> k;
	farey(0, 1, 1, 1);
	if (res_n == 0) cout << -1 << endl;
	else cout << res_n << " " << res_m << endl;
	return 0;
}