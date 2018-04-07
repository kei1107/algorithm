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
 <url:http://codeforces.com/contest/961/problem/B>
 問題文============================================================
 
 ti が 1であれば価値 aiを手に入れられるとする。
 
 n個分の ti と　ai が与えられる
 
 この時、一回だけ連続したk個分だけ必ずtiを1にすることができる時、
 入手できる最大価値はいくつか
 =================================================================
 解説=============================================================
 
 全てのtiが1であるような累積和と、t = 0の時 a = 0とした、累積和の二つを作る、
 
 各区間 [i,i+k-1]について上記二つの累積和からO(1)で価値を得ることができるので
 
 O(N)で溶ける
 ================================================================
 */

ll solve(){
    ll res = 0;
    ll n,k; cin >> n >> k;
    vector<ll> a(n),t(n);
    for(auto& in:a) cin >> in;
    for(auto& in:t) cin >> in;
    
    vector<ll> cusum(n+1,0);
    vector<ll> cusum2(n+1,0);
    for(int i = 0; i < n;i++){
        cusum[i+1] = cusum[i] + (t[i]==1?a[i]:0);
        cusum2[i+1] = cusum2[i] + a[i];
    }
    for(ll i = k; i <= n;i++){
        res = max(res,cusum[i-k]+(cusum[n]-cusum[i])+cusum2[i]-cusum2[i-k]);
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
