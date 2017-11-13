#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60


/*
<url:https://beta.atcoder.jp/contests/arc085/tasks/arc085_b>
��蕶============================================================

N  ���̃J�[�h����Ȃ�R�D������܂��B�J�[�h�ɂ͂��ꂼ�ꐔ��������Ă���C 
�ォ��i ���ڂɂ�ai ��������Ă��܂��B
���̎R�D���g���CX ����� Y ����2 �l�ŃQ�[�������܂��B X, Y ����͍ŏ��C
Z,W �������ꂽ�J�[�h�������Ă��܂��B ������ X ���񂩂���݂Ɉȉ����s���܂��B
�R�D���牽�����J�[�h�������B�����č������Ă���J�[�h���̂āC�Ō�Ɉ������J�[�h�����Ɏ��B
�������C�K��1 ���͈����Ȃ��Ă͂Ȃ�Ȃ��B
�R�D���Ȃ��Ȃ�ƃQ�[���͏I���ŁC2 �l�̎����Ă���J�[�h�ɏ����ꂽ���̍��̐�Βl�����̃Q�[���̃X�R�A�ɂȂ�܂��B
X ����̓X�R�A���ő剻����悤�ɁCY ����̓X�R�A���ŏ�������悤�ɃQ�[�����v���C�������C �X�R�A�͂����ɂȂ�ł��傤���H

=================================================================
���=============================================================

min-max + �����@�̎����ŊԂɍ���

p.s �z���@��O(1)

================================================================
*/

ll N, Z, W;
ll dp[2001][2001];
vector<ll> a;
ll rec(ll i,ll j, ll k,ll alpha, ll beta) {
	ll& res = dp[i][j];
	if (res != -LINF)return res;
	if (i == N || j == N) {
		ll X = (i == 0) ? Z : a[i];
		ll Y = (j == 0) ? W : a[j];
		res = abs(X - Y);
		return res;
	}
	if (k == 1) {
		res = LINF;
		for (int y = i + 1; y <= N;y++) {
			res = min(res, rec(i, y, 0, alpha, res));
			if (alpha >= res) {
				return alpha;
			}
		}
	}
	else {
		for (int x = j + 1; x <= N;x++) {
			res = max(res, rec(x, j, 1, res, beta));
			if (res >= beta) {
				return beta;
			}
		}
	}
	return res;
}

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	cin >> N >> Z >> W;
	a.resize(N + 1);
	for (int i = 1; i <= N;i++) cin >> a[i];
	for (int i = 0; i <= N;i++) {
		for (int j = 0; j <= N;j++) {
			dp[i][j] = -LINF;
		}
	}
	a.erase(unique(a.begin(), a.end()), a.end());
	N = a.size() - 1;

	cout << rec(0, 0, 0, -LINF, LINF) << endl;
	return 0;
}