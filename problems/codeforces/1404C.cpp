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
 <url:https://codeforces.com/contest/1404/problem/C>
 問題文============================================================
 C. Fixed Point Removal
 =================================================================
 解説=============================================================
 ================================================================
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

// RMQ / RAQ
struct Monoid1 {
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
// RMQ / RAQ
struct Monoid2 {
    using Type = pll;/* Monoidに乗せる型 */
    static Type id() { return  {0,0}; /* モノイドの初期値 */};
    static Type Nid() { return {0,0}; /* 遅延評価時の初期値 */}
    static Type Qid() { return {LINF,LINF}; /* 範囲外クエリ処理時の値 */}
    
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
        Type ret = l;
        ret.first += r.first;
        return ret;
    }
    
    // 作用素と作用素のマージ
    static Type op3(const Type&l, const Type &r) {
        Type ret;
        ret.first = l.first + r.first;
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
    vector<int> a(n);
    for(auto& in:a) cin >> in;
    using Item = tuple<int,int,int>;
    vector<Item> Q;

    vector<vector<pii>> x_id(n);
    for(int i = 0; i < q;i++){
        int x,y; cin >> x >> y;
        x_id[x].emplace_back(y,i);
    }
    LazySegmentTree<Monoid1> LST1(n);
    LazySegmentTree<Monoid2> LST2(n);
    for(int i = 0; i < n;i++){
        LST2.set(i,Monoid2::Type(0,-i));
    }
    LST2.build();

    vector<ll> ans(q);

    vector<ll> cnt(n+1);
    for(int i = n-1; i >= 0; i--){
        cnt[i] = cnt[i+1];

        LST2.update(i,i+1,Monoid2::Type((i+1)-a[i],0));
        while(true){
            int val,id;
            tie(val,id) = LST2.query(i,n);
            id = -id;
            if(val < 0){
                LST2.update(id,id+1,Monoid2::Type(INF,0));
            }else if(val > 0){
                break;
            }else{
                cnt[i]++;
                LST1.update(0,id,1);
                LST2.update(id,n,Monoid2::Type(-1,0));
            }
        }
        for(auto p:x_id[i]){
            int x = i;
            int y = p.first;
            int id = p.second;

            ans[id] = cnt[x] - LST1[(n-1)-y];
        }
    }
    for(int i = 0; i < q;i++){
        cout << ans[i] << endl;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    solve<ll>(0);
    // cout << fixed << setprecision(12) << solve<ll>() << endl;
    return 0;
}