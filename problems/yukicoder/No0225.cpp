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
 <url:https://yukicoder.me/problems/no/225>
 問題文============================================================
 =================================================================
 解説=============================================================
 レーベンシュタイン距離求めるだけ
 ================================================================
 */
ll solve(){
    ll res = 0;
    ll n,m; cin >> n >> m;
    string S,T; cin >> S >> T;
    vector<vector<ll>> dp(n+1,vector<ll>(m+1,INF));
    dp[0][0] = 0;
    for (int i = 1; i <= S.length();i++) dp[i][0] = i;
    for (int j = 1; j <= T.length(); j++) dp[0][j] = j;
    
    for (int i = 1; i <= S.length(); i++) {
        for (int j = 1; j <= T.length(); j++) {
            dp[i][j] = min({
                dp[i][j - 1] + 1,
                dp[i - 1][j] + 1,
                dp[i - 1][j - 1] + (S[i - 1] != T[j - 1])
            });
        }
    }
    res = dp[n][m];
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
