#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:https://beta.atcoder.jp/contests/arc085/tasks/arc085_c>
��蕶============================================================
��΂�N ����C���ꂼ��1,2,...,N �Ɛ���������Ă��܂��B
���Ȃ��́C�ȉ��̑�����D���Ȃ����s�����Ƃ��o���܂�(��x���s��Ȃ��Ă��悢�ł�)�B
������x ��I�ԁBx �̔{���������ꂽ��΂�S�Ē@������B
�����āCi ��������Ă�����΂�����ꂸ�Ɏc���Ă����ꍇ�C
ai �~�Ⴂ�܂��B �������C����ai �͕��̏ꍇ������C���̏ꍇ�͂����𕥂�Ȃ��Ă͂����܂���B

���܂�������s�������C���Ȃ��͍ő�ŉ��~������Ⴆ��ł��傤���H
=================================================================
���=============================================================

�ŏ��J�b�g���ɋA���ł���A�A�A�A�A�炵��

a_i <= 0 �Ȃ�� s -> i �� cost -a_i�@�̕�
a_i > 0 �Ȃ�� i -> t �Ɂ@cost a_i �̕�
�ej=2i,3i,4i,...�ɂ��� i->j�ɗe��inf�̕�

�𒣂��ė����΂悢


================================================================
*/

struct edge {
	int to; // �s����
	ll cap; // �e��
	int rev; // �t��
	edge() {}
	edge(int to, ll cap, int rev) :to(to), cap(cap), rev(rev) {}
};

vector<vector<edge>> G; // �O���t�̗אڃ��X�g�\��
vector<int> used; // DFS�ł��łɒ��ׂ���t���O

				  // from����to�֌������e��cap�̕ӂ��O���t�ɒǉ�����
void add_edge(int from, int to, ll cap) {
	G[from].push_back(edge(to, cap, G[to].size()));
	G[to].push_back(edge(from, 0, G[from].size() - 1));
}

// �����p�X��DFS�ŒT��
ll dfs(int v, int t, ll f) {
	if (v == t) return f;
	used[v] = true;
	for (int i = 0; i < G[v].size(); i++) {
		edge &e = G[v][i];
		if (!used[e.to] && e.cap > 0) {
			ll d = dfs(e.to, t, min(f, e.cap));
			if (d > 0) {
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}

// s����t�ւ̍ő嗬�����߂�
ll max_flow(int s, int t) {
	ll flow = 0;
	for (;;) {
		fill(used.begin(), used.end(), 0);
		ll f = dfs(s, t, INF);
		if (f == 0) return flow;
		flow += f;
	}
}

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	ll N; cin >> N;
	G.resize(N + 2); used.resize(N + 2);

	ll Sum = 0;
	for (int i = 1; i <= N;i++) {
		ll a; cin >> a;
		for (int j = 2 * i; j <= N; j += i) add_edge(i, j, LINF);
		if (a > 0) {
			Sum += a;
			add_edge(i, N + 1, a);
		}
		else {
			add_edge(0, i, -a);
		}
	}
	cout << Sum - max_flow(0, N + 1) << endl;
	return 0;
}