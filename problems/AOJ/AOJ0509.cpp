#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0509>
��蕶============================================================
���ʂɒ����`�̃V�[�g���������u����Ă���.�����̃V�[�g�ŕ����Ă��镔���̖ʐς���������߂�v���O�������쐬����.
������, ���ʂ����W���ʂƂ݂Ȃ����Ƃ�, �V�[�g�̔z�u�͎��̏��� (1), (2) �𖞂������̂Ƃ���.
(1) �e�V�[�g�̒����`�� 4 ���_�� x, y ���W�͑S�� 0 �ȏ� 10000 �ȉ��̐����ł���,
    �����`�̊e�ӂ� x ��, �܂��� y ���ɕ��s�ł���.
(2) �V�[�g�̖����͍��X 10000 ���ȉ��ł���.
���̓f�[�^ �� 1 �s�ڂɒ����`�̌� n �Ɩ��̎�ނ�\������ r ���󔒂ŋ�؂��ď�����Ă���.
2 �s�ڈȍ~�̊e�s�ɂ�, �e�V�[�g�̍������_���W (x1, y1) �ƉE�㒸�_���W (x2, y2) �̍��W�l��
x1, y1, x2, y2 �̏��ŋ󔒂ŋ�؂��ď����Ă���.

�o�͂ɂ� r = 1 �̂Ƃ� 1 �s�ڂɖʐς�, r = 2 �̂Ƃ� 1 �s�ڂɖʐ�, 2 �s�ڂɎ��͂̒������o�͂���.
������̏ꍇ���Ō�ɉ��s�����邱��.

=================================================================

���=============================================================

���񂪎ク��΂����������ʐϖ��͓񎟌��ݐϘa�ŉ������Ƃ��ł���A
�ݐϘa�v�Z���s���A�ݐϘa�����ƂȂ镔�����͂܂�Ă��镔���ƂȂ�A�����グ��΂��ꂪ�ʐςƂȂ�B
�O���Ɋւ��Ă��A�ݐϘa��0�Ɛ��l�̋��̐��𐔂���΂悢�B

�����A���̖��̏ꍇ�͐��񂩂�P���ɗݐϘa�z�������MLE�ƂȂ邽�߁A�s���Ƃɍl���Ĕz����g���܂킷�B

�Q�l�T�C�g<http://algoogle.hadrori.jp/aoj/0509/>

================================================================
*/

int m[2][10010];
vector<pll> ps[10010];
int maxh, maxw;
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	ll N, r;
	while (cin >> N >> r, N | r) {
		maxh = -1, maxw = -1;
		memset(m, 0, sizeof(m));
		for (int i = 0; i < 10010;i++) ps[i].clear();
		for (int i = 0;i < N;i++) {
			int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
			x1++; y1++; x2++; y2++;
			ps[y1].push_back({ x1,1 });
			ps[y1].push_back({ x2,-1 });
			ps[y2].push_back({ x1,-1 });
			ps[y2].push_back({ x2,1 });
			maxh = max(maxh, y2);
			maxw = max(maxw, x2);
		}

		int Area = 0, Length = 0;
		int cur = 0, next = 1;
		for (int i = 0; i <= maxh + 1;i++) {
			memset(m[next], 0, sizeof(m[next]));
			for (auto p : ps[i]) {
				m[next][p.first] += p.second; // �ݐϘa�̏������
			}
			for (int j = 0; j <= maxw;j++) {
				m[next][j + 1] += m[next][j]; // �ݐϘa ����֓`�d
				m[next][j] += m[cur][j]; // �ݐϘa �c���֓`�d
			}
			for (int j = 0; j <= maxw;j++) {
				if (m[next][j] > 0) Area++;
				if ((m[cur][j] > 0) != (m[next][j] > 0)) Length++;
				if ((m[next][j] > 0) != (m[next][j + 1] > 0)) Length++;
			}
			cur = !cur;
			next = !next;
		}
		cout << Area << endl;
		if (r == 2) cout << Length << endl;
	}
	return 0;
}