#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:https://www.ioi-jp.org/joi/2015/2016-ho/2016-ho.pdf>
問題文============================================================
N(1<=N<=20000)個のオレンジがあり、オレンジiの大きさはAiである。

このオレンジを前から順番にいくつかの箱に分けてつめることにした。ひとつの箱には
連続した番号のオレンジしかつめることができない。

ひとつの箱には最大でM(1<=M<=1000)までオレンジをつめることができ、
箱にオレンジをつめるためにかかるコストは、箱につめる最大のオレンジの大きさをa,
箱につめる最小のオレンジの大きさをb, 箱につめるオレンジの個数をsとしたとき, K+s*(a-b)となる。
Kは箱にかかるコストであり。全ての箱で共通

適切な個数の箱を用意して、すべてのオレンジを適切に箱詰めすることで箱詰めにかかる
コストの総和をできるだけ小さくする。
=================================================================
解説=============================================================

dp[i][j] := i番目のオレンジを見たとき、箱に既にj個オレンジが入っているときの状態（コスト、最大のオレンジ、最小のオレンジ)

N*Mの配列だとMLEするので、2*Mで行列を使いまわす
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	ll N, M, K; cin >> N >> M >> K;
	vector<int> A(N); for (auto& in : A)cin >> in;

	vector<vector<pair<ll, pair<int, int>>>> dp(2, vector<pair<ll, pair<int, int>>>(M, { LINF,{ -INF,INF } }));
	int cur = 0, next = 1;
	dp[0][0].first = 0;
	for (int i = 0; i < N;i++) {
		for (int j = 0; j < M;j++) {
			dp[next][j] = { LINF,{-INF,INF} };
		}
		for (int j = 0; j < M;j++) {
			if (dp[cur][j].first == LINF)continue;
			if (j != M-1 && i != N-1) {
				dp[next][j+1] = min(dp[next][j + 1], { dp[cur][j].first,{ max(dp[cur][j].second.first,A[i]),min(dp[cur][j].second.second,A[i]) } });
			}
			dp[next][0] = min(dp[next][0], { dp[cur][j].first + (ll)K + (ll)(j + 1)*((ll)max(dp[cur][j].second.first,A[i]) - (ll)min(dp[cur][j].second.second,A[i])),{ -INF,INF } });
		}
		cur = !cur;
		next = !next;
	}
	cout << dp[cur][0].first << endl;
	return 0;
}