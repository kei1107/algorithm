#define INF 1<<30
#define LINF 1LL60

struct edge {
	int to; // 行き先
	int cap; // 容量
	int rev; // 逆辺
	edge() {}
	edge(int to, int cap, int rev) :to(to), cap(cap), rev(rev) {}
};

vector<vector<edge>> G; // グラフの隣接リスト表現
vector<int> used; // DFSですでに調べたらフラグ

vector<vector<int>> one_path; // 幅1の道の場所記録

// fromからtoへ向かう容量capの辺をグラフに追加する
void add_edge(int from, int to, int cap) {
	if (cap == 1) {
		one_path[from].push_back(G[from].size());
		one_path[to].push_back(G[to].size());
	}
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

/* 幅1のパス(u,v)を u->vのルートではなく、別ルートから辿れるか確認 ex.( u->s->t->v) */
bool check(int u, int v, int rev) {
	if (u == v)return true;
	used[u] = true;
	for (int i = 0; i < G[u].size();i++) {
		if (used[G[u][i].to] == true) continue;
		if (G[u][i].cap <= 0) continue;
		if (G[u][i].to == rev)continue;
		if (check(G[u][i].to, v, u))return true;
	}
	return false;
}


/* use example / max_flow < F = 10000  */
int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	int V, E; cin >> V >> E;
	int F = 10000;
	G.resize(V); used.resize(V); one_path.resize(V);
	for (int i = 0; i < E;i++) {
		int s, t, c; cin >> s >> t >> c;
		add_edge(s, t, c);
	}

	int f = max_flow(0, V - 1);
	for (int i = 0; i < V;i++) {
		bool break_flag = false;
		for (int j = 0; j < one_path[i].size();j++) {
			if (G[i][one_path[i][j]].cap == 0) {
				fill(used.begin(), used.end(), 0);
				if (!check(i, G[i][one_path[i][j]].to, -1)) {
					f--; break_flag = true; break;
				}
			}
		}
		if (break_flag)break;
	}
	cout << ((f > F) ? -1 : f) << endl;
	return 0;
}