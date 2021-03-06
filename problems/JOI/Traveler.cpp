#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:https://www.ioi-jp.org/joi/2009/2010-ho-prob_and_sol/2010-ho.pdf>
問題文============================================================
あなたは JOI 街道を旅する旅人である．
JOI 街道は東西にまっすぐに延びた道路で，JOI 街道上には n 個の宿場町がある．
宿場町には西から東の順に 1 から n までの番号が付けられている．
JOI 街道上の最も西の宿場町が宿場町 1 であり，最も東の宿場町が宿場町 n である．
あなたは，宿場町 1 から出発して m 日間の旅に出ることになった．
あなたの旅程は数列 a1, a2, . . . , am に従い，次のように決められている．
ai は i 日目の移動方法を表す 0 ではない整数である．
i 日目にあなたが出発する宿場町を宿場町 k とおくと，
i 日目にあなたは宿場町 k から宿場町 k +ai までまっすぐに移動することを意味する．
宿場町の個数 n，旅の日数 m，宿場町間の距離の情報と，移動方法を表す数列a1, a2, . . . , am が与えられたとき，
m 日間の旅におけるあなたの移動距離の合計を100000 = 10^5 で割った余りを求めるプログラムを作成せよ．
=================================================================
解説=============================================================
累積和

各距離の累積和をあらかじめ求めておき、
指定された移動方法での移動距離を実際にシュミレーションすればよい
================================================================
*/
const int Mod = (int)1e5;
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	vector<int> cusum(n + 1, 0);
	for (int i = 2; i <= n;i++) {
		cin >> cusum[i];
		cusum[i] += cusum[i - 1];
	}
	int res = 0;
	int now = 1;
	for (int i = 0; i < m;i++) {
		int a; cin >> a;
		if (a > 0) {
			res += cusum[now + a] - cusum[now];
			now = now + a;
		}
		else {
			res += cusum[now] - cusum[now + a];
			now = now + a;
		}
		res %= Mod;
	}
	cout << res << endl;
	return 0;
}