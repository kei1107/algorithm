#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:https://www.ioi-jp.org/camp/2008/2008-sp-tasks/2008-sp_tr-day1_20.pdf>
��蕶============================================================
�����O�Ƃ����؍\�����^������B
�e�ӂɂ̓R�X�g���^�����Ă���A������q��H���čs�������̂��̃R�X�g���ő�ƂȂ鎞�̒l�����߂�
�������������_��n(<=100000), i�Ԗڂ̒��_�̐e��si(0<=si<i), �R�X�gai(-100<=ai<=100)
=================================================================
���=============================================================

�[���D��T���ŒH���Ă�����ok
�o�̓R�X�g�����ɂȂ肤�邽�߁A����������0�ɂ��Ȃ��悤�ɒ���
================================================================
*/

vector<int> C;
vector<vector<int>> G;
vector<int> memo;
int dfs(int n) {
	int res = C[n];
	for (auto next : G[n]) {
		res += max(0, dfs(next));
	}
	return (memo[n] = res);
}

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	int N; cin >> N;
	C.assign(N + 1, 0);
	G.assign(N + 1, vector<int>());
	memo.assign(N + 1, 0);
	for (int i = 1; i <= N;i++) {
		int v, c; cin >> v >> c;
		G[v].push_back(i);
		C[i] = c;
	}
	dfs(0);
	cout << *max_element(memo.begin()+1, memo.end()) << endl;
	return 0;
}
