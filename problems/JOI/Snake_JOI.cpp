#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:https://joi2017yo.contest.atcoder.jp/tasks/joi2017yo_f>
問題文============================================================
ヘビの JOI 君は，ある大きな屋敷に迷い込んでしまった．屋敷の住人に見つかる前に，屋敷を脱出しなければならない．

この屋敷には部屋が N 個あり，1,2,…,N の番号が付けられている．
また，廊下が M 本あり，i 本目の廊下 (1≦i≦M) は部屋 Ai と部屋 Bi を結んでいる．
JOI 君はこれらの廊下をどちらの向きにも通ることができ，廊下 i を通るのには Di 分かかる．
部屋と部屋の間を廊下を通る以外の手段で移動する方法はない．

この屋敷の部屋の温度はそれぞれ一定に調節されており，JOI 君にとって寒すぎるか，快適であるか，暑すぎるかである．
JOI 君は，急な温度変化に対応できないため，最後に寒すぎる部屋を出てから X 分未満のうちに暑すぎる部屋に入ることはできない．
同様に，最後に暑すぎる部屋を出てから X 分未満のうちに寒すぎる部屋に入ることもできない．

JOI 君は，移動中に部屋に入るとすぐに部屋から出なければならない．また，廊下の途中で引き返したり，
廊下 i を Di 分より長い時間かけて通ることもできない．ただし，一度訪れた部屋にもう一度入ることや，一度使った廊下をもう一度使うことは許される．

JOI 君は現在部屋 1 にいる．この部屋は JOI 君にとって寒すぎる．
JOI 君は屋敷の出口のある部屋 N に入ると，屋敷から脱出できる．

JOI 君が屋敷から脱出するのにかかる最短の時間を求めよ．

N,M,X(2≦N≦10000,1≦M≦20000,1≦X≦200)

部屋 i の温度を表す整数 Ti(0≦Ti≦2) が書かれている．
JOI 君にとって部屋 i は，Ti=0 のとき寒すぎ，Ti=1 のとき快適であり，Ti=2 のとき暑すぎる．
T1=0 であることが保証されている

3 個の整数 Aj,Bj,Dj(1≦Aj<Bj≦N,1≦Dj≦200) が空白を区切りとして書かれている．
これは，廊下 j が部屋 Aj と部屋 Bj を結んでおり，通るのに Dj 分かかることを表す
=================================================================

解説=============================================================

拡張ダイクストラ
現在の位置・現在の状態・経過時間の3要素をもってダイクストラをすればok

priority-queueを使えばかなり早くなる

================================================================
*/

// 解法1
struct edge {
	ll u;
	ll v;
	ll c;
	edge() {}
	edge(ll u, ll v, ll c) :u(u), v(v), c(c) {}
};
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	ll N, M, X; cin >> N >> M >> X;
	vector<ll> T(N);
	for (auto& in : T) cin >> in;
	vector<vector<edge>> G(N);
	for (int i = 0; i < M;i++) {
		ll A, B, D; cin >> A >> B >> D;
		A--; B--;
		G[A].push_back(edge(A, B, D));
		G[B].push_back(edge(B, A, D));
	}

	vector<vector<vector<ll>>> dist(N, vector<vector<ll>>(3, vector<ll>(X + 1, INF)));
	dist[0][0][0] = 0;
	using Key = tuple<ll, ll, ll>;
	queue<Key> q;
	q.push(Key(0, 0, 0));
	while (!q.empty()) {
		ll n, f, x;
		tie(n, f, x) = q.front(); q.pop();
		for (auto e : G[n]) {
			if (x + e.c < X) {
				if (f == 0 && T[e.v] == 2) continue;
				if (f == 2 && T[e.v] == 0) continue;

				if (T[e.v] == 1) {
					if (dist[e.v][f][x + e.c] > dist[e.u][f][x] + e.c) {
						dist[e.v][f][x + e.c] = dist[e.u][f][x] + e.c;
						q.push(Key(e.v, f, x + e.c));
					}
				}
				if (T[e.v] == f) {
					if (dist[e.v][f][0] > dist[e.u][f][x] + e.c) {
						dist[e.v][f][0] = dist[e.u][f][x] + e.c;
						q.push(Key(e.v, f, 0));
					}
				}

			}
			else {
				if (T[e.v] == 1) {
					if (dist[e.v][T[e.v]][X] > dist[e.u][f][x] + e.c) {
						dist[e.v][T[e.v]][X] = dist[e.u][f][x] + e.c;
						q.push(Key(e.v, T[e.v], X));
					}
				}
				else {
					if (dist[e.v][T[e.v]][0] > dist[e.u][f][x] + e.c) {
						dist[e.v][T[e.v]][0] = dist[e.u][f][x] + e.c;
						q.push(Key(e.v, T[e.v], 0));
					}
				}
			}
		}
	}

	ll ans = LINF;
	for (int i = 0; i <= X;i++) {
		ans = min({ ans,dist[N - 1][0][i],dist[N - 1][1][i],dist[N - 1][2][i] });
	}
	cout << ans << endl;
	return 0;
}



////////////////////////////////////////////////////////////////////////////////////////////
// 解法2
ll dist[10010][3][205];
bool used[10010][3][205];

struct edge {
	ll u;
	ll v;
	ll c;
	edge() {}
	edge(ll u, ll v, ll c) :u(u), v(v), c(c) {}
};

struct status {
	int t, n, f, x;
	status(int t, int n, int f, int x) :t(t), n(n), f(f), x(x) {}
	bool operator < (const status& o) const {
		return t < o.t;
	}
	bool operator > (const status& o) const {
		return t > o.t;
	}
};
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	ll N, M, X; cin >> N >> M >> X;
	vector<ll> T(N);
	for (auto& in : T) cin >> in;
	vector<vector<edge>> G(N);
	for (int i = 0; i < M;i++) {
		ll A, B, D; cin >> A >> B >> D;
		A--; B--;
		G[A].push_back(edge(A, B, D));
		G[B].push_back(edge(B, A, D));
	}

	priority_queue<status, vector<status>, greater<status>> pq;
	for (int i = 0; i < N;i++) {
		for (int j = 0; j < 3;j++) {
			for (int k = 0; k <= X;k++) {
				dist[i][j][k] = INF;
			}
		}
	}

	pq.push(status(0, 0, 0, 0));
	while (!pq.empty()) {
		status now = pq.top(); pq.pop();

		if (!used[now.n][now.f][now.x]) {
			used[now.n][now.f][now.x] = true;
			dist[now.n][now.f][now.x] = now.t;

			for (auto e : G[now.n]) {
				if (now.x + e.c >= X) {
					pq.push(status(now.t + e.c, e.v, T[e.v], T[e.v] == 1 ? X : 0));
				}
				else {
					if (T[e.v] == 1 || T[e.v] == now.f) {
						pq.push(status(now.t + e.c, e.v, now.f, T[e.v] == 1 ? now.x + e.c : 0));
					}
				}
			}
		}
	}

	ll ans = LINF;
	for (int i = 0; i <= X;i++) {
		ans = min({ ans,dist[N - 1][0][i],dist[N - 1][1][i],dist[N - 1][2][i] });
	}
	cout << ans << endl;
	return 0;
}
