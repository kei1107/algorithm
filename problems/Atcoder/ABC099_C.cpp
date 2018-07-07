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
 <url:https://beta.atcoder.jp/contests/abc099/tasks/abc099_c>
 問題文============================================================
 =================================================================
 解説=============================================================
 dp[i] := i円を引き出す時の最小操作回数
 ================================================================
 */
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    ll N; cin >> N;
    vector<ll> dp(N+1,LINF);
    dp[0] = 0;
    for(int i = 0; i < N;i++){
        dp[i+1] = min(dp[i+1],dp[i] + 1);
        ll x = 6;
        while(i+x<=N){
            dp[i+x] = min(dp[i+x],dp[i]+1);
            x *= 6;
        }
        x = 9;
        while(i+x<=N){
            dp[i+x] = min(dp[i+x],dp[i]+1);
            x *= 9;
        }
    }
    cout << dp[N] << endl;
    return 0;
}
