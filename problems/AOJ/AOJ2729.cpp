#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2729>
��蕶============================================================

1*Li�̒����`���������ŏc�ɕ���ł���

�C�ӂ̒����`�̋������A���̋��ƌ�������S�Ă̒����`����x�ɍ폜���邱�Ƃ��\�ȂƂ��A
�폜�����������`��S�ď����ɂ́A�Œ�ŉ�����̑I�����K�v���H

=================================================================
���=============================================================

�폜�����������`�̂����A�����̒Z�����̂��珇�Ԃɍ폜���悤�ƍl���Ă����΂悢

================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	int N; cin >> N;
	vector<char> D(N);
	vector<int> L(N);
	vector<pii> DL;
	ll res = 0;
	for (int i = 0; i < N;i++) {
		cin >> D[i] >> L[i];
		if (D[i] == 'y') {
			DL.push_back({ L[i],i });
		}
	}
	sort(DL.begin(), DL.end());
	vector<int> f(N, 0);
	for (int i = 0; i < (int)DL.size();i++) {
		int idx = DL[i].second;
		if (f[idx] == 1)continue;
		res++;
		int l = DL[i].first;
		for (int j = idx - 1; j >= 0;j--) {
			if (D[j] == 'y') f[j] = 1;
			else if (L[j] >= l)break;
		}
		for (int j = idx + 1; j < N;j++) {
			if (D[j] == 'y')f[j] = 1;
			else if (L[j] >= l)break;
		}
	}
	cout << res << endl;
	return 0;
}