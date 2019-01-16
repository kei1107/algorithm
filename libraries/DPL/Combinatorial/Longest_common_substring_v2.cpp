#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

/*
 <url:https://atcoder.jp/contests/dp/tasks/dp_f>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 ================================================================
 */

// 互いの文字列で順序が一致する最大の部分列を取得
template<class Type>
Type solve(Type res = Type()){
    string s,t; cin >> s >> t;
    vector<vector<int>> dp(s.length()+1,vector<int>(t.length()+1));
    for(int i = 1; i <= s.length();i++){
        for(int j = 1; j <= t.length();j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    int nows = (int)s.length(),nowt = (int)t.length();
    while(nows!=0 && nowt !=0){
        if(s[nows-1]==t[nowt-1]){
            res += s[nows-1];
            nows--;
            nowt--;
        }else{
            if(dp[nows][nowt-1] > dp[nows-1][nowt]){
                nowt--;
            }else{
                nows--;
            }
        }
    }
    reverse(res.begin(),res.end());
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<string>() << endl;
    return 0;
}
