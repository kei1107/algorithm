#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0509>
問題文============================================================
平面に長方形のシートが何枚か置かれている.これらのシートで覆われている部分の面積や周長を求めるプログラムを作成せよ.
ただし, 平面を座標平面とみなしたとき, シートの配置は次の条件 (1), (2) を満たすものとする.
(1) 各シートの長方形の 4 頂点の x, y 座標は全て 0 以上 10000 以下の整数であり,
    長方形の各辺は x 軸, または y 軸に平行である.
(2) シートの枚数は高々 10000 枚以下である.
入力データ の 1 行目に長方形の個数 n と問題の種類を表す整数 r が空白で区切って書かれている.
2 行目以降の各行には, 各シートの左下頂点座標 (x1, y1) と右上頂点座標 (x2, y2) の座標値が
x1, y1, x2, y2 の順で空白で区切って書いてある.

出力には r = 1 のとき 1 行目に面積を, r = 2 のとき 1 行目に面積, 2 行目に周囲の長さを出力する.
いずれの場合も最後に改行を入れること.

=================================================================

解説=============================================================

制約が弱ければこういった面積問題は二次元累積和で解くことができる、
累積和計算を行い、累積和が正となる部分が囲まれている部分となり、数え上げればそれが面積となる。
外周に関しても、累積和が0と正値の境の数を数えればよい。

ただ、この問題の場合は制約から単純に累積和配列を作るとMLEとなるため、行ごとに考えて配列を使いまわす。

参考サイト<http://algoogle.hadrori.jp/aoj/0509/>

================================================================
*/

int m[2][10010];
vector<pll> ps[10010];
int maxh, maxw;
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	ll N, r;
	while (cin >> N >> r, N | r) {
		maxh = -1, maxw = -1;
		memset(m, 0, sizeof(m));
		for (int i = 0; i < 10010;i++) ps[i].clear();
		for (int i = 0;i < N;i++) {
			int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
			x1++; y1++; x2++; y2++;
			ps[y1].push_back({ x1,1 });
			ps[y1].push_back({ x2,-1 });
			ps[y2].push_back({ x1,-1 });
			ps[y2].push_back({ x2,1 });
			maxh = max(maxh, y2);
			maxw = max(maxw, x2);
		}

		int Area = 0, Length = 0;
		int cur = 0, next = 1;
		for (int i = 0; i <= maxh + 1;i++) {
			memset(m[next], 0, sizeof(m[next]));
			for (auto p : ps[i]) {
				m[next][p.first] += p.second; // 累積和の初期状態
			}
			for (int j = 0; j <= maxw;j++) {
				m[next][j + 1] += m[next][j]; // 累積和 横列へ伝播
				m[next][j] += m[cur][j]; // 累積和 縦軸へ伝播
			}
			for (int j = 0; j <= maxw;j++) {
				if (m[next][j] > 0) Area++;
				if ((m[cur][j] > 0) != (m[next][j] > 0)) Length++;
				if ((m[next][j] > 0) != (m[next][j + 1] > 0)) Length++;
			}
			cur = !cur;
			next = !next;
		}
		cout << Area << endl;
		if (r == 2) cout << Length << endl;
	}
	return 0;
}