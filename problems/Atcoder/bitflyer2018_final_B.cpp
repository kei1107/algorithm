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
 <url:https://beta.atcoder.jp/contests/bitflyer2018-final-open/tasks/bitflyer2018_final_b>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 問題文を直すと
 
 [0,C-D]はD円
 (C-D,C)となるXは C-X円
 (C,C+D)となるXは X-C円
 [C+D,INF]はD円
 
 となる、
 この境界をにぶたんで求めておき、C-XやX-Cになる部分は累積和を求めておくことでO(1)で求まる
 ================================================================
 */

void solve(){
    ll N,Q; cin >> N >> Q;
    vector<ll> X(N); for(auto& in:X) cin >> in;
    vector<ll> cusum(N+1); for(int i = 0; i < N;i++) cusum[i+1] = cusum[i] + X[i];
    while(Q--){
        ll C,D; cin >> C >> D;
        ll ans = 0;
        auto l = upper_bound(X.begin(),X.end(),C-D) - X.begin();
        ans += D*l;
        
        auto m = upper_bound(X.begin(),X.end(),C) - X.begin();
        ans += (m-l)*C - (cusum[m] - cusum[l]);
        
        auto r = upper_bound(X.begin(),X.end(),C+D) - X.begin();
        ans += (cusum[r] - cusum[m]) - (r-m)*C;
        
        ans += D*(N-r);
        
        cout << ans << endl;
   //     cout << l << " " << X[l] << " " << m << " " << X[m] << endl;
    }
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
