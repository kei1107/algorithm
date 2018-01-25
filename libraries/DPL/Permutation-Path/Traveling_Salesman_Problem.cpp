#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

struct edge {
	ll u;
	ll v;
	ll cost;
	edge() {}
	edge(ll u, ll v, ll c) :u(u), v(v), cost(c) {}
};

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	ll V, E; cin >> V >> E;
	vector<vector<edge>> G(V);
	for (int i = 0; i < E;i++) {
		ll s, t, d; cin >> s >> t >> d;
		G[s].emplace_back(edge(s, t, d));
	}
	/* dp[i][j] := �����_j�ɂ���Ƃ�, bit��i�̒��_�����B�ςł��鎞�̍ŒZ���� */
	vector<vector<ll>> dp(1 << V, vector<ll>(V, INF));
	dp[0][0] = 0; // ���_0����n�܂�
	for (int i = 0; i < (1 << V);i++) {
		for (int j = 0; j < V;j++) {
			for (auto e : G[j]) {
				if (!((i >> e.v) & 1)) {
					dp[i | (1 << e.v)][e.v] = min(dp[i | (1 << e.v)][e.v], dp[i][e.u] + e.cost);
				}
			}
		}
	}
	ll ret = dp[(1 << V) - 1][0]; // �S�Ă̒��_��H��, 0�ɖ߂��Ă���
	if (ret == INF)ret = -1;
	cout << ret << endl;
	return 0;
}