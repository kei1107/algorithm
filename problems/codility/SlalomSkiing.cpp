#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T>& V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> >& Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T>& mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }
template<typename T>vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}

/*
 update(s,t,x): [s,t) をxに変更する。
 find(s,t): [s,t) の最小値を出力する。
 */

const ll INIT = 0;
const ll NIL = LLONG_MAX;
struct SegTree {
    int N;
    ll init_v;
    vector<ll> node, lazy;
    
    SegTree(int _N):init_v(INIT) {
        N = 1;
        while (N < _N) N *= 2;
        node.resize(2 * N - 1, init_v);
        lazy.resize(2 * N - 1, NIL);
    }
    
    ll merge(ll l,ll r){
        return max(l,r);
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
        if (lazy[k] == NIL) return;
        node[k] = lazy[k];
        if (k < N - 1) {
            lazy[2 * k + 1] = lazy[k];
            lazy[2 * k + 2] = lazy[k];
        }
        lazy[k] = NIL;
    }
    
    /* [a,b) 引数の範囲に注意!! s~tまでを更新→update(s,t+1,~) */
    ll update(int a, int b, int x) { return update(a, b, 0, 0, N, x); }
    ll update(int a, int b, int k, int l, int r, int x) {
        if (r <= a || b <= l) {
            lazy_evaluate(k); // nodeの値を見るときは必ず遅延評価を更新する
            return node[k]; // updateでは全体の中の最小を見つける必要があるため, [l,r)外になっても値を参照
        }
        if (a <= l && r <= b) {
            lazy[k] = x;
            lazy_evaluate(k);
            return node[k];
        }
        else {
            lazy_evaluate(k);
            ll vl = update(a, b, 2 * k + 1, l, (l + r) / 2, x);
            ll vr = update(a, b, 2 * k + 2, (l + r) / 2, r, x);
            return node[k] = merge(vl, vr);
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
            return merge(vl, vr);
        }
    }
};
int solution(vector<int> &A){
    int ret = 0;
    auto cA = A;
    sort(cA.begin(),cA.end());
    for(auto& a:A) a = (int)(lower_bound(cA.begin(),cA.end(),a)-cA.begin()) + 1;
    
    int N = (int)A.size();
    int _N = N + 1;
    vector<SegTree> ST(3,SegTree(_N));
    for(auto & a:A){
        for(int j = 0; j < 3;j++){
            if(j%2 == 0){
                ST[j].update(a, a+1, max((int)ST[j].query(a,a+1),(int)ST[j].query(0,a)+1));
                if(j!=0){
                    ST[j].update(a,a+1,max((int)ST[j].query(a,a+1),(int)ST[j-1].query(0,a)+1));
                }
            }else{
                ST[j].update(a, a+1, max((int)ST[j].query(a,a+1),(int)ST[j].query(a+1,_N)+1));
                ST[j].update(a,a+1,max((int)ST[j].query(a,a+1),(int)ST[j-1].query(a+1,_N)+1));
            }
        }
    }
    for(int j = 0; j < 3;j++){
        ret = max(ret,(int)ST[j].query(0,_N));
    }
    return ret;
}
