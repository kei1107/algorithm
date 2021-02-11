#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
inline ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
template <class S, class T>
ostream &operator<<(ostream &out, const pair<S, T> &o) {
    out << "(" << o.first << "," << o.second << ")";
    return out;
}
template <class T> ostream &operator<<(ostream &out, const vector<T> &V) {
    for(int i = 0; i < V.size(); i++) {
        out << V[i];
        if(i != V.size() - 1)
            out << " ";
    }
    return out;
}
template <class T>
ostream &operator<<(ostream &out, const vector<vector<T>> &Mat) {
    for(int i = 0; i < Mat.size(); i++) {
        if(i != 0)
            out << endl;
        out << Mat[i];
    }
    return out;
}
template <class S, class T>
ostream &operator<<(ostream &out, const map<S, T> &mp) {
    out << "{ ";
    for(auto it = mp.begin(); it != mp.end(); it++) {
        out << it->first << ":" << it->second;
        if(mp.size() - 1 != distance(mp.begin(), it))
            out << ", ";
    }
    out << " }";
    return out;
}
template <typename T> vector<T> make_v(size_t a) { return vector<T>(a); }
template <typename T, typename... Ts> auto make_v(size_t a, Ts... ts) {
    return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}
template <typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type fill_v(T &t, const V &v) {
    t = v;
}
template <typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type fill_v(T &t, const V &v) {
    for(auto &e : t)
        fill_v(e, v);
}
/*
 <url:https://atcoder.jp/contests/abc186/tasks/abc186_f>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */

/*
 抽象化SegTree
 ref : https://ei1333.github.io/algorithm/segment-tree.html
 */
template <typename Monoid> struct SegmentTree {
  public:
    using Type = typename Monoid::Type;
    int sz; // Array size
    int _n;
    vector<Type> node;
    SegmentTree(int n) : _n(n) {
        sz = 1;
        while(sz < n)
            sz <<= 1;
        node.assign(2 * sz, Monoid::id());
    }
    void set(int k, const Type &val) { node[k + sz] = val; }
    void build() {
        for(int k = sz - 1; k > 0; k--) {
            node[k] = Monoid::op(node[2 * k], node[2 * k + 1]);
        }
    }
    inline void update(int k, const Type &val) {
        k += sz;
        node[k] = val;
        while(k >>= 1) {
            node[k] = Monoid::op(node[2 * k], node[2 * k + 1]);
        }
    }
    inline Type query(int l, int r) {
        if(l >= r)
            return Monoid::id();
        Type vl = Monoid::id(), vr = Monoid::id();
        for(l += sz, r += sz; l != r; l >>= 1, r >>= 1) {
            if(l & 1)
                vl = Monoid::op(vl, node[l++]);
            if(r & 1)
                vr = Monoid::op(node[--r], vr);
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
        if(l == _n)
            return _n;
        l += sz;
        Type sm = Monoid::id();
        do {
            while(l % 2 == 0)
                l >>= 1;
            if(!f(Monoid::op(sm, node[l]))) {
                while(l < sz) {
                    l = (2 * l);
                    if(f(Monoid::op(sm, node[l]))) {
                        sm = Monoid::op(sm, node[l]);
                        l++;
                    }
                }
                return l - sz;
            }
            sm = Monoid::op(sm, node[l]);
            l++;
        } while((l & -l) != l);
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
        if(r == 0)
            return 0;
        r += sz;
        Type sm = Monoid::id();
        do {
            r--;
            while(r > 1 && (r % 2))
                r >>= 1;
            if(!f(Monoid::op(node[r], sm))) {
                while(r < sz) {
                    r = (2 * r + 1);
                    if(f(Monoid::op(node[r], sm))) {
                        sm = Monoid::op(node[r], sm);
                        r--;
                    }
                }
                return r + 1 - sz;
            }
            sm = Monoid::op(node[r], sm);
        } while((r & -r) != r);
        return 0;
    }

    Type operator[](int i) { return node[i + sz]; }
};

struct Monoid {
    using Type = ll; /* Monoidに乗せる型 */
    static Type id() { return 0; /* モノイドの初期値 */ };

    //  =========  //
    //  マージ処理  //
    //  =========  //
    static Type op(const Type &l, const Type &r) {
        Type ret;
        ret = l + r;
        return ret;
    }
};

template <class Type> Type solve(Type res = Type()) {
    int H, W, M;
    cin >> H >> W >> M;
    vector<int> X(M), Y(M);
    for(int i = 0; i < M; i++)
        cin >> X[i] >> Y[i];

    vector<vector<int>> R(H);
    for(int i = 0; i < M; i++) {
        X[i]--;
        Y[i]--;
        R[X[i]].emplace_back(Y[i]);
    }
    for(int i = 0; i < H; i++) {
        R[i].emplace_back(W); // banpei
        sort(R[i].begin(), R[i].end());
    }

    SegmentTree<Monoid> ST(W);
    for(int j = 0; j < R[0][0]; j++) {
        ST.set(j, 1);
    }
    ST.build();

    res = ST.query(0, W);

    bool calc_row = true;
    for(int i = 1; i < H; i++) {
        if(R[i][0] == 0) calc_row = false;
        for(auto j : R[i]){
            if(j != W){
                ST.update(j,0);
            }
        }
        if(calc_row) {
            res += R[i][0];
            res += ST.query(R[i][0]+1,W);
        }else{
            res += ST.query(0,W);
        }
    }

    return res;
}
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // solve<ll>(0);
    cout << fixed << setprecision(12) << solve<ll>() << endl;
    return 0;
}