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
 <url:https://atcoder.jp/contests/dp/tasks/dp_c>
 問題文============================================================
 =================================================================
 解説=============================================================
 dp[i][j] := i日目で、前日の生活がjの場合の最大値
 ================================================================
 */


template<class Type>
Type solve(Type res = Type()){
    int N; cin >> N;
    vector<vector<ll>> abc(N,vector<ll>(3));
    for(int i = 0; i < N;i++) for(int j = 0; j < 3;j++) cin >> abc[i][j];
    
    vector<vector<ll>> dp(2,vector<ll>(3,0));
    int cur = 0,next = 1;
    for(int i = 0; i < N;i++){
        for(int j = 0; j < 3;j++){
            for(int k = 0; k < 3;k++){
                if(j==k) continue;
                dp[next][k] = max(dp[next][k],dp[cur][j]+abc[i][k]);
            }
            dp[cur][j] = 0;
        }
        swap(cur,next);
    }
    res = *max_element(dp[cur].begin(), dp[cur].end());
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
