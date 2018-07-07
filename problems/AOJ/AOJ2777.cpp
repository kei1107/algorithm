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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2777>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 セグ木を用いることによって効率的に解くことが可能
 
 クエリにおいて数列の前半側には x を 後半側には -x を加算するイメージで
 処理を行えば、きっちりしているか確認する際に、セグ木全体の最大値、最小値が０に
 なっていればきっちりしているとみなすことができる
 
 ================================================================
 */
/* [0..N-1] */
const ll INIT = 0; // 問題に合わせる
struct SegTree {
    int N;
    ll init_v;
    vector<pll> node;
    vector<ll> lazy;
    
    SegTree(int _N):init_v(INIT) {
        N = 1;
        while (N < _N) N *= 2;
        node.resize(2 * N - 1, {init_v,init_v});
        lazy.resize(2 * N - 1, init_v);
    }
    pll merge(pll a, pll b) {
        pll ret = pll(-1e9, 1e9);
        ret.first = max(a.first, b.first);
        ret.second = min(a.second, b.second);
        return ret;
    }
    void lazy_evaluate(int l, int r,int k){
        node[k].first += lazy[k];
        node[k].second += lazy[k];
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
    pll query(int a, int b) { return query(a, b, 0, 0, N); }
    pll query(int a, int b, int k, int l, int r) {
        lazy_evaluate(l, r, k);
        if (r <= a || b <= l) return {-INF,INF};
        if (a <= l && r <= b) {
            return node[k];
        }
        else {
            pll vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
            pll vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
            return merge(vl, vr);
        }
    }
};

void solve() {
    int N; cin >> N;
    vector<ll> kassa(N); for (auto& in : kassa) cin >> in;
    int Q; cin >> Q;
    int  S = N / 2;
    SegTree ST(S);
    for (int i = 0; i < S; i++) {
        ST.update(i, i + 1, kassa[i]);
    }
    for (int i = S; i < N; i++) {
        ST.update(N - i - 1, N - i, -kassa[i]);
    }
    while (Q--) {
        int l, r, x; cin >> l >> r >> x;
        l--; r--;
        if (r < S) {
            ST.update(l, r + 1, x);
        }
        else if (l >= S) {
            ST.update(N - r - 1, N - l, -x);
        }
        else {
            ST.update(l, S, x);
            ST.update(N - r - 1, S, -x);
        }
        pll a = ST.query(0, S);
        if (a.first == a.second && a.first == 0) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
