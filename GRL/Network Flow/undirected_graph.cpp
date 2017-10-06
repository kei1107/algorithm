#define INF 1<<30

struct edge {
	int to; // 行き先
	int cap; // 容量
	int rev; // 逆辺
	edge() {}
	edge(int to, int cap, int rev) :to(to), cap(cap), rev(rev) {}
};

vector<vector<edge>> G; // グラフの隣接リスト表現
vector<int> used; // DFSですでに調べたらフラグ

// fromからtoへ向かう容量capの辺をグラフに追加する
void add_edge(int from, int to, int cap) {
	G[from].push_back(edge(to, cap, G[to].size()));
	G[to].push_back(edge(from, cap, G[from].size() - 1));
}

// 増加パスをDFSで探す
int dfs(int v, int t, int f) {
	if (v == t) return f;
	used[v] = true;
	for (int i = 0; i < G[v].size(); i++) {
		edge &e = G[v][i];
		if (!used[e.to] && e.cap > 0) {
			int d = dfs(e.to, t, min(f, e.cap));
			if (d > 0) {
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}

// sからtへの最大流を求める
int max_flow(int s, int t) {
	int flow = 0;
	for (;;) {
		fill(used.begin(), used.end(), 0);
		int f = dfs(s, t, INF);
		if (f == 0) return flow;
		flow += f;
	}
}

/* use example */
int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	int V, E; cin >> V >> E;
	G.resize(V); used.resize(V);
	for (int i = 0; i < E;i++) {
		int s, t, c; cin >> s >> t >> c;
		add_edge(s, t, c);
	}
	cout << max_flow(0, V - 1) << endl;
	return 0;
}