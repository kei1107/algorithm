#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/* http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_E&lang=jp
�ҏW����
�Q�̕����� s1�As2 �̕ҏW�����i���[�x���V���^�C�������j�����߂ĉ������B

�ҏW�����Ƃ́A�ȉ��R��ނ̑���ɂ���āA�P�̕������ʂ̕�����ɕό`����̂ɕK�v�Ȏ菇�̍ŏ��񐔂ł��F

�}��: ������ɂP�̕�����}������B
�폜: �����񂩂�P�̕������폜����B
�u��: ������̒��̂P������ʂȕ����ɒu��������B

*/

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	string s1, s2; cin >> s1 >> s2;
	vector<vector<ll>> dp(s1.length() + 1, vector<ll>(s2.length() + 1, INF));

	/* dp[i][j] := ������s1[0..(i-1)] ���� ������s2[0..(j-1)]�̕ҏW���� ( �Y����0�̓k�� ) */
	dp[0][0] = 0;
	for (int i = 1; i <= s1.length();i++) dp[i][0] = i;
	for (int j = 1; j <= s2.length(); j++) dp[0][j] = j;

	for (int i = 1; i <= s1.length(); i++) {
		for (int j = 1; j <= s2.length(); j++) {
			dp[i][j] = min({
				dp[i][j - 1] + 1,
				dp[i - 1][j] + 1,
				dp[i - 1][j - 1] + (s1[i - 1] != s2[j - 1])
			});
		}
	}

	/*for (int i = 0; i <= s1.length();i++) {
		for (int j = 0; j <= s2.length(); j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	cout << dp[s1.length()][s2.length()] << endl;
	return 0;
}