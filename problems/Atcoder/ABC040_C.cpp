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
 <url:https://abc040.contest.atcoder.jp/tasks/abc040_c>
 問題文============================================================
 N 本の木の柱が左から右へ一列に並んだアスレチックがあります。左から i 本目の柱の高さは ai センチメートルです。
 
 高橋君は左から 1 本目の柱からスタートし、右へ柱を渡っていき N 本目の柱まで行こうとしています。
 
 高橋君がある柱にいるとき、次には現在の柱から 1 個もしくは 2 個右にある柱のどちらかへ移動することができます。
 
 移動するときには、現在いる柱の高さと、移動後の柱の高さの差の絶対値のぶんだけコストがかかります。
 
 N 本目の柱まで行くとき、コストの合計の最小値はいくらになるでしょうか。
 =================================================================
 解説=============================================================
 
 dpだね
 
 
 dp[i] := i番目の柱に到達する際の最小コスト
 
 でO(N)
 ================================================================
 */

ll solve(){
    ll res = 0;
    ll N; cin >> N;
    vector<ll> a(N);
    for(auto& in:a) cin >> in;
    vector<ll> dp(N+5,LINF);
    dp[0] = 0;
    for(int i = 0; i < N;i++){
        dp[i+1] = min(dp[i+1],dp[i]+abs(a[i+1]-a[i]));
        dp[i+2] = min(dp[i+2],dp[i]+abs(a[i+2]-a[i]));
    }
    return res = dp[N-1];
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
