#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_B&lang=jp
/*
���
0-1 �i�b�v�U�b�N���
���l�� vi �d���� wi �ł���悤�� N �̕i���ƁA�e�ʂ� W �̃i�b�v�U�b�N������܂��B
���̏����𖞂����悤�ɁA�i����I��Ńi�b�v�U�b�N�ɓ���܂��F

�I�񂾕i���̉��l�̍��v���ł��邾����������B
�I�񂾕i���̏d���̑��a�� W �𒴂��Ȃ��B
���l�̍��v�̍ő�l�����߂Ă��������B

*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	ll N, W; cin >> N >> W;
	vector<ll> v(N), w(N);
	for (int i = 0; i < N;i++) cin >> v[i] >> w[i];

	/*
	vector<vector<ll>> dp(N + 1, vector<ll>(W + 1, 0));
	for (int i = 0; i < N;i++) {
		for (int j = 0; j <= W;j++) {
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
			if (j + w[i] <= W) {
				dp[i + 1][j + w[i]] = max(dp[i + 1][j + w[i]], dp[i][j] + v[i]);
			}
		}
	}
	cout << dp[N][W] << endl;
	*/

	vector<ll> dp(W + 1, 0);
	for (int i = 0; i < N;i++) {
		for (int j = W; j >= 0;j--) {
			if (j + w[i] <= W) {
				dp[j + w[i]] = max(dp[j + w[i]], dp[j] + v[i]);
			}
		}
	}
	cout << dp[W] << endl;
	return 0;
}