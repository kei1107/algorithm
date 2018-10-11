/*
 update : [s,t)にxを加算する
 query : [s,t) の総和を出力する
 */
const ll INIT = 0;
struct SegTree {
    int N;
    ll init_v;
    vector<ll> node, lazy;
    
    SegTree(int _N):init_v(INIT) {
        N = 1;
        while (N < _N) N *= 2;
        node.resize(2 * N - 1, init_v);
        lazy.resize(2 * N - 1, init_v);
    }
    
    ll merge(ll l,ll r){
        return l + r;
    }
    void build(){
        for(int k = N - 2; k >= 0; k--){
            node[k] = merge(node[2*k+1],node[2*k+2]);
        }
    }
    void direct_update(int k,ll v){
        node[k+N-1] = v;
    }
    
    void lazy_evaluate(int k) {
        node[k] += lazy[k]; // add のため加算
        if (k < N - 1) {
            lazy[2 * k + 1] += lazy[k] / 2; // add のため加算
            lazy[2 * k + 2] += lazy[k] / 2;
        }
        lazy[k] = 0;
    }
    
    /* [a,b) 引数の範囲に注意!! s~tまでを更新→update(s,t+1,~) */
    ll update(int a, int b, ll x) { return update(a, b, 0, 0, N, x); }
    ll update(int a, int b, int k, int l, int r, ll x) {
        if (r <= a || b <= l) {
            lazy_evaluate(k); // nodeを参照する前には必ず更新
            return node[k];
        }
        if (a <= l && r <= b) {
            lazy[k] += (r - l) * x; // 参照区間が指定区間を完全に含んでいれば, 参照区間長*加算値分nodeに加算される
            lazy_evaluate(k);
            return node[k];
        }
        else {
            lazy_evaluate(k);
            ll vl = update(a, b, 2 * k + 1, l, (l + r) / 2, x);
            ll vr = update(a, b, 2 * k + 2, (l + r) / 2, r, x);
            return node[k] = merge(vl,vr);
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
            return merge(vl,vr);
        }
    }
};
