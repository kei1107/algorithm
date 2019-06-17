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
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }


// Ver 1
vector<int> solution(int N, vector<int> &A) {
    vector<int> res(N);
    int maxcounter = 0;
    int maxval = 0;
    for(auto a:A){
        if(a == N+1) maxcounter = maxval;
        else{
            if(res[a-1] < maxcounter) res[a-1] = maxcounter + 1;
            else res[a-1]+=1;
            
            maxval = max(maxval,res[a-1]);
        }
    }
    for(auto& r:res) r = max(r,maxcounter);
    return res;
}


// ========= //
// Ver 2

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

vector<int> solution(int N, vector<int> &A) {
    SegTree ST(N);
    for(auto a:A){
        if(a==N+1){
            ST.update(0,N,(int)ST.query(0,N));
        }else{
            ST.update(a-1,a,(int)ST.query(a-1,a)+1);
        }
    }
    vector<int> res(N);
    for(int i = 0; i < N;i++){
        res[i] = (int)ST.query(i,i+1);
    }
    return res;
}
