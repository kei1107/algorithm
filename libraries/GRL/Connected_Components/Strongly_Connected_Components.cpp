#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

class SCC {
public:
	ll V;
	vector<vector<ll>> G;
	vector<vector<ll>> rG;
	vector<ll> group;
	vector<ll> List;
	vector<int> visited;
	SCC(ll V) :V(V) {
		G.resize(V); rG.resize(V);
		group.assign(V, -1);
	}

	void add_edge(ll u, ll v) {
		G[u].emplace_back(v);
		rG[v].emplace_back(u);
	}

	void dfs1(ll u) {
		visited[u] = 1;
		for (auto next : G[u]) {
			if (visited[next] == 1)continue;
			dfs1(next);
		}
		List.emplace_back(u);
	}

	void dfs2(ll u, ll group_num) {
		visited[u] = 1;
		group[u] = group_num;
		for (auto next : rG[u]) {
			if (visited[next] == 1)continue;
			dfs2(next, group_num);
		}
	}

	void solve() {
		visited.assign(V, 0);
		for (int i = 0; i < V;i++) {
			if (visited[i] == 1)continue;
			dfs1(i);
		}

		reverse(List.begin(), List.end());

		visited.assign(V, 0);
		ll group_num = 0;
		for (auto v : List) {
			if (visited[v] == 1)continue;
			dfs2(v, group_num);
			group_num++;
		}
	}

	bool same(ll u, ll v) {
		return group[u] == group[v];
	}
};

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	ll V, E; cin >> V >> E;
	SCC scc(V);
	for (int i = 0; i < E;i++) {
		ll s, t; cin >> s >> t;
		scc.add_edge(s, t);
	}

	scc.solve();

	ll Q; cin >> Q;
	for (int i = 0; i < Q;i++) {
		ll s, t; cin >> s >> t;
		cout << scc.same(s, t) << endl;
	}
	return 0;
}