#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:https://www.ioi-jp.org/joi/2014/2015-ho/2015-ho.pdf>
��蕶============================================================

�~�`�̃P�[�L������AN(1<=N<=2000)�̃s�[�X�ɐ؂蕪�����Ă���B
�s�[�X��1����N�܂Ŕ����v���ɔԍ��������B������i�Ԗڂ̃s�[�X�̑傫����Ai����B

����N��JOI�����IOI�����Ŏ��̂悤�ɕ�����

1.
�܂� JOI ���� N �̂����̍D���� 1 ��I��Ŏ��D

2.
���̌�CIOI ����񂩂�͂��߂� IOI ������ JOI ���񂪌��݂Ɏc��̃s�[�X�� 1 ������Ă����D
�������C���ׂ̃s�[�X�̂������Ȃ��Ƃ���������Ɏ���Ă���悤�ȃs�[�X������邱�Ƃ��ł����C
����s�[�X����������Ƃ��́CIOI �����͂��̂����ł��傫�����̂�I��Ŏ��C
JOI ����͂��̂����ōD���Ȃ��̂�I��Ŏ�邱�Ƃ��ł���D
JOI ����́C�������ŏI�I�Ɏ��s�[�X�̑傫���̍��v���ő剻�������D
=================================================================
���=============================================================

l ~ r �܂ł̃s�[�X����菜����Ă��鎞�_����JOI��������s�[�X�̑傫���̍ő�
���������ċA
================================================================
*/
ll res = 0;
ll N;
vector<ll> A;
vector<vector<ll>> memo;
ll rec(int l, int r, int cur, bool first) {
	if (first) {
		return rec((l - 1 + N) % N, (r + 1) % N, 1, false) + A[l];
	}
	if (l == r) {
		if (cur == 0) {
			if (memo[l][r] != 0)return memo[l][r];
			else return memo[l][r] = A[l];
		}
		else {
			return 0;
		}
	}

	if (cur == 0) {
		ll& res = memo[l][r];
		if (res != 0)return res;
		res = max(res, rec((l - 1 + N) % N, r, 1, false) + A[l]);
		res = max(res, rec(l, (r + 1) % N, 1, false) + A[r]);
		return res;
	}
	else {
		if (A[l] > A[r]) {
			return rec((l - 1 + N) % N, r, 0, false);
		}
		else {
			return rec(l, (r + 1) % N, 0, false);
		}
	}
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	cin >> N;
	A.assign(N, 0);
	memo.assign(N, vector<ll>(N, 0));
	for (auto& in : A) cin >> in;
	ll res = 0;
	for (int i = 0; i < N;i++) {
		res = max(res, rec(i, i, 0, true));
	}
	cout << res << endl;
	return 0;
}