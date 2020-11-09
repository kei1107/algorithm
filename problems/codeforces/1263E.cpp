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
 <url:https://codeforces.com/problemset/problem/1263/E>
 問題文============================================================
 E. Editor
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
struct Monoid {
    using Type = pll;/* Monoidに乗せる型 */
    static Type id() { return  {0,0}; /* モノイドの初期値 */};
    static Type Nid() { return {0,0}; /* 遅延評価時の初期値 */}
    static Type Qid() { return {INF,-INF}; /* 範囲外クエリ処理時の値 */}
    
    //  =========  //
    //  マージ処理  //
    //  =========  //
 
    // 要素と要素のマージ
    static Type op1(const Type&l, const Type &r) {
        Type ret;
        
        ret.first = min(l.first,r.first);
        ret.second = max(l.second,r.second);

        return ret;
    }
    
    // 要素と作用素のマージ
    static Type op2(const Type&l, const Type &r) {
        Type ret;

        ret.first = l.first + r.first;
        ret.second = l.second + r.first;

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
    int n; cin >> n;
    string s; cin >> s;

    LazySegmentTree<Monoid> LST(n+1);
    string now_s(n,'#');
    int Lcnt = 0, Rcnt = 0;
    int id = 0;
    for(auto c:s){
        assert(id >= 0 && id < n);
        if(c == 'R'){
            id++;
        }else if(c == 'L'){
            id = max(0,id-1);
        }else{

            int diff = 0;
            if(now_s[id] == '('){
                // LST.update(id,n,{-1,0});
                diff--;
                Lcnt--;
            }
            if(now_s[id] == ')'){
                // LST.update(id,n,{+1,0});
                diff++;
                Rcnt--;
            }
            now_s[id] = c;
            if(now_s[id] == '('){
                // LST.update(id,n,{+1,0});
                diff++;
                Lcnt++;
            }
            if(now_s[id] == ')'){
                // LST.update(id,n,{-1,0});
                diff--;
                Rcnt++;
            }

            if(diff!=0){
                LST.update(id,n,{diff,0});
            }
        }

        pll ret = LST.query(0,n);
        if(ret.first == 0 && ret.second >= 0 && Lcnt == Rcnt){
            res.emplace_back(ret.second);
        }else{
            res.emplace_back(-1);
        }
    }

    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    //solve<ll>(0);
    cout << fixed << setprecision(12) << solve<vector<ll>>() << endl;
    return 0;
}