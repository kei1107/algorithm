#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1e9
#define LINF 1e18

/*
<url:https://www.ioi-jp.org/camp/2008/2008-sp-tasks/2008-sp_tr-day1_20.pdf>
問題文============================================================
今年は JOI 国でインフルエンザの大流行の兆しがある．
JOI 国には n 個の都市 P1, . . . , Pn があり，都市 Pi の場所は座標を用いて Pi(xi, yi) と表される．
異なる都市が同じ座標を持つことはない．すなわち，
i ̸= j であれば，(xi, yi) ̸= (xj, yj ) である．
また，都市 P1 は首都の JOI 市である．
今年のインフルエンザは特別な型であり，次のような特徴がある．

1. 各都市において，インフルエンザの流行はちょうど m 日間続く．
	すなわち，もし都市 Piでインフルエンザの流行が始まったとすると，
	Pi におけるインフルエンザの流行はちょうど m 日間続き，m 日後にはインフルエンザの流行は収まる．
2. ある都市で一度インフルエンザが流行すると，その都市の市民の体内に抗体ができる．
	そのため，インフルエンザが 1 つの都市で 2 回以上流行することはない．
3. インフルエンザは日を追うごとに都市から都市へと流行を拡大する．
	その感染可能距離は d である．もし，都市 Pi でインフルエンザの流行が始まったとする．
	都市 Pj と Pi の距離が d 以下であり，まだ Pj ではインフルエンザは流行していない場合，
	その翌日には，都市 Pj でインフルエンザの流行が始まる．
	（都市 Pi(xi, yi) と Pj (xj, yj ) の間の距離は√(xi − xj )^2 + (yi − yj )^2 である．）
4. 上に述べた以外の経路でインフルエンザの流行が拡大することはない．

また，各 i = 1, . . . , n に対し，都市 Pi からの距離が d 以下であるような Pi 以外の都市の数は10 個以下である．
ある日，インフルエンザの流行が，JOI 市 P1 で始まった．
JOI 市以外の都市では，今年は，まだインフルエンザは流行していない．
JOI 国では，治療に必要なワクチンを効率よく手配するため，インフルエンザの流行状況を予測することにした．

入力として，都市の数 n，1 つの都市でインフルエンザの流行が続く日数 m，
インフルエンザの感染可能距離 d，整数 k ≥ 1，各都市の座標が与えられたとき，JOI 市で流行が始まってからk 日後において，
JOI 国内でインフルエンザが流行している都市の数を求めるプログラムを作成せよ．
n <= 100, 000
m <= 100
d <= 25
x,y <= 1000
=================================================================

解説=============================================================

制約より、貪欲にある都市から次にどの都市に感染するかどうかを確認すると O(n^2)でTLEする。
ここで、他の制約を確認する。d <= 25 , x,y <= 1000 であるので、ある座標における頂点の有無はテーブルでもっておける。
また、d <= 25より、ある座標に注目したとき、高々 (2d)^2 の範囲の周囲を確認すれば感染される都市を確認できる

よって O(n * 4d^4)となり、計算ができる。

あとは、単純にダイクストラなどをおこなって感染日を記録していけばよい

================================================================
*/
int n, m, d, k;
const int H = 1000, W = 1000;
int dict(pii& p1, pii& p2) { return (p1.first - p2.first)*(p1.first - p2.first) + (p1.second - p2.second)*(p1.second - p2.second); }
bool check(int x, int y) { return !(x < 0 || x >= H || y < 0 || y >= W); }

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	cin >> n >> m >> d >> k;
	vector<pii> ps(n);
	vector<vector<int>> masu(H, vector<int>(W, -1));
	for (int i = 0; i < n;i++) {
		int x, y; cin >> x >> y; ps[i] = { x,y };
		masu[x][y] = i;
	}

	vector<vector<int>> G(n);
	for (int i = 0; i < n;i++) {
		int x = ps[i].first, y = ps[i].second;
		for (int dx = -(d+1); dx <= d+1; dx++) {
			for (int dy = -(d+1); dy <= d+1; dy++) {
				if(dx*dx+dy*dy <= d*d){
					int nx = x + dx, ny = y + dy;
					if (!check(nx, ny)) continue;
					int v = masu[nx][ny];
					if (v == -1 || v == i) continue;
					G[i].push_back(v);
				}

			}
		}
	}

	vector<int> infection_day(n, INF);
	queue<int> q; q.push(0);
	infection_day[0] = 0;
	while (!q.empty()) {
		int N = q.front(); q.pop();
		int D = infection_day[N] + 1;
		for (auto v : G[N]) {
			if (infection_day[v] > D) {
				infection_day[v] = D;
				q.push(v);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n;i++) {
		if (infection_day[i] <= k && k < infection_day[i] + m) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
