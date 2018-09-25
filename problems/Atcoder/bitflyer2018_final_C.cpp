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
 <url:https://beta.atcoder.jp/contests/bitflyer2018-final-open/tasks/bitflyer2018_final_c>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 対応が文字列とは
 
 ・'('と')'が同じ回数登場する
 ・文字列の途中までを見たとき'('の登場する回数が')'の登場する回数以上
 
 の２条件を満たすこと
 [0,i]の文字列の上記対応は累積和の要領で求めることができる
 この累積和をpとすれば
 
 p[i] = p[j] (i < j)
 となるi,jに対して p[k] >= p[i] (i < k <=j)となっていれば良い
 
 よってこれは p[i]の値と関してSeg木を用いることで解ける
 ================================================================
 */

/*
 update : k を x に変更
 query : [s,t) の最小(大)を出力する
 */
const ll INIT = INT_MAX;
struct SegTree {
    int N;
    ll init_v;
    vector<ll> node;
    
    SegTree(int _N):init_v(INIT) {
        N = 1;
        while (N < _N) N *= 2;
        node.resize(2 * N - 1, init_v);
    }
    
    ll merge(ll l,ll r){
        return min(l,r);
    }
    void update(int k, ll val) {
        k += N - 1;
        node[k] = val;
        while (k) {
            k = (k - 1) / 2;
            node[k] = merge(node[2 * k + 1], node[2 * k + 2]);
        }
    }
    ll query(int a,int b){ return query(a,b,0,0,N);}
    ll query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return init_v;
        if (a <= l && r <= b) return node[k];
        else {
            ll vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
            ll vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
            return merge(vl, vr);
        }
    }
};

#define MAXL 100010
vector<int> G[MAXL];
ll solve(){
    ll res = 0;
    string S; cin >> S;
    
    // prepare
    vector<ll> p(S.length()+1);
    for(int i = 0; i < S.length();i++){
        p[i+1] = p[i];
        if(S[i] == '(') p[i+1]++;
        if(S[i] == ')') p[i+1]--;
    }
    
    // p[i] >= 0とする
    ll minv = *min_element(p.begin(), p.end());
    for(int i = 0; i <= S.length();i++)p[i] -= minv;
    
    SegTree ST((int)S.length()+1);
    for(int i = 0; i <= S.length();i++) ST.update(i, p[i]);
    for(int i = 0; i <= S.length();i++) G[p[i]].push_back(i);
    for(int i = 0; i < MAXL;i++) sort(G[i].begin(),G[i].end());
    
    // solver
    for(int i = 0; i < MAXL;i++){
        ll l = 0,r = 0;
        for(;r < G[i].size(); r++){
            if(i > ST.query(G[i][l],G[i][r]+1)){
                res += (r-l)*(r-l-1)/2;
                l = r;
            }
        }
        res += (r-l)*(r-l-1)/2;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
