#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:https://www.ioi-jp.org/camp/2011/2011-sp-tasks/2011-sp-day1.pdf>
��蕶============================================================
H x W (1<= H, W <= 400)�̓��͂��^������A�e�}�X�ɂ�1,2,3�̔ԍ�������U���Ă���B

�}�X�̒��̂��������`�ƂȂ�悤��4�_��I�񂾎��A
1,2,3�̊e�ԍ������Ȃ��Ƃ�1�܂܂��悤�ȑI�ѕ��͉��ʂ葶�݂��邩�H
=================================================================
���=============================================================

2����Œ肵����A�e�s�ɂĂǂ��������F�̑g���������݂��邩�̌��𐔂��Ă����B
���̌�A���킹����3��ނ̐F�ƂȂ肤����̐ς�����2��łł��钷���`�̌�

�e�F���r�b�g�Ƃ��āA�}�X�N��������Ɗy
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	ll H, W; cin >> H >> W;
	vector<vector<int>> masu(H, vector<int>(W));
	for (int i = 0; i < H;i++) {
		for (int j = 0; j < W;j++) {
			int c; cin >> c;
			masu[i][j] = (1 << c);
		}
	}

	ll res[8];
	memset(res, 0, sizeof(res));
	ll cnt[8];
	for (int i = 0; i < H;i++) {
		for (int j = i + 1; j < H;j++) {
			memset(cnt, 0, sizeof(cnt));
			for (int k = 0; k < W;k++) {
				cnt[masu[i][k]| masu[j][k]]++;
			}
			for (int k = 0; k < 8;k++) {
				for (int l = k + 1; l < 8;l++) {
					res[k | l] += cnt[k] * cnt[l];
				}
			}
		}
	}
	cout << res[7] << endl;
	return 0;
}