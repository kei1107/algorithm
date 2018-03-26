
/*
 update : k に xを加算
 query : [s,t) の総和を出力
 */
const ll INIT = 0;
struct SegTree {
	int N;
	ll init_v;
	vector<ll> node;

    SegTree(int _N):init_v(INIT) {
		N = 1;
		while (N < _N) N *= 2;
		node.resize(2 * N - 1, init_v);
	}

	void update(int k, ll val) {
		k += N - 1;
		node[k] += val;
		while (k) {
			k = (k - 1) / 2;
			//node[k] = node[2 * k + 1] + node[2 * k + 2];
			node[k] += val;
		}
	}
	ll query(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l) return init_v;
		if (a <= l && r <= b) return node[k];
		else {
			ll vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
			ll vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
			return vl + vr;
		}
	}
	ll rsq(int a, int b) { return query(a, b, 0, 0, N); }
};
