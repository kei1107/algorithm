/*
 update : [s,t) に xを加算
 query  : [s,t) の　最大(小)値を出力する
 */

/* [0..N-1] */
const ll INIT = 0; // 問題に合わせる
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
    
    void lazy_evaluate(int l, int r,int k){
        node[k] += lazy[k];
        if(r - l > 1){
            lazy[2 * k + 1] += lazy[k];
            lazy[2 * k + 2] += lazy[k];
        }
        lazy[k] = 0;
    }
    
    /* [a,b) 引数の範囲に注意!! s~tまでを更新→update(s,t+1,~) */
    void update(int a, int b, ll x) { update(a, b, 0, 0, N, x); }
    void update(int a, int b, int k, int l, int r, ll x) {
        lazy_evaluate(l,r,k);
        if (r <= a || b <= l) return;
        if (a <= l && r <= b) {
            lazy[k] += x;
            lazy_evaluate(l,r,k);
        }
        else {
            update(a, b, 2 * k + 1, l, (l + r) / 2, x);
            update(a, b, 2 * k + 2, (l + r) / 2, r, x);
            node[k] = min(node[2 * k + 1],node[2 * k + 2]);
        }
    }
    
    /* [a,b) 引数の範囲に注意!! */
    ll query(int a, int b) { return query(a, b, 0, 0, N); }
    ll query(int a, int b, int k, int l, int r) {
        lazy_evaluate(l, r, k);
        if (r <= a || b <= l) return LLONG_MAX; // min : LLONG_MAX , max : LLONG_MIN
        if (a <= l && r <= b) {
            return node[k];
        }
        else {
            ll vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
            ll vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
            return min(vl, vr);
        }
    }
};

// ======================================================== //

// ver.2

/*starry sky tree
 add(O(logN)):区間[a, b)に値xを加算する
 getMin(O(logN)): 区間の最小値を得る
 */
static const int MAX_SIZE = 1 << 17; // 2^n !!
typedef long long ll;
ll segMin[2 * MAX_SIZE - 1], segAdd[2 * MAX_SIZE - 1];

void add(int a, int b, int x, int k = 0, int l = 0, int r = MAX_SIZE){
    if (r <= a || b <= l) return; //もし交差しない区間であれば終える.
    
    if (a <= l && r <= b){ //もし今みている区間[l, r)が[a, b)に完全に内包されていれば
        segAdd[k] += x;  //区間[l, r)にkを加算する.
        return;
    }
    
    //子の区間に(必要があれば)xを加算する.
    add(a, b, x, k * 2 + 1, l, (l + r) / 2);
    add(a, b, x, k * 2 + 2, (l + r) / 2, r);
    
    //親の区間の最小値は, 子の区間の最小値 + 自分に一様に加算されている値 である.一様に加算される値は更新しなくて良い.
    segMin[k] = min(segMin[k * 2 + 1] + segAdd[k * 2 + 1], segMin[k * 2 + 2] + segAdd[k * 2 + 2]);
}

ll getMin(int a, int b, int k = 0, int l = 0, int r = MAX_SIZE){
    if (r <= a || b <= l) return (LLONG_MAX);
    if (a <= l && r <= b) return (segMin[k] + segAdd[k]); //完全に内包されていれば,その区間の最小値を返す.
    
    ll left = getMin(a, b, k * 2 + 1, l, (l + r) / 2); //子の区間の最小値を求める.
    ll right = getMin(a, b, k * 2 + 2, (l + r) / 2, r); //子の区間の最小値を求める
    
    //親の区間の最小値は, 子の区間の最小値 + 自分に一様に加算されている値
    return (min(left, right) + segAdd[k]);
}
