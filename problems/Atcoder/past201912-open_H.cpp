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
 <url:https://atcoder.jp/contests/past201912-open/tasks/past201912_h>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
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
    
    ll merge(ll l,ll r){
        return min(l,r);
    }
    void build(){
        for(int k = N - 2; k >= 0; k--){
            node[k] = merge(node[2*k+1],node[2*k+2]);
        }
    }
    void direct_update(int k,ll v){
        node[k+N-1] = v;
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
            node[k] = merge(node[2 * k + 1],node[2 * k + 2]);
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
            return merge(vl, vr);
        }
    }
};
template<class Type>
Type solve(Type res = Type()){
    int N; cin >> N;
    vector<ll> C(N); for(auto& in:C) cin >> in;
    
    res = accumulate(C.begin(),C.end(),0LL);
    
    int odd_num = N/2;
    int even_num = N - odd_num;
    
    vector<SegTree> ST{
        SegTree(even_num),
        SegTree(odd_num)
    };
    for(int i = 0; i < N;i++){
        ST[i%2].direct_update(i/2, C[i]);
    }
    ST[0].build(); ST[1].build();
    
    int Q; cin >> Q;
    while(Q--){
        int com; cin >> com;
        if(com == 1){
            int x,a; cin >> x >> a;
            x--;
            if(ST[x%2].query(x/2,x/2+1) >= a){
                ST[x%2].update(x/2,x/2+1,-a);
            }
        }else if(com == 2){
            int a; cin >> a;
            
            if(ST[0].query(0,even_num) >= a){
                ST[0].update(0,even_num,-a);
            }
        }else{
            int a; cin >> a;
            if(min(ST[0].query(0,even_num),ST[1].query(0,odd_num))>=a){
                ST[0].update(0,even_num,-a);
                ST[1].update(0,odd_num,-a);
            }
        }
    }
    for(int i = 0; i < even_num;i++){
        res -= ST[0].query(i,i+1);
    }
    for(int i = 0; i < odd_num;i++){
        res -= ST[1].query(i,i+1);
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
