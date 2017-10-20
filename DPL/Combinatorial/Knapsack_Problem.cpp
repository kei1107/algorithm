#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_C&lang=jp
/*
問題
ナップザック問題
価値が vi 重さが wi であるような N 種類の品物と、容量が W のナップザックがあります。

次の条件を満たすように、品物を選んでナップザックに入れます：

選んだ品物の価値の合計をできるだけ高くする。
選んだ品物の重さの総和は W を超えない。
同じ種類の品物はいくつでも選ぶことができる。
価値の合計の最大値を求めてください。

*/

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	ll N, W; cin >> N >> W;
	vector<ll> v(N), w(N);
	for (int i = 0; i < N;i++)cin >> v[i] >> w[i];
	vector<ll> dp(W + 1, 0);
	for (int i = 0; i <= W;i++) {
		for (int j = 0; j < N;j++) {
			if (i + w[j] > W)continue;
			dp[i + w[j]] = max(dp[i + w[j]], dp[i] + v[j]);
		}
	}
	cout << dp[W] << endl;
	return 0;
}