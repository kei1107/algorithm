#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:http://imoz.jp/data/joi/2013-sp-d1-joi_poster.pdf>
問題文============================================================
K 理事長は国際情報オリンピック日本選手団を応援するポスターを 3 枚デザインしている．
ポスターにはそれぞれ J,O,I の文字を 1 文字ずつ盛り込む予定である．
早速文字 J と文字 I のポスターを完成させた K理事長は，
残る文字 O のポスターをオーストラリアの星空を背景にデザインしようと考えた．

ポスターは幅 W，高さ H の長方形で，左下隅の座標が (0, 0)，右上隅の座標が (W, H) である．
ポスター上には N 個の星が印刷されている．
i 番目の星 Si(1 <= i <= N) のポスター上での座標は (Xi, Yi) であり，どの2 つの星も同じ座標にない．
K 理事長は文字 O のデザインを作成するにあたり，以下のように考えた．
N 個の星のうち，異なる 4 つの星を選びそれぞれ A, B,C, D とする．
A を中心とし B を通る円を円 O1，
C を中心とし D を通る円を円O2 とする．
2 つの円 O1, O2 が以下の両方の条件を満たすとき，4 つの星 A, B,C, D は K 理事長のデザイン
の候補となる．

• 円 O1 が円 O2 を内部に含む．
 すなわち，円 O2 の内部または円周上の任意の点が円 O1 の内部 (円周上は除く) にある．

• どちらの円もポスターの長方形領域からはみ出さない．すなわち，円の内部または円周上の任意の点
 (X, Y) について，0 <= X <= W かつ 0 <= Y <= H を満たす．

K 理事長のデザインの候補となるような 4 つの星 A, B,C, D の選び方は何通りあるだろうか．
=================================================================
解説=============================================================
確認する星の数が少ないのでN^4の貪欲探索で間に合う。
ただ、円が接する場合の条件判定をきちんとする
================================================================
*/

#define dist(x) ((x)*(x))
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	ll N;
	double W, H; cin >> N >> W >> H;
	vector<pair<double,double>> ps(N);
	for (auto&p : ps) cin >> p.first >> p.second;
	ll res = 0;
	for (int i = 0; i < N;i++) {
		for (int j = 0; j < N;j++) {
			for (int k = 0; k < N;k++) {
				for (int l = 0; l < N;l++) {
					if (i == j | i == k | i == l | j == k | j == l | k == l)continue;
					double r1 = dist(ps[j].first - ps[i].first) + dist(ps[j].second - ps[i].second);
					double r2 = dist(ps[l].first - ps[k].first) + dist(ps[l].second - ps[k].second);
					r1 = sqrt(r1); r2 = sqrt(r2);

					if (r1 > ps[i].first || r1 > ps[i].second)continue;
					if (r2 > ps[k].first || r2 > ps[k].second)continue;

					if (r1 > W - ps[i].first)continue;
					if (r2 > W - ps[k].first)continue;
					if (r1 > H - ps[i].second)continue;
					if (r2 > H - ps[k].second)continue;

					double dist_ik = dist(ps[i].first - ps[k].first) + dist(ps[i].second - ps[k].second);
					dist_ik = sqrt(dist_ik);
					if (r2 + dist_ik + 1e-9 < r1) {
						res++;
					}
				}
			}
		}
	}
	cout << res << endl;
	return 0;
}