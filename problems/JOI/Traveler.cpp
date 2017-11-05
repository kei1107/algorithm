#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:https://www.ioi-jp.org/joi/2009/2010-ho-prob_and_sol/2010-ho.pdf>
��蕶============================================================
���Ȃ��� JOI �X���𗷂��闷�l�ł���D
JOI �X���͓����ɂ܂������ɉ��т����H�ŁCJOI �X����ɂ� n �̏h�꒬������D
�h�꒬�ɂ͐����瓌�̏��� 1 ���� n �܂ł̔ԍ����t�����Ă���D
JOI �X����̍ł����̏h�꒬���h�꒬ 1 �ł���C�ł����̏h�꒬���h�꒬ n �ł���D
���Ȃ��́C�h�꒬ 1 ����o������ m ���Ԃ̗��ɏo�邱�ƂɂȂ����D
���Ȃ��̗����͐��� a1, a2, . . . , am �ɏ]���C���̂悤�Ɍ��߂��Ă���D
ai �� i ���ڂ̈ړ����@��\�� 0 �ł͂Ȃ������ł���D
i ���ڂɂ��Ȃ����o������h�꒬���h�꒬ k �Ƃ����ƁC
i ���ڂɂ��Ȃ��͏h�꒬ k ����h�꒬ k +ai �܂ł܂������Ɉړ����邱�Ƃ��Ӗ�����D
�h�꒬�̌� n�C���̓��� m�C�h�꒬�Ԃ̋����̏��ƁC�ړ����@��\������a1, a2, . . . , am ���^����ꂽ�Ƃ��C
m ���Ԃ̗��ɂ����邠�Ȃ��̈ړ������̍��v��100000 = 10^5 �Ŋ������]������߂�v���O�������쐬����D
=================================================================
���=============================================================
�ݐϘa

�e�����̗ݐϘa�����炩���ߋ��߂Ă����A
�w�肳�ꂽ�ړ����@�ł̈ړ����������ۂɃV���~���[�V��������΂悢
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