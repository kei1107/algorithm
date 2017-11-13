#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:https://beta.atcoder.jp/contests/arc085/tasks/arc085_c>
問題文============================================================
宝石がN 個あり，それぞれ1,2,...,N と数が書かれています。
あなたは，以下の操作を好きなだけ行うことが出来ます(一度も行わなくてもよいです)。
正整数x を選ぶ。x の倍数が書かれた宝石を全て叩き割る。
そして，i が書かれていた宝石が割られずに残っていた場合，
ai 円貰います。 ただし，このai は負の場合もあり，その場合はお金を払わなくてはいけません。

うまく操作を行った時，あなたは最大で何円お金を貰えるでしょうか？
=================================================================
解説=============================================================

最小カット問題に帰結できる、、、、、らしい

a_i <= 0 ならば s -> i に cost -a_i　の辺
a_i > 0 ならば i -> t に　cost a_i の辺
各j=2i,3i,4i,...について i->jに容量infの辺

を張って流せばよい


================================================================
*/

struct edge {
	int to; // 行き先
	ll cap; // 容量
	int rev; // 逆辺
	edge() {}
	edge(int to, ll cap, int rev) :to(to), cap(cap), rev(rev) {}
};

vector<vector<edge>> G; // グラフの隣接リスト表現
vector<int> used; // DFSですでに調べたらフラグ

				  // fromからtoへ向かう容量capの辺をグラフに追加する
void add_edge(int from, int to, ll cap) {
	G[from].push_back(edge(to, cap, G[to].size()));
	G[to].push_back(edge(from, 0, G[from].size() - 1));
}

// 増加パスをDFSで探す
ll dfs(int v, int t, ll f) {
	if (v == t) return f;
	used[v] = true;
	for (int i = 0; i < G[v].size(); i++) {
		edge &e = G[v][i];
		if (!used[e.to] && e.cap > 0) {
			ll d = dfs(e.to, t, min(f, e.cap));
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
ll max_flow(int s, int t) {
	ll flow = 0;
	for (;;) {
		fill(used.begin(), used.end(), 0);
		ll f = dfs(s, t, INF);
		if (f == 0) return flow;
		flow += f;
	}
}

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	ll N; cin >> N;
	G.resize(N + 2); used.resize(N + 2);

	ll Sum = 0;
	for (int i = 1; i <= N;i++) {
		ll a; cin >> a;
		for (int j = 2 * i; j <= N; j += i) add_edge(i, j, LINF);
		if (a > 0) {
			Sum += a;
			add_edge(i, N + 1, a);
		}
		else {
			add_edge(0, i, -a);
		}
	}
	cout << Sum - max_flow(0, N + 1) << endl;
	return 0;
}