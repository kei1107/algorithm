#define INF 1<<30
#define LINF 1LL60

struct edge {
	int to; // �s����
	int cap; // �e��
	int rev; // �t��
	edge() {}
	edge(int to, int cap, int rev) :to(to), cap(cap), rev(rev) {}
};

vector<vector<edge>> G; // �O���t�̗אڃ��X�g�\��
vector<int> used; // DFS�ł��łɒ��ׂ���t���O

vector<vector<int>> one_path; // ��1�̓��̏ꏊ�L�^

// from����to�֌������e��cap�̕ӂ��O���t�ɒǉ�����
void add_edge(int from, int to, int cap) {
	if (cap == 1) {
		one_path[from].push_back(G[from].size());
		one_path[to].push_back(G[to].size());
	}
	G[from].push_back(edge(to, cap, G[to].size()));
	G[to].push_back(edge(from, cap, G[from].size() - 1));
}

// �����p�X��DFS�ŒT��
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

// s����t�ւ̍ő嗬�����߂�
int max_flow(int s, int t) {
	int flow = 0;
	for (;;) {
		fill(used.begin(), used.end(), 0);
		int f = dfs(s, t, INF);
		if (f == 0) return flow;
		flow += f;
	}
}

/* ��1�̃p�X(u,v)�� u->v�̃��[�g�ł͂Ȃ��A�ʃ��[�g����H��邩�m�F ex.( u->s->t->v) */
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