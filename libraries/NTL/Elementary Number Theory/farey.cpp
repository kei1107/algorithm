#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
ファレイ数列
<https://ja.wikipedia.org/wiki/%E3%83%95%E3%82%A1%E3%83%AC%E3%82%A4%E6%95%B0%E5%88%97>
*/
/* use example // 小さいほうから数えてk番目の分母　分子を出力 */
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