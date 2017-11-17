#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:https://www.ioi-jp.org/camp/2011/2011-sp-tasks/2011-sp-day1.pdf>
問題文============================================================
H x W (1<= H, W <= 400)の入力が与えられる、各マスには1,2,3の番号が割り振られている。

マスの中のうち長方形となるような4点を選んだ時、
1,2,3の各番号が少なくとも1つ含まれるような選び方は何通り存在するか？
=================================================================
解説=============================================================

2列を固定した後、各行にてどういった色の組合せが存在するかの個数を数えておく。
その後、あわせたら3種類の色となりうる個数の積がその2列でできる長方形の個数

各色をビットとして、マスク処理すると楽
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	ll H, W; cin >> H >> W;
	vector<vector<int>> masu(H, vector<int>(W));
	for (int i = 0; i < H;i++) {
		for (int j = 0; j < W;j++) {
			int c; cin >> c;
			masu[i][j] = (1 << c);
		}
	}

	ll res[8];
	memset(res, 0, sizeof(res));
	ll cnt[8];
	for (int i = 0; i < H;i++) {
		for (int j = i + 1; j < H;j++) {
			memset(cnt, 0, sizeof(cnt));
			for (int k = 0; k < W;k++) {
				cnt[masu[i][k]| masu[j][k]]++;
			}
			for (int k = 0; k < 8;k++) {
				for (int l = k + 1; l < 8;l++) {
					res[k | l] += cnt[k] * cnt[l];
				}
			}
		}
	}
	cout << res[7] << endl;
	return 0;
}