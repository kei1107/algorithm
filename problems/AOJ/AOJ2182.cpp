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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2182>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */

ll solve(string& S){
    for(auto& c:S) c -= '0';
    ll res = 0;
    vector<vector<ll>> dp(S.length()+1,vector<ll>(11,0));
    if(S[0]!=0)dp[0][S[0]] = 1;
    
    for(int i = 1; i < S.length();i++){
        for(int j = 0; j < 11; j++){
            dp[i][(j*10+S[i])%11] += dp[i-1][j];
        }
        if(S[i]!=0) dp[i][S[i]]++;
    }
    for(int i = 0;i < S.length();i++){
        res += dp[i][0];
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    string S;
    while(true){
        cin >> S;
        if(S == "0") break;
        cout << solve(S) << endl;
    }
    return 0;
}
