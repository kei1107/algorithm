#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define INF INT_MAX
#define LINF 1LL<<60

/* [0..N-1] */
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
		if (k >= N - 1)node[k] += lazy[k];
		if (k < N - 1) {
			lazy[2 * k + 1] += lazy[k] / 2;
			lazy[2 * k + 2] += lazy[k] / 2;
		}
		lazy[k] = 0;
	}

	/* [a,b) ˆø”‚Ì”ÍˆÍ‚É’ˆÓ!! s~t‚Ü‚Å‚ðXV¨update(s,t+1,~) */
	void update(int a, int b, int x) { update(a, b, 0, 0, N, x); }
	void update(int a, int b, int k, int l, int r, int x) {
		if (r <= a || b <= l) return;
		if (a <= l && r <= b) {
			lazy[k] += (r - l)*x;
			lazy_evaluate(k);
		}
		else {
			lazy_evaluate(k);
			update(a, b, 2 * k + 1, l, (l + r) / 2, x);
			update(a, b, 2 * k + 2, (l + r) / 2, r, x);
		}
	}

	/* [a,b) ˆø”‚Ì”ÍˆÍ‚É’ˆÓ!! */
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
			return max(vl, vr);
		}
	}
};
