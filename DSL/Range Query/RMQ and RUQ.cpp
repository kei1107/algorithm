#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define INF INT_MAX
#define LINF 1LL<<60

struct SegTree {
	int N;
	ll init_v = INF;
	vector<ll> node, lazy;

	SegTree(int _N) {
		N = 1;
		while (N < _N) N *= 2;
		node.resize(2 * N - 1, init_v);
		lazy.resize(2 * N - 1, -1);
	}

	void lazy_evaluate(int k) {
		if (lazy[k] == -1) return;
		node[k] = lazy[k];
		if (k < N - 1) {
			lazy[2 * k + 1] = lazy[k];
			lazy[2 * k + 2] = lazy[k];
		}
		lazy[k] = -1;
	}

	/* [a,b) �����͈̔͂ɒ���!! s~t�܂ł��X�V��update(s,t+1,~) */
	ll update(int a, int b, int x) { return update(a, b, 0, 0, N, x); }
	ll update(int a, int b, int k, int l, int r, int x) {
		if (r <= a || b <= l) {
			lazy_evaluate(k); // node�̒l������Ƃ��͕K���x���]�����X�V����
			return node[k]; // update�ł͑S�̂̒��̍ŏ���������K�v�����邽��, [l,r)�O�ɂȂ��Ă��l���Q��
		}
		if (a <= l && r <= b) {
			lazy[k] = x;�@
			lazy_evaluate(k);
			return node[k];
		}
		else {
			lazy_evaluate(k);
			ll vl = update(a, b, 2 * k + 1, l, (l + r) / 2, x);
			ll vr = update(a, b, 2 * k + 2, (l + r) / 2, r, x);
			return node[k] = min(vl, vr);
		}
	}

	/* [a,b) �����͈̔͂ɒ���!! */
	ll query(int a, int b) { return query(a, b, 0, 0, N); }
	ll query(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l) return init_v;
		if (a <= l && r <= b) {
			lazy_evaluate(k);
			return node[k];
		}
		else {
			lazy_evaluate(k);
			ll vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
			ll vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
			return min(vl, vr);
		}
	}
};
