#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60
/*
<url:https://colopl2018-qual.contest.atcoder.jp/tasks/colopl2018_qual_c>
��蕶============================================================
���ʂ��N�́A���̓��ɂ���܂łɐH�ׂ��ǂ̃J�[�h�ɏ����ꂽ�����Ƃ��݂��ɑf�ł��鐮���̏����ꂽ�J�[�h��H�ׂ��Ƃ��A��ԁB�����łȂ��Ƃ��A�߂��ށB

�����̃J�[�h�V���b�v�ɂ� A �ȏ� B �ȉ��̐����̏����ꂽ�J�[�h�� 1 ���������Ă��܂��B 
���Ȃ��́A���̂����� 0 ���ȏ�̔C�ӂ̖������w�����A���ׂẴJ�[�h�����ʂ��N�ɗ^���邱�Ƃɂ��܂����B���̂Ƃ��A���ʂ��N�� 1 �x�ł��߂��܂��Ă͂����܂���B
�J�[�h�̔������͉��ʂ肠��ł��傤���B
=================================================================
���=============================================================
�×~�S�T���@�C��
================================================================
*/
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }

ll A, B;
ll N;
ll res;
vector<vector<int>> check;
void dfs(ll dep,vector<int>& L) {
	if (dep > N) {
		res++;
		return;
	}
	bool f = true;;
	for (auto l : L) {
		if (check[l][dep] == 0) {
			f = false;
			break;
		}
	}
	auto tmp = L;
	dfs(dep + 1, tmp);
	if (f) {
		auto tmp = L;
		tmp.push_back(dep);
		dfs(dep + 1, tmp);
	}
}

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	cin >> A >> B;
	N = B - A;
	check.assign(N+1, vector<int>(N+1, 0));
	for (int i = 0; i <= N;i++) {
		for (int j = i + 1; j <= N;j++) {
			if (gcd(A + i, A + j) == 1) {
				check[i][j] = check[j][i] = 1;
			}
		}
	}
	vector<int> L;
	dfs(0, L);
	cout << res << endl;
	return 0;
}