#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_F&lang=jp
0-1 ナップザック問題 II
価値が vi 重さが wi であるような N 個の品物と、容量が W のナップザックがあります。次の条件を満たすように、品物を選んでナップザックに入れます：

選んだ品物の価値の合計をできるだけ高くする。
選んだ品物の重さの総和は W を超えない。
価値の合計の最大値を求めてください。

制約
1 ≤ N ≤ 100
1 ≤ vi ≤ 100
1 ≤ wi ≤ 10,000,000
1 ≤ W ≤ 1,000,000,000
*/

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	ll N, W; cin >> N >> W;
	vector<ll> v(N), w(N);
	ll MAX_V = 100;
	for (int i = 0; i < N;i++) cin >> v[i] >> w[i];
	/* dp[i][j] := i番目までの品物を見たとき,価値jとなるのに必要な最小の重み */
	vector<vector<ll>> dp(N + 1, vector<ll>(N * MAX_V + 1, INF));
	dp[0][0] = 0;
	for (int i = 0; i < N;i++) {
		for (int j = 0; j <= N*MAX_V;j++) {
			if (dp[i][j] == INF) continue;
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
			if (dp[i][j] + w[i] <= W) {
				dp[i + 1][j + v[i]] = min(dp[i + 1][j + v[i]], dp[i][j] + w[i]);
			}
		}
	}
	for (int j = N*MAX_V; j >= 0; j--) {
		if (dp[N][j] == INF)continue;
		cout << j << endl;
		break;
	}
	return 0;
}