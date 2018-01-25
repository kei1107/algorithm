#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/* http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_H&lang=jp
巨大ナップザック問題
価値が vi 重さが wi であるような N 個の品物と、容量が W のナップザックがあります。次の条件を満たすように、品物を選んでナップザックに入れます：

選んだ品物の価値の合計をできるだけ高くする。
選んだ品物の重さの総和は W を超えない。
価値の合計の最大値を求めてください。

制約
1 ≤ N ≤ 40
1 ≤ vi ≤ 10^15
1 ≤ wi ≤ 10^15
1 ≤ W ≤ 10^15

*/

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	ll N, W; cin >> N >> W;
	vector<ll> v(N), w(N);
	for (int i = 0; i < N;i++) cin >> v[i] >> w[i];
	
	/* 半分全列挙 */
	// 前半分の全列挙
	ll n1 = N / 2;
	vector<pll> ps(1 << n1);
	for (int i = 0; i < (1 << n1);i++) {
		ll sum_v = 0, sum_w = 0;
		for (int j = 0; j < n1;j++) {
			if (i >> j & 1) {
				sum_v += v[j];
				sum_w += w[j];
			}
		}
		ps[i] = { sum_w,sum_v };
	}
	// 無駄な要素の除去
	sort(ps.begin(), ps.end());
	ll m = 1;
	for (int i = 1; i < (1 << n1);i++) {
		if (ps[m - 1].second < ps[i].second) {
			ps[m++] = ps[i];
		}
	}

	// 後ろ半分の全列挙
	ll res = 0;
	ll n2 = N - n1;
	for (int i = 0; i < (1 << n2);i++) {
		ll sum_v = 0, sum_w = 0;
		for (int j = 0; j < n2;j++) {
			if (i >> j & 1) {
				sum_v += v[n1 + j];
				sum_w += w[n1 + j];
			}
		}
		if (sum_w <= W) {
			auto idx = lower_bound(ps.begin(), ps.begin() + m, pll(W - sum_w,INF)) - ps.begin();
			ll V = ps[idx - 1].second;
			res = max(res, sum_v + V);
		}
	}
	cout << res << endl;
	return 0;
}