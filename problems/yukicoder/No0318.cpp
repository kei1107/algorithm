#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

/*
 <url:https://yukicoder.me/problems/no/318>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 セグ木でごり押し
 ================================================================
 */

/*
 update(s,t,x): [s,t) をxに変更する。
 find(s,t): [s,t) の最小値を出力する。
 */

const ll INIT = INT_MAX;
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
vector<ll> solve(){
    vector<ll> res;
    int n; cin >> n;
    vector<int> a(n); for(auto& in:a) cin >> in;
    map<int,pii> mp;
    for(int i = 0; i < n;i++){
        if(mp.count(a[i])){
            pii& p = mp[a[i]];
            p.first = min(p.first,i);
            p.second = max(p.second,i);
        }else{
            mp[a[i]] = {i,i};
        }
    }
    SegTree ST(n);
    for(auto lpll :mp){
        int val = lpll.first;
        int l,r; tie(l,r) = lpll.second;
        ST.update(l, r+1, val);
    }
    res = vector<ll>(n);
    for(int i = 0; i < n;i++){
        res[i] = ST.query(i, i+1);
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
