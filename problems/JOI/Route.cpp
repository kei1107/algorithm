#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1e9
#define LINF 1e18

/*
<url:https://www.ioi-jp.org/camp/2007/2007-sp-tasks/2007-sp-day3_23.pdf>
問題文============================================================
あなたの友人の象使いは王宮まで象をつれて行くことを命ぜられた．
道路図が与えられるが,王宮までの道路はそれぞれ有料で，さらにその費用は自前で用意しなければならない．
彼のために最も安い道程を探し出して欲しい．
ただし，以下のことに注意すること．
	• 道路は２つの料金所の間を結ぶ線分である．２つの料金所 p, q の組に対して，p と q を結ぶ道路は高々1 本しか存在しない．
	• 道路は必ず端点から端点までたどらなければならず，途中でほかの道路に乗り換えることはできない．
	• 象は鋭角には曲れないため，料金所では，それまでたどった道路とのなす角が鋭角になる道路には乗り換えられない


1 番目の料金所から 2 番目の料金所へ到達できる，最も安い料金を出力せよ．
もし到達不可能な場合は，−1 を出力せよ．
=================================================================

解説=============================================================

拡張ダイクストラ

queueに今の頂点と1つ前の頂点の二つを状態ともって、次頂点との関係が鋭角にならないように
更新していけばよい


(ICPC 400点問題のCarrot　がこれに似てるけど、もっと難しめのやつだと思う)
================================================================
*/

struct node {
	int now_city;
	int pre_city;
	ll dist_len;
	node() {}
	node(int now, int pre, ll d) :now_city(now), pre_city(pre), dist_len(d) {}
	bool operator < (const node& o) const {
		return o.dist_len < dist_len;
	}
};

struct edge {
	int u, v, cost;
	edge() {}
	edge(int u, int v, int cost) :u(u), v(v), cost(cost) {}
};
typedef pii Point;

inline bool check(int now, int pre, int next, vector<Point>& ps) {
	/*
		-90 <= theta <= 90
		cos(theta) >= 0
		内積 >= 0
	*/
	return (ps[next].first - ps[now].first) * (ps[now].first - ps[pre].first) + (ps[next].second - ps[now].second)*(ps[now].second - ps[pre].second) >= 0;
}

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);

	/* input */
	int n, m; cin >> n >> m;
	vector<Point> ps(n);
	vector<vector<edge>> G(n);
	for (int i = 0; i < n;i++) { int x, y; cin >> x >> y; ps[i] = { x,y }; }
	for (int i = 0; i < m;i++) {
		int a, b, c; cin >> a >> b >> c; a--; b--;
		G[a].push_back(edge(a, b, c)); G[b].push_back(edge(b, a, c));
	}

	priority_queue<node> pq;
	vector<vector<ll>> dist(n, vector<ll>(n, LINF));
	int s = 0, t = 1;
	for (auto e : G[s]) {
		dist[e.u][e.v] = e.cost;
		pq.push(node(e.v, e.u, dist[e.u][e.v]));
	}
	while (!pq.empty()) {
		node State = pq.top(); pq.pop();
		int n = State.now_city;
		int pre = State.pre_city;
		ll D = State.dist_len;
		if (dist[pre][n] < D) continue;
		for (auto e : G[n]) {
			int next = e.v;
			if (check(n, pre, next, ps)) {
				if (dist[n][next] > dist[pre][n] + e.cost) {
					dist[n][next] = dist[pre][n] + e.cost;
					pq.push(node(next, n, dist[n][next]));
				}
			}
		}
	}
	ll ans = LINF;
	for (int i = 0; i < n;i++) ans = min(ans, dist[i][t]);
	cout << (ans==LINF?-1:ans) << endl;
}