#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX_N 16
#define INF (1<<30)
#define Graph vector<vector<Edge>>
using namespace std;
int V, E;
/*
Chinese Postman Problem <Undirected>
Reference:<http://www.prefield.com/algorithm/graph/undirected_chinese_postman.html>
*/

/*
 中国人郵便配達問題
 */
struct Edge {
	int from, to, cost;
	Edge(int from, int to, int cost) :from(from), to(to), cost(cost) {}
	bool operator < (const Edge &o) const {
		return cost != o.cost ? cost > o.cost :
			from != o.from ? from < o.to : to < o.to;
	}
};

int Chinese_Postman_Problem(Graph &g) {
	int ret = 0;
	vector<int> odds;
	for (int u = 0; u < V; u++) {
		for (auto e : g[u]) ret += e.cost;
		if (g[u].size() % 2) odds.emplace_back(u);
	}
	ret /= 2;
	int n = odds.size(), N = 1 << n;
	vector<vector<int>> w(n, vector<int>(n));
	for (int u = 0; u < n; u++) {
		int s = odds[u];
		vector<int> dist(V, INF);
		dist[s] = 0;
		vector<int> prev(V, -2);
		priority_queue<Edge> Q;
		Q.push(Edge(-1, s, 0));
		while (!Q.empty()) {
			Edge e = Q.top(); Q.pop();
			if (prev[e.to] != -2) continue;
			prev[e.to] = e.from;
			for (auto o : g[e.to]) {
				if (dist[o.to] > e.cost + o.cost) {
					dist[o.to] = e.cost + o.cost;
					Q.push(Edge(o.from, o.to, e.cost + o.cost));
				}
			}
		}
		for (int v = 0; v < n; v++) w[u][v] = dist[odds[v]];
	}
	vector<int> dp(N, INF);
	dp[0] = 0;

	for (int S = 0; S < N; S++) {
		for (int i = 0; i < n; i++) {
			if (!(S&(1 << i))) {
				for (int j = i + 1; j < n; j++) {
					if (!(S&(1 << j))) {
						dp[S | (1 << i) | (1 << j)] = min(dp[S | (1 << i) | (1 << j)], dp[S] + w[i][j]);
					}
				}
			}
		}
	}
	return ret + dp[N - 1];
}

int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	cin >> V >> E;
	Graph g(V);
	for (int i = 0; i < E; i++) {
		int s, t, d; cin >> s >> t >> d;
		g[s].emplace_back(Edge(s, t, d));
		g[t].emplace_back(Edge(t, s, d));
	}
	cout << Chinese_Postman_Problem(g) << endl;
}
