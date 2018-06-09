/*
 update : k を x に変更
 query : [s,t) の最小(大)を出力する
 */
const ll INIT = INT_MAX;
struct SegTree {
    int N;
    ll init_v;
    vector<ll> node;
    
    SegTree(int _N):init_v(INIT) {
        N = 1;
        while (N < _N) N *= 2;
        node.resize(2 * N - 1, init_v);
    }
    
    ll merge(ll l,ll r){
        return min(l,r);
    }
    void update(int k, ll val) {
        k += N - 1;
        node[k] = val;
        while (k) {
            k = (k - 1) / 2;
            node[k] = merge(node[2 * k + 1], node[2 * k + 2]);
        }
    }
    ll query(int a,int b){ return query(a,b,0,0,N);}
    ll query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return init_v;
        if (a <= l && r <= b) return node[k];
        else {
            ll vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
            ll vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
            return merge(vl, vr);
        }
    }
};
