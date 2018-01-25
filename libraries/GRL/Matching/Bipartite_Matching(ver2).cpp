#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

ll V;
vector<vector<ll>> G;
vector<ll> match;
vector<int> used;

void add_edge(ll u, ll v) {
	G[u].push_back(v);
	G[v].push_back(u);
}

bool dfs(ll v) {
	used[v] = 1;
	for (int i = 0; i < G[v].size(); i++) {
		ll u = G[v][i], w = match[u];
		if (w < 0 || ((used[w] == 0) && dfs(w))) {
			match[v] = u;
			match[u] = v;
			return true;
		}
	}
	return false;
}

ll bipartite_matching() {
	ll res = 0;
	for (int i = 0; i < (int)match.size();i++)match[i] = -1;
	for (int v = 0;v < V;v++) {
		if (match[v] < 0) {
			for (int i = 0; i < (int)used.size();i++)used[i] = 0;
			if (dfs(v))res++;
		}
	}
	return res;
}

/* use example */
int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	ll X, Y, E; cin >> X >> Y >> E;
	V = X + Y; // initialize V [0..index]
	G.resize(V); used.resize(V); match.resize(V); // initialize G used match
	for (int i = 0; i < E;i++) {
		ll x, y; cin >> x >> y;
		add_edge(x, y + X);
	}
	cout << bipartite_matching() << endl;
	return 0;
}
