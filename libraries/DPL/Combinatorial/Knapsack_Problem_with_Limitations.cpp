#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_G&lang=jp
個数制限付きナップザック問題
価値が vi 重さが wi であるような N 種類の品物と、容量が W のナップザックがあります。

次の条件を満たすように、品物を選んでナップザックに入れます：

選んだ品物の価値の合計をできるだけ高くする。
選んだ品物の重さの総和は W を超えない。
i 番目の品物は mi 個まで選ぶことができる。
価値の合計の最大値を求めてください。

制約
1 ≤ N ≤ 100
1 ≤ vi ≤ 1,000
1 ≤ wi ≤ 1,000
1 ≤ mi ≤ 10,000
1 ≤ W ≤ 10,000
*/

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	ll N, W; cin >> N >> W;
	vector<ll> v(N), w(N), m(N);
	for (int i = 0; i < N;i++) cin >> v[i] >> w[i] >> m[i];

	vector<ll> dp(W + 1, 0);
	for (int i = 0; i < N;i++) {
		ll num = m[i];
		for (int k = 1; num > 0; k <<= 1) {
			ll mul = min((ll)k, num);
			for (int j = W; j >= w[i] * mul;j--) {
				dp[j] = max(dp[j], dp[j - w[i] * mul] + v[i] * mul);
			}
			num -= mul;
		}
	}
	cout << dp[W] << endl;
	return 0;
}