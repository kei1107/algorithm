#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60
/* http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_A&lang=jp */
/*
問題
額面がc1, c2,..., cm　円の　m　種類のコインを使って、
n 円を支払うときの、コインの最小の枚数を求めて下さい。
各額面のコインは何度でも使用することができます。

出力
コインの最小枚数を１行に出力してください。
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	ll n, m; cin >> n >> m;
	vector<ll> c(m);
	vector<ll> dp(50010, INF);
	for (int i = 0; i < m;i++) {
		cin >> c[i];
		dp[c[i]] = 1;
	}
	for (int i = 0; i < n;i++) {
		if (dp[i] == INF)continue;
		for (int j = 0; j < m;j++) {
			if (i + c[j] > n)continue;
			dp[i + c[j]] = min(dp[i + c[j]], dp[i] + 1);
		}
	}
	cout << dp[n] << endl;
	return 0;
}