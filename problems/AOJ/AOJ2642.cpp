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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2642>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 <reference : http://okuraofvegetable.hatenablog.com/entry/2017/09/17/000945>
 
 ================================================================
 */

ll solve(){
    ll res = -LINF;
    ll N,P,Q; cin >> N >> P >> Q;
    vector<ll> C(N); for(auto& in:C) cin >> in;
    ll S = accumulate(C.begin(),C.end(),0LL);
    vector<ll> F(N);
    for(ll a = 0; a < N;a++){
        F[a] = P*a + C[a];
    }
    sort(F.begin(),F.end());
    for(int i = 0; i < N-1;i++) F[i+1] += F[i];
    res = S;
    for(ll k = 1; k <= N;k++){
        res = max(res,S+k*P*Q+P*k*(k-1)-F[k-1]);
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
