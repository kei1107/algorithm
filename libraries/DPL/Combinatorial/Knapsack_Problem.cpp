#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_C&lang=jp
/*
���
�i�b�v�U�b�N���
���l�� vi �d���� wi �ł���悤�� N ��ނ̕i���ƁA�e�ʂ� W �̃i�b�v�U�b�N������܂��B

���̏����𖞂����悤�ɁA�i����I��Ńi�b�v�U�b�N�ɓ���܂��F

�I�񂾕i���̉��l�̍��v���ł��邾����������B
�I�񂾕i���̏d���̑��a�� W �𒴂��Ȃ��B
������ނ̕i���͂����ł��I�Ԃ��Ƃ��ł���B
���l�̍��v�̍ő�l�����߂Ă��������B

*/

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	ll N, W; cin >> N >> W;
	vector<ll> v(N), w(N);
	for (int i = 0; i < N;i++)cin >> v[i] >> w[i];
	vector<ll> dp(W + 1, 0);
	for (int i = 0; i <= W;i++) {
		for (int j = 0; j < N;j++) {
			if (i + w[j] > W)continue;
			dp[i + w[j]] = max(dp[i + w[j]], dp[i] + v[j]);
		}
	}
	cout << dp[W] << endl;
	return 0;
}