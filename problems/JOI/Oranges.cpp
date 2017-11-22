#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:https://www.ioi-jp.org/joi/2015/2016-ho/2016-ho.pdf>
��蕶============================================================
N(1<=N<=20000)�̃I�����W������A�I�����Wi�̑傫����Ai�ł���B

���̃I�����W��O���珇�Ԃɂ������̔��ɕ����Ă߂邱�Ƃɂ����B�ЂƂ̔��ɂ�
�A�������ԍ��̃I�����W�����߂邱�Ƃ��ł��Ȃ��B

�ЂƂ̔��ɂ͍ő��M(1<=M<=1000)�܂ŃI�����W���߂邱�Ƃ��ł��A
���ɃI�����W���߂邽�߂ɂ�����R�X�g�́A���ɂ߂�ő�̃I�����W�̑傫����a,
���ɂ߂�ŏ��̃I�����W�̑傫����b, ���ɂ߂�I�����W�̌���s�Ƃ����Ƃ�, K+s*(a-b)�ƂȂ�B
K�͔��ɂ�����R�X�g�ł���B�S�Ă̔��ŋ���

�K�؂Ȍ��̔���p�ӂ��āA���ׂẴI�����W��K�؂ɔ��l�߂��邱�ƂŔ��l�߂ɂ�����
�R�X�g�̑��a���ł��邾������������B
=================================================================
���=============================================================

dp[i][j] := i�Ԗڂ̃I�����W�������Ƃ��A���Ɋ���j�I�����W�������Ă���Ƃ��̏�ԁi�R�X�g�A�ő�̃I�����W�A�ŏ��̃I�����W)

N*M�̔z�񂾂�MLE����̂ŁA2*M�ōs����g���܂킷
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