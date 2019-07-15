/*
 抽象化SegTree
 ref : https://ei1333.github.io/algorithm/segment-tree.html
 */
template <typename Monoid>
struct SegmentTree {
public:
    using Type = typename Monoid::Type;
    int sz; // Array size
    vector<Type>node;
    SegmentTree(int n){
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
    Type operator[](int i) { return node[i + sz]; }
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
