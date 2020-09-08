/*
 抽象化LazySegTree
 ref : https://ei1333.github.io/algorithm/segment-tree.html
 */

template< typename Monoid>
struct LazySegmentTree{
public:
    using Type = typename Monoid::Type;
    int sz; // Array size
    
    vector<Type> node;
    vector<Type> lazy;
    
    LazySegmentTree(int n){
        sz = 1;
        while(sz < n) sz <<= 1;
        node.assign(2*sz,Monoid::id());
        lazy.assign(2*sz,Monoid::Nid());
    }
    void set(int k, const Type& val){ node[k + sz] = val; }
    void build(){
        for(int k = sz - 1; k > 0; k--) {
            node[k] = Monoid::op1(node[2*k+0], node[2*k+1]);
        }
    }
    
    void lazy_update(int k, int len){
        if(lazy[k] != Monoid::Nid()){
            if(k < sz){
                lazy[2 * k + 0] = Monoid::op3(lazy[2 * k + 0], lazy[k]);
                lazy[2 * k + 1] = Monoid::op3(lazy[2 * k + 1], lazy[k]);
            }
            node[k] = Monoid::op2(node[k],Monoid::op4(lazy[k],len));
            lazy[k] = Monoid::Nid();
        }
    }
    inline Type update(int a,int b,const Type& val,int k,int l,int r){
        lazy_update(k, r-l);
        if(r <= a || b <= l){
            return node[k];
        }else if(a <= l && r <= b){
            lazy[k] = Monoid::op3(lazy[k],val);
            lazy_update(k, r-l);
            return node[k];
        }else{
            return node[k] = Monoid::op1(
                                         update(a, b, val, 2 * k + 0, l, (l+r)/2),
                                         update(a, b, val, 2 * k + 1, (l+r)/2, r)
                                         );
        }
    }
    inline Type update(int a,int b,const Type& val){
        return update(a,b,val,1,0,sz);
    }
    inline Type query(int a,int b,int k,int l,int r){
        lazy_update(k, r - l);
        if(r <= a || b <= l) {
            return Monoid::Qid();
        } else if(a <= l && r <= b) {
            return node[k];
        } else {
            return Monoid::op1(
                               query(a, b, 2 * k + 0, l, (l + r)/2),
                               query(a, b, 2 * k + 1, (l + r)/2, r)
                               );
        }
    }
    inline Type query(int a,int b){
        return query(a,b,1,0,sz);
    }
    Type operator[](int k){
        return query(k,k+1);
    }
};
struct Monoid {
    using Type = ;/* Monoidに乗せる型 */
    static Type id() { return  ; /* モノイドの初期値 */};
    static Type Nid() { return ; /* 遅延評価時の初期値 */}
    static Type Qid() { return ; /* 範囲外クエリ処理時の値 */}
    
    //  =========  //
    //  マージ処理  //
    //  =========  //
 
    // 要素と要素のマージ
    static Type op1(const Type&l, const Type &r) {
        Type ret;
        return ret;
    }
    
    // 要素と作用素のマージ
    static Type op2(const Type&l, const Type &r) {
        Type ret;
        return ret;
    }
    
    // 作用素と作用素のマージ
    static Type op3(const Type&l, const Type &r) {
        Type ret;
        return ret;
    }
    
    // 作用素を下に降ろす時に行う演算
    // (第一引数は作用素のもとの値, 第二引数は降ろした後の区間の長さ)
    static Type op4(const Type&l, const int &r) {
        Type ret;
        return ret;
    }
};



/* ======================================================================
 RMQ and RAQ
 
 Verify
 http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H
 */

struct Monoid {
    using Type = ll;/* Monoidに乗せる型 */
    static Type id() { return  0; /* モノイドの初期値 */};
    static Type Nid() { return 0; /* 遅延評価時の初期値 */}
    static Type Qid() { return LINF; /* 範囲外クエリ処理時の値 */}
    
    // ================================================ //
    //                              マージ処理                               //
    // ================================================ //
    
    // 要素と要素のマージ
    static Type op1(const Type&l, const Type &r) {
        Type ret;
        ret = min(l,r);
        return ret;
    }
    
    // 要素と作用素のマージ
    static Type op2(const Type&l, const Type &r) {
        Type ret;
        ret = l + r;
        return ret;
    }
    
    // 作用素と作用素のマージ
    static Type op3(const Type&l, const Type &r) {
        Type ret;
        ret = l + r;
        return ret;
    }
    
    // 作用素を下に降ろす時に行う演算
    // (第一引数は作用素のもとの値, 第二引数は降ろした後の区間の長さ)
    static Type op4(const Type&l, const int &r) {
        Type ret;
        ret = l;
        return ret;
    }
};

template<class Type>
Type solve(Type res = Type()){
    int n,q; cin >> n >> q;
    LazySegmentTree<Monoid> LST(n);
    while(q--){
        int com; cin >> com;
        if(com == 0){
            int s,t,x; cin >> s >> t >> x;
            LST.update(s,t+1,x);
        }else{
            int s,t; cin >> s >> t;
            cout << LST.query(s,t+1) << endl;
        }
    }
    return res;
}

/* ======================================================================
 RSQ and RAQ
 
 Verify
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G
 */
struct Monoid {
    using Type = ll;/* Monoidに乗せる型 */
    static Type id() { return  0; /* モノイドの初期値 */};
    static Type Nid() { return 0; /* 遅延評価時の初期値 */}
    static Type Qid() { return  0; /* 範囲外クエリ処理時の値 */}
    
    // ================================================ //
    //                              マージ処理                               //
    // ================================================ //
    
    // 要素と要素のマージ
    static Type op1(const Type&l, const Type &r) {
        Type ret;
        ret = l + r;
        return ret;
    }
    
    // 要素と作用素のマージ
    static Type op2(const Type&l, const Type &r) {
        Type ret;
        ret = l + r;
        return ret;
    }
    
    // 作用素と作用素のマージ
    static Type op3(const Type&l, const Type &r) {
        Type ret;
        ret = l + r;
        return ret;
    }
    
    // 作用素を下に降ろす時に行う演算
    // (第一引数は作用素のもとの値, 第二引数は降ろした後の区間の長さ)
    static Type op4(const Type&l, const int &r) {
        Type ret;
        ret = l * r;
        return ret;
    }
};

template<class Type>
Type solve(Type res = Type()){
    int n,q; cin >> n >> q;
    LazySegmentTree<Monoid> LST(n);
    while(q--){
        int com; cin >> com;
        if(com == 0){
            int s,t,x; cin >> s >> t >> x;
            s--; t--;
            LST.update(s,t+1,x);
        }else{
            int s,t; cin >> s >> t;
            s--; t--;
            cout << LST.query(s,t+1) << endl;
        }
    }
    return res;
}

/* ======================================================================
 RMQ and RUQ
 
 Verify
 http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F
 */
struct Monoid {
    using Type = ll;/* Monoidに乗せる型 */
    static Type id() { return  INT_MAX; /* モノイドの初期値 */};
    static Type Nid() { return INT_MAX; /* 遅延評価時の初期値 */}
    static Type Qid() { return  LINF; /* 範囲外クエリ処理時の値 */}
    
    // ================================================ //
    //                              マージ処理                               //
    // ================================================ //
    
    // 要素と要素のマージ
    static Type op1(const Type&l, const Type &r) {
        Type ret;
        ret = min(l,r);
        return ret;
    }
    
    // 要素と作用素のマージ
    static Type op2(const Type&l, const Type &r) {
        Type ret;
        ret = r; // update : rを優先
        return ret;
    }
    
    // 作用素と作用素のマージ
    static Type op3(const Type&l, const Type &r) {
        Type ret;
        ret = r; // update : rを優先
        return ret;
    }
    
    // 作用素を下に降ろす時に行う演算
    // (第一引数は作用素のもとの値, 第二引数は降ろした後の区間の長さ)
    static Type op4(const Type&l, const int &r) {
        Type ret;
        ret = l;
        return ret;
    }
};

template<class Type>
Type solve(Type res = Type()){
    int n,q; cin >> n >> q;
    LazySegmentTree<Monoid> LST(n);
    while(q--){
        int com; cin >> com;
        if(com == 0){
            int s,t,x; cin >> s >> t >> x;
            LST.update(s,t+1,x);
        }else{
            int s,t; cin >> s >> t;
            cout << LST.query(s,t+1) << endl;
        }
    }
    return res;
}

/* ======================================================================
 RSQ and RUQ
 
 Verify
 http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I
 */
struct Monoid {
    using Type = ll;/* Monoidに乗せる型 */
    static Type id() { return  0; /* モノイドの初期値 */};
    static Type Nid() { return LINF; /* 遅延評価時の初期値 */}
    static Type Qid() { return  0; /* 範囲外クエリ処理時の値 */}
    
    // ================================================ //
    //                              マージ処理                               //
    // ================================================ //
    
    // 要素と要素のマージ
    static Type op1(const Type&l, const Type &r) {
        Type ret;
        ret = l + r;
        return ret;
    }
    
    // 要素と作用素のマージ
    static Type op2(const Type&l, const Type &r) {
        Type ret;
        ret = r;
        return ret;
    }
    
    // 作用素と作用素のマージ
    static Type op3(const Type&l, const Type &r) {
        Type ret;
        ret = r;
        return ret;
    }
    
    // 作用素を下に降ろす時に行う演算
    // (第一引数は作用素のもとの値, 第二引数は降ろした後の区間の長さ)
    static Type op4(const Type&l, const int &r) {
        Type ret;
        ret = l * r; // sum : 区間の長さ分だけ乗算
        return ret;
    }
};

template<class Type>
Type solve(Type res = Type()){
    int n,q; cin >> n >> q;
    LazySegmentTree<Monoid> LST(n);
    while(q--){
        int com; cin >> com;
        if(com == 0){
            int s,t,x; cin >> s >> t >> x;
            LST.update(s,t+1,x);
        }else{
            int s,t; cin >> s >> t;
            cout << LST.query(s,t+1) << endl;
        }
    }
    return res;
}

/* ======================================================================
// Range Affine Range Sum
/*
 * update : l,r,b,c
 *  区間[l,r) に対して ai <- b x ai + c
 * query  : l,r
 *  区間[l,r) の sum(a) mod m
 * 
 * 
 * 要素   {x,y} : { 要素の総和, 区間の長さ}
 * 作用素 {x,y} : { 乗数c, 加数d}
 */
const ll MOD = 998244353;
struct Monoid {
    using Type = pll;/* Monoidに乗せる型 */
    static Type id() { return  {0,0}; /* モノイドの初期値 */};
    static Type Nid() { return {1,0}; /* 遅延評価時の初期値 */}
    static Type Qid() { return id(); /* 範囲外クエリ処理時の値 */}
    
    //  =========  //
    //  マージ処理  //
    //  =========  //

    // 要素と要素のマージ
    static Type op1(const Type&l, const Type &r) {
        Type ret;
        ret.first = (l.first + r.first)%MOD;
        ret.second = l.second + r.second;
        return ret;
    }
    
    // 要素と作用素のマージ
    static Type op2(const Type&l, const Type &r) {
        Type ret;

        ret.first = (l.first * r.first % MOD + l.second * r.second % MOD )%MOD;
        ret.second = l.second;        
        return ret;
    }
    
    // 作用素と作用素のマージ
    static Type op3(const Type&l, const Type &r) {
        Type ret;

        ret.first = (l.first * r.first) %MOD;
        ret.second = (l.second * r.first + r.second)% MOD;

        return ret;
    }
    
    // 作用素を下に降ろす時に行う演算
    // (第一引数は作用素のもとの値, 第二引数は降ろした後の区間の長さ)
    static Type op4(const Type&l, const int &r) {
        Type ret = l;
        return ret;
    }
};
// https://atcoder.jp/contests/practice2/tasks/practice2_k
template<class Type>
Type solve(Type res = Type()){
    int N,Q; cin >> N >> Q;
    LazySegmentTree<Monoid> LST(N);
    for(int i = 0; i < N;i++){
        int a; cin >> a;
        LST.set(i,Monoid::Type(a,1));
    }
    LST.build();
    for(int i = 0; i < Q;i++){
        int t; cin >> t;

        if(t == 0){
            int l,r,c,d; cin >> l >> r >> c >> d;
            LST.update(l,r,Monoid::Type(c,d));
        }else{
            int l,r; cin >> l >> r;
            cout << LST.query(l,r).first << endl;
        }
    }
    return res;
}
