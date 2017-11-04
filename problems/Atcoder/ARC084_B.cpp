#include "bits/stdc++.h"
#include <random>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:https://beta.atcoder.jp/contests/arc084/tasks/arc084_b>
問題文============================================================
K  の正の倍数の10 進法での各桁の和としてありうる最小の値を求めてください。
=================================================================
解説=============================================================
 => 解説<https://img.atcoder.jp/arc084/editorial.pdf>

 Dijkstra

 むつかしいね
================================================================
*/

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	ll K; cin >> K;
	vector<vector<pll>> G(K);
	for (int i = 1;i < K;i++) {
		G[i].push_back({ (i+1)%K,1 });
		G[i].push_back({ (i * 10) % K,0 });
	}
	for (int i = 0; i < K;i++) {
		sort(G[i].begin(), G[i].end());
		G[i].erase(unique(G[i].begin(), G[i].end()), G[i].end());
	}
	vector<ll> dist(K, INF);
	queue<ll> q; q.push(1);
	dist[1] = 0;
	while (!q.empty()) {
		ll n = q.front(); q.pop();
		for (auto e : G[n]) {
			if (dist[e.first] > dist[n] + e.second) {
				dist[e.first] = dist[n] + e.second;
				q.push(e.first);
			}
		}
	}
	cout << dist[0] + 1 << endl;
	return 0;
}