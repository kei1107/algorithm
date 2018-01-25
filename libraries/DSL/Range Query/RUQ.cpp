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

	/* [a,b) 引数の範囲に注意!! s~tまでを更新→update(s,t+1,~) */
	void update(int a, int b, int x) { update(a, b, 0, 0, N, x); }
	void update(int a, int b, int k, int l, int r, int x) {
		if (r <= a || b <= l) return;
		if (a <= l && r <= b) {
			lazy[k] = x;
			lazy_evaluate(k);
		}
		else {
			lazy_evaluate(k);
			update(a, b, 2 * k + 1, l, (l + r) / 2, x);
			update(a, b, 2 * k + 2, (l + r) / 2, r, x);
		}
	}

	/* [a,b) 引数の範囲に注意!! */
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