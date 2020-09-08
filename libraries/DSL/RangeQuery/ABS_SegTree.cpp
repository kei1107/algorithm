/*
 抽象化SegTree
 ref : https://ei1333.github.io/algorithm/segment-tree.html
 */
template <typename Monoid>
struct SegmentTree {
public:
    using Type = typename Monoid::Type;
    int sz; // Array size
    int _n;
    vector<Type>node;
    SegmentTree(int n):_n(n){
        sz = 1;
        while(sz < n) sz <<= 1;
        node.assign(2*sz,Monoid::id());
    }
    void set(int k,const Type& val){
        node[k+sz] = val;
    }
    void build(){
        for(int k = sz - 1; k > 0; k--){
            node[k] = Monoid::op(node[2*k],node[2*k+1]);
        }
    }
    inline void update(int k, const Type& val) {
        k += sz;
        node[k] = val;
        while (k >>= 1) {
            node[k] = Monoid::op(node[2*k], node[2*k+1]);
        }
    }
    inline Type query(int l, int r) {
        if (l >= r)return Monoid::id();
        Type vl = Monoid::id(), vr = Monoid::id();
        for (l += sz, r += sz; l != r; l >>= 1, r >>= 1) {
            if (l & 1)  vl = Monoid::op(vl, node[l++]);
            if (r & 1)  vr = Monoid::op(node[--r], vr);
        }
        return Monoid::op(vl, vr);
    }

    /*
     * max_right
     * 
     * bool を返す評価関数fを用いて
     * 以下の条件を両方満たす rを（いずれか1つ返す)
     * - r = l もしくは f(op(a[l], a[l + 1], ..., a[r - 1])) = true
     * - r = n もしくは f(op(a[l], a[l + 1], ..., a[r])) = false
     * 
     * fの単調性を許せば
     * "f(op(a[l], a[l + 1], ..., a[r - 1])) = true となる最大のr"を返す
     */
    template <bool (*f)(Type)> int max_right(int l) {
        return max_right(l, [](Type x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) {
        assert(0 <= l && l <= _n);
        assert(f(Monoid::id()));
        if (l == _n) return _n;
        l += sz;
        Type sm = Monoid::id();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(Monoid::op(sm, node[l]))) {
                while (l < sz) {
                    l = (2 * l);
                    if (f(Monoid::op(sm, node[l]))) {
                        sm = Monoid::op(sm, node[l]);
                        l++;
                    }
                }
                return l - sz;
            }
            sm = Monoid::op(sm, node[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }


    /*
     * min_left
     * 
     * bool を返す評価関数lを用いて
     * 以下の条件を両方満たす lを（いずれか1つ返す)
     * - l = r もしくは f(op(a[l], a[l + 1], ..., a[r - 1])) = true
     * - l = 0 もしくは f(op(a[l - 1], a[l + 1], ..., a[r - 1])) = false
     * 
     * fの単調性を許せば
     * "f(op(a[l], a[l + 1], ..., a[r - 1])) = true となる最小のl"を返す
     */
    template <bool (*f)(Type)> int min_left(int r) {
        return min_left(r, [](Type x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) {
        assert(0 <= r && r <= _n);
        assert(f(Monoid::id()));
        if (r == 0) return 0;
        r += sz;
        Type sm = Monoid::id();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(Monoid::op(node[r], sm))) {
                while (r < sz) {
                    r = (2 * r + 1);
                    if (f(Monoid::op(node[r], sm))) {
                        sm = Monoid::op(node[r], sm);
                        r--;
                    }
                }
                return r + 1 - sz;
            }
            sm = Monoid::op(node[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

    Type operator[](int i) { return node[i + sz]; }
};

struct Monoid {
    using Type = **;/* Monoidに乗せる型 */
    static Type id() { return **; /* モノイドの初期値 */};
    
    //  =========  //
    //  マージ処理  //
    //  =========  //
    static Type op(const Type&l, const Type &r) {
        Type ret;
        return ret;
    }
};


/*
 Verify: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A&lang=jp
 */

struct Monoid {
    using Type = ll;/* Monoidに乗せる型 */
    static Type id() { return INT_MAX; /* モノイドの初期値 */};
    static Type op(const Type&l, const Type &r) {
        Type ret;
        /* マージ処理 */
        ret = min(l,r);
        return ret;
    }
};

template<class Type>
Type solve(Type res = Type()){
    int n,q; cin >> n >> q;
    SegmentTree<Monoid> ST(n);
    while(q--){
        int com,x,y; cin >> com >> x >> y;
        if(com == 0){
            ST.update(x,y);
        }else{
            cout << ST.query(x, y+1) << endl;
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve(0);
    // cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}

// verified max_left : https://atcoder.jp/contests/practice2/tasks/practice2_j
struct Monoid {
    using Type = ll;/* Monoidに乗せる型 */
    static Type id() { return -1; /* モノイドの初期値 */};
    
    //  =========  //
    //  マージ処理  //
    //  =========  //
    static Type op(const Type&l, const Type &r) {
        Type ret = max(l,r);
        return ret;
    }
};
template<class Type>
Type solve(Type res = Type()){
    int N,Q; cin >> N >> Q;

    SegmentTree<Monoid> ST(N);
    for(int i = 0; i < N;i++){
        int A; cin >> A;
        ST.set(i,A);
    }
    ST.build();

    while(Q--){
        int T; cin >> T;
        if(T == 1){
            int X,V; cin >> X >> V;
            ST.update(X-1,V);
        }else if(T == 2){
            int L,R; cin >> L >> R;
            cout << ST.query(L-1,R) << endl;
        }else{
            int X,V; cin >> X >> V;
            ll ret = ST.max_right(X-1,[V](Monoid::Type x){return x < V;});
            cout << ret + 1 << endl;
        }
    }
    return res;
}
