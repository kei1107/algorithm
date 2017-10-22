#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	ll H, W; cin >> H >> W;
	vector<vector<ll>> dp(H + 1, vector<ll>(W + 1, 0));
	for (int i = 1;i <= H;i++) {
		for (int j = 1;j <= W;j++) {
			ll c; cin >> c;
			if (c == 0) {
				dp[i][j] = 1;
			}
		}
	}
	ll res = 0;
	for (int i = 1;i <= H;i++) {
		for (int j = 1;j <= W;j++) {
			if (dp[i][j] == 0)continue;
			dp[i][j] = min({
				dp[i - 1][j - 1],
				dp[i - 1][j],
				dp[i][j - 1]
			}) + 1;
			res = max(res, dp[i][j]);
		}
	}
	cout << res*res << endl;
	return 0;
}