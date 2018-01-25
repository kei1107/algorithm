#include "bits/stdc++.h"
using namespace std;

class Bridge {
public:
	vector<vector<int>> G;
	vector<int> ord, low;
	vector<pair<int, int>> bridges;
	int k;

	Bridge(int N):k(0) {
		G.resize(N); ord.resize(N, -1); low.resize(N, -1);
	}
	void clear() { G.clear();ord.clear();low.clear(); }
	void add_edge(int s, int t) {
		G[s].emplace_back(t); 
		G[t].emplace_back(s);
	}

	bool is_bridge(int u, int v)const {
		if (ord[u] > ord[v])swap(u, v);
		return ord[u] < low[v];
	}

	/* Lowlink */
	void dfs(int u,int rev = -1) {
		ord[u] = low[u] = k;
		k++;
		for (auto v : G[u]) {
			if (v == rev)continue;
			if (ord[v] < 0) {
				dfs(v, u);
				low[u] = min(low[u], low[v]);
			}
			else {
				low[u] = min(low[u], ord[v]);
			}
			if (is_bridge(u, v)) {
				int s = u, t = v;
				if (s > t) swap(s, t);
				bridges.push_back({ s,t });
			}
		}
	}

	void solve() {
		dfs(0);
		sort(bridges.begin(), bridges.end());
	}
};