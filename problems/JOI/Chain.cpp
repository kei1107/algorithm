#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:https://www.ioi-jp.org/joi/2008/2009-yo-prob_and_sol/2009-yo-t3/2009-yo-t3.html>
��蕶============================================================
���̂悤�ȃQ�[��������D

����L�����N�^�[���c 1 ��� N ����ł���D 
�����̃L�����N�^�[�̐F�͐ԁC�C���̂����ꂩ�ł���C 
������Ԃœ����F�̃L�����N�^�[��4�ȏ�A�����ĕ���ł��邱�Ƃ͂Ȃ��D
�v���[���[�́C����ʒu�̃L�����N�^�[��I�ё��̐F�ɕύX���邱�Ƃ��ł���D 
���̑���ɂ�蓯���F�̃L�����N�^�[��4�ȏ�A�����ĕ��ԂƂ����̃L�����N�^�[�͏��ł���D
�L�����N�^�[�����ł��邱�Ƃɂ��V���ɓ����F�̃L�����N�^�[��4�ȏ�A�����ĕ��Ԃ�
�����̃L�����N�^�[�����ł��C�����F�̃L�����N�^�[��4�ȏ�A�����ĕ���ł���ӏ���
�Ȃ��Ȃ�܂ł��̘A���͑����D
���̃Q�[���̖ړI�́C ���ł��Ȃ��Ŏc���Ă���L�����N�^�[�����Ȃ�ׂ����Ȃ����邱�Ƃł���D
=================================================================
���=============================================================
i�Ԗڂ̃L�����N�^�[�̐F��X�Ƃ���ƁAi�Ԗڂ̃L�����N�^�[��X�ȊO�̐F�ɕω��������Ƃ��A
�ǂ��܂ŏ��ł����邱�Ƃ��ł���̂������ۂɃV���~���[�V��������΂悢
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	ll N;
    while(cin >> N,N){
	vector<ll> C(N);
	for (int i = 0; i < N;i++) cin >> C[i];
	ll res = INF;
	for (int i = 0; i < N;i++) {
		ll l = i - 1, r = i + 1;
		for (int j = 1; j <= 3;j++) {
			if (j == C[i])continue;
			ll cnt = 1;
			ll nC = j;
			ll pre_l = i, pre_r = i;
			while (true) {
				if (r < N) {
					if (C[r] == nC) {
						cnt++; r++;
						continue;
					}
				}
				if (l >= 0) {
					if (C[l] == nC) {
						cnt++; l--;
						continue;
					}
				}
				if (cnt < 4)break;
				pre_l = l; pre_r = r;
				if (l < 0 || r >= N)break;
				if (C[l] != C[r])break;
				cnt = 2;
				nC = C[l];
				l--; r++;
			}
			ll temp = max(pre_l + 1, 0LL) + max(0LL, N - pre_r);
			if (pre_l == pre_r) temp--;
			res = min(res, temp);
		}
	}
	cout << res << endl;
    }
	return 0;
}
