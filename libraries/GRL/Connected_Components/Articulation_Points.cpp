#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

class ArticulationPoints {
public:
	ll V;
	vector<vector<ll>> G;
	vector<ll> prenum, parent, lowest;
	vector<int> visited;
	set<ll> AP;
	ll timer;

	ArticulationPoints(ll V) :V(V){
		prenum.assign(V, 0); parent.assign(V, -1); lowest.assign(V, -1);
		visited.assign(V, 0);
		G.resize(V);
	}

	void add_edge(ll u, ll v, bool undirected = false) {
		G[u].emplace_back(v);
		if (undirected) {
			G[v].emplace_back(u);
		}
	}

	void dfs(ll u, ll rev) {
		prenum[u] = lowest[u] = timer++;
		visited[u] = 1;
		for (auto v : G[u]) {
			if (visited[v] == 0) {
				parent[v] = u;
				dfs(v, u);
				lowest[u] = min(lowest[u], lowest[v]);
			}
			else if (v != rev) {
				lowest[u] = min(lowest[u], prenum[v]);
			}
		}
	}

	void depthFirstSearchScheme() {
		for (int i = 0; i < V;i++)visited[i] = 0;
		ll root = 0;
		timer = 1;

		// lowest‚ÌŒvŽZ
		dfs(root, -1);
	}

	void solve() {
		AP.clear();

		ll cnt = 0;
		for (int i = 0; i < V;i++) {
			if (parent[i] == 0)cnt++;
			if (cnt >= 2) {
				AP.insert(0); break;
			}
		}
		for (int i = 1; i < V;i++) {
			for (ll v : G[i]) {
				ll p = parent[v];
				if (p > 0) {
					if (prenum[p] <= lowest[v])AP.insert(p);
				}
			}
		}
	}

	set<ll> get_AP() const { return AP; }
};

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	ll V, E; cin >> V >> E;
	ArticulationPoints ap(V);
	for (int i = 0; i < E;i++) {
		ll s, t; cin >> s >> t;
		ap.add_edge(s, t, true);
	}

	ap.depthFirstSearchScheme();
	ap.solve();
	
	auto ans = ap.get_AP();
	for (auto x : ans) {
		cout << x << endl;
	}
	return 0;
}