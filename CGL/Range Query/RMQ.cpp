#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define INF INT_MAX
#define LINF 1LL<<60

struct SegTree {
	int N;
	ll init_v = INF;
	vector<ll> node;

	SegTree(int _N) {
		N = 1;
		while (N < _N) N *= 2;
		node.resize(2 * N - 1, INF);
	}

	void update(int k, ll val) {
		k += N - 1;
		node[k] = val;
		while (k) {
			k = (k - 1) / 2;
			node[k] = min(node[2 * k + 1], node[2 * k + 2]);
		}
	}
	ll query(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l) return INF;
		if (a <= l && r <= b) return node[k];
		else {
			ll vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
			ll vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
			return min(vl, vr);
		}
	}
	ll rmq(int a, int b) { return query(a, b, 0, 0, N); }
};
