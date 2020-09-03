#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T>& V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> >& Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T>& mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }
template<typename T>vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}
/*
 <url:>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */

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

struct Monoid {
    using Type = ll;/* Monoidに乗せる型 */
    static Type id() { return 0; /* モノイドの初期値 */};
    
    // ================================================ //
    //                              マージ処理                               //
    // ================================================ //
    static Type op(const Type&l, const Type &r) {
        Type ret;
        ret = max(l,r);
        return ret;
    }
};

template<class Type>
Type solve(Type res = Type()){
    int H,W,M; cin >> H >> W >> M;
    vector<vector<int>> Hs(H);
    vector<vector<int>> Ws(W);

    for(int i = 0; i < M;i++){
        int h,w; cin >> h >> w;
        h--; w--;

        Hs[h].emplace_back(w);
        Ws[w].emplace_back(h);
    }

    SegmentTree<Monoid> ST(H);
    for(int i = 0; i < H;i++){
        ST.set(i,Hs[i].size());
    }
    ST.build();

    for(int i = 0; i < W;i++){
        // i列目の情報を消す
        for(auto h:Ws[i]){
            ST.update(h,ST.query(h,h+1)-1);
        }

        // 計算
        res = max(res,ST.query(0,H)+(ll)Ws[i].size());

        // i列目の情報を戻す
        for(auto h:Ws[i]){
            ST.update(h,ST.query(h,h+1)+1);
        }

    }

    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    //solve<ll>(0);
    cout << fixed << setprecision(12) << solve<ll>() << endl;
    return 0;
}