#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60
/*
<url:>
��蕶============================================================
���N�����ʂ��Ղ̋G�߂�����Ă��܂����B
��񂲂���́A�܂���n�߂ɂ��ʂ��N�����̋V��������s�����Ǝv���Ă��܂��B
�V���ɂ͍Ւd���K�v�ŁA�Ւd�͏㕔�A�����A������3 �̃J�e�S���[�̃p�[�c1 ������Ȃ�܂��B
�Ւd��3 �J�e�S���[�̃p�[�c�����ꂼ��N ������܂��B
i �ڂ̏㕔�̃p�[�c�̃T�C�Y��Ai �Ai �ڂ̒����̃p�[�c�̃T�C�Y��Bi �A
i �ڂ̉����̃p�[�c�̃T�C�Y��Ci �ł��B
�Ւd�����ɂ������ẮA�����̃p�[�c�̃T�C�Y�͏㕔�̃p�[�c�̃T�C�Y���^�ɑ傫���A
�����̃p�[�c�̃T�C�Y�͒����̃p�[�c�̃T�C�Y��� �^�ɑ傫���Ȃ���΂Ȃ�܂���B
�t�ɁA���̏����𖞂����C�ӂ�3 �̃s�[�X��g�ݍ��킹�čՒd����邱�Ƃ��ł��܂��B
��񂲂��񂪍�邱�Ƃ̂ł���Ւd�͉���ނ���ł��傤���B
�������A2 �̍Ւd���قȂ�Ƃ́A�㕔�A�����A�����Ɏg����s�[�X�̂���
���Ȃ��Ƃ�1 ���قȂ邱�Ƃ������܂��B
=================================================================
���=============================================================
�񕔒T���{�ݐϘa

�悭�悭�l�����,�����̂���p�[�cB�͏㕔��B��菬�����p�[�c�̍��v(=>�ݐϘa+�񕔒T��O(n logn))
�ł���A�����̂���p�[�cC�͒�����C��菬�����p�[�c�̍��v(=>��ŗp�������v���l�����A���l�ɂł���)
�ƂȂ�̂ŁA�񕔒T���{�ݐϘa��O(n log n)�ł��ꂵ��
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	ll N; cin >> N;
	vector<ll> A(N), B(N), C(N);
	for (int i = 0; i < N;i++) cin >> A[i];
	for (int i = 0; i < N;i++) cin >> B[i];
	for (int i = 0; i < N;i++) cin >> C[i];
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	sort(C.begin(), C.end());

	vector<ll>BA(N+1, 0);
	for (int i = 0; i < N;i++) {
		BA[i+1] = lower_bound(A.begin(), A.end(), B[i]) - A.begin();
	}
	for (int i = 0; i < N;i++) {
		BA[i + 1] += BA[i];
	}
	ll res = 0;
	for (int i = 0; i < N;i++) {
		res += BA[lower_bound(B.begin(), B.end(), C[i]) - B.begin()];
	}
	cout << res << endl;
	return 0;
}