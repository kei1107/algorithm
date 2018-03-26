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
 <url:https://onlinejudge.u-aizu.ac.jp/services/room.html#RitsCamp18Day1/problems/G>
 問題文============================================================
 
 株式会社AORは N 階建てのビルである。地下階は存在しない。
 AORイカちゃんはイカであるため、階段を下りることは可能だが、上ることは不可能である。
 
 上の階に登れないと不便なため、M 個のエレベータをビルに設置することにした。
 エレベータを設置するには時間がかかり、i 番目のエレベータは Di 日後の夜に設置が完了し、
 Ai 階以上 Bi 階以下の全ての階を移動可能にする。
 
 あなたはAORイカちゃんに Q 個の質問をされた。
 i 番目の質問は「 Ei 日後の昼に、Si 階から Ti 階に移動可能か？」という質問である。
 移動に使える手段は階段とエレベータのみである。また移動にかかる時間は無視できるものとする。
 
 =================================================================
 
 解説=============================================================
 
 時間順にイベント処理
 
 RAQ_RM(in)Q
 
 エレベータ設置イベント
     [2*A,2*B]へ1加算
 
 query
     S >= T 時
         無条件でYESであり
     S < T の時
         [2*S,2*T]の区間に0が含まれていれば　NO,含まれていなければ YES
 
 ================================================================
 */

/*
 update : [s,t) に xを加算
 query  : [s,t) の　最大(小)値を出力する
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
            node[k] = min(node[2 * k + 1],node[2 * k + 2]);
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
            return min(vl, vr);
        }
    }
};

typedef pair<pll,pair<pll,int>> event; // { {t , 開通 1 : query 0}{{l,r},順番}}

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll N,M,Q; cin >> N >> M >> Q;
    vector<event> e;
    for(int i = 0; i < M;i++){
        ll d,a,b; cin >> d >> a >> b;
        e.push_back({{d,1},{{2*a,2*b},INF}});
    }
    for(int i = 0; i < Q;i++){
        ll d,s,t; cin >> d >> s >> t;
        e.push_back({{d,0},{{2*s,2*t},i}});
    }
    
    sort(e.begin(),e.end());
    SegTree ST(2*N);
    vector<ll> ans(Q,0);
    for(int i = 0; i < e.size();i++){
        ll s,t;
        tie(s,t) = e[i].second.first;
        if(e[i].first.second == 0){
            if(s >= t){
                ans[e[i].second.second] = 1;
            }else{
                ans[e[i].second.second] = ST.query(s-1,t);// getMin(s-1,t);
            }
        }else{
            ST.update(s-1,t,1); //add(s-1,t,1);
        }
    }
    for(auto v:ans){
        if(v == 0){
            cout << "No" << endl;
        }else{
            cout << "Yes" << endl;
        }
    }
    
    return 0;
}
