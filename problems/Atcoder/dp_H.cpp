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
 <url:https://atcoder.jp/contests/dp/tasks/dp_h>
 問題文============================================================
 =================================================================
 解説=============================================================
 典型
 
 組み合わせ数をdpで求めるやり方を応用
 ================================================================
 */

const ll MOD = 1e9+7;
template<class Type>
Type solve(Type res = Type()){
    int H,W; cin >> H >> W;
    vector<vector<char>> a(H,vector<char>(W));
    for(auto& vec:a) for(auto& in:vec) cin >> in;
    vector<vector<ll>> dp(H+1,vector<ll>(W+1));
    dp[0][0] = 1;
    for(int i = 0; i < H;i++){
        for(int j = 0; j < W;j++){
            if(a[i][j]=='#') continue;
            (dp[i+1][j] += dp[i][j])%=MOD;
            (dp[i][j+1] += dp[i][j])%=MOD;
        }
    }
    res = dp[H-1][W-1];
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
