#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define INF INT_MAX
#define LINF 1LL<<60

struct SegTree {
	int N;
	ll init_v = 0;
	vector<ll> node, lazy;

	SegTree(int _N) {
		N = 1;
		while (N < _N) N *= 2;
		node.resize(2 * N - 1, init_v);
		lazy.resize(2 * N - 1, init_v);
	}

	void lazy_evaluate(int k) {
		node[k] += lazy[k]; // add �̂��߉��Z
		if (k < N - 1) {
			lazy[2 * k + 1] += lazy[k] / 2; // add �̂��߉��Z
			lazy[2 * k + 2] += lazy[k] / 2;
		}
		lazy[k] = 0;
	}

	/* [a,b) �����͈̔͂ɒ���!! s~t�܂ł��X�V��update(s,t+1,~) */
	ll update(int a, int b, int x) { return update(a, b, 0, 0, N, x); }
	ll update(int a, int b, int k, int l, int r, int x) {
		if (r <= a || b <= l) {
			lazy_evaluate(k); // node���Q�Ƃ���O�ɂ͕K���X�V
			return node[k];
		}
		if (a <= l && r <= b) {
			lazy[k] += (r - l) * x; // �Q�Ƌ�Ԃ��w���Ԃ����S�Ɋ܂�ł����, �Q�Ƌ�Ԓ�*���Z�l��node�ɉ��Z�����
			lazy_evaluate(k);
			return node[k];
		}
		else {
			lazy_evaluate(k);
			ll vl = update(a, b, 2 * k + 1, l, (l + r) / 2, x);
			ll vr = update(a, b, 2 * k + 2, (l + r) / 2, r, x);
			return node[k] = vl + vr;
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
			return vl + vr;
		}
	}
};
