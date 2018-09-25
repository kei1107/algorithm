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
 <url:https://beta.atcoder.jp/contests/arc100/tasks/arc100_b>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 QとRの境い目を全探索する。
 
 区切りが決まったら、PとQ、RとSができるだけ近い値になるように選んでやれば良い
 
 ================================================================
 */

ll solve(){
    ll res = LINF;
    ll N; cin >> N;
    vector<ll> A(N); for(auto& in:A) cin >> in;
    vector<ll> cusum(N+1);
    for(int i = 0; i < N;i++) cusum[i+1] = cusum[i] + A[i];
    ll th = 1;
    for(ll m = 2; m <= N - 2;m++){
        ll Lsum = cusum[m], Rsum = cusum[N] - Lsum;
        ll lidx = lower_bound(cusum.begin()+1, cusum.end(), Lsum/2) - cusum.begin();
        ll ridx = lower_bound(cusum.begin()+1, cusum.end(), Lsum+Rsum/2) - cusum.begin();
        for(ll l = max(lidx-th,1LL); l <= min(lidx+th,m-1);l++){
            for(ll r = max(ridx-th,m+1); r <= min(ridx+th,N-1); r++){
                ll P = cusum[l], Q = cusum[m] - cusum[l], R = cusum[r] - cusum[m], S = cusum[N] - cusum[r];
                res = min(res,max({P,Q,R,S}) - min({P,Q,R,S}));
            }
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
