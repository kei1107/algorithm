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
 <url:https://atcoder.jp/contests/dp/tasks/dp_i>
 問題文============================================================
 =================================================================
 解説=============================================================
 dp[i][j] := 表の数がiで裏の数がjの時の確率
 で、 i+jが小さい場合から遷移させていく
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int N; cin >> N;
    vector<double> p(N); for(auto& in:p) cin >> in;
    vector<vector<double>> dp(N+1,vector<double>(N+1));
    dp[0][0] = 1.0;
    for(int n = 0; n < N;n++){
        for(int i = 0; i <= n;i++){
            int j = n-i;
            dp[i+1][j] += dp[i][j]*p[n];
            dp[i][j+1] += dp[i][j]*(1-p[n]);
        }
    }
    
    for(int i = 0; i <= N;i++){
        int j = N-i;
        if(i <= j) continue;
        res += dp[i][j];
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<double>() << endl;
    return 0;
}
