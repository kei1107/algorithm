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
 <url:https://atcoder.jp/contests/code-festival-2014-relay/tasks/code_festival_relay_g>
 問題文============================================================
 =================================================================
 解説=============================================================
 †DP†
 dp[i] := 音量の合計がiになるか否か
 ================================================================
 */

ll dp[50*10001];
template<class Type>
Type solve(Type res = Type()){
    ll n,m; cin >> n >> m;
    vector<ll> a(n); for(auto& in:a) cin >> in;
    if(accumulate(a.begin(),a.end(),0LL) < m) return -1;
    dp[0] = true;
    for(int i = 0; i < n;i++){
        for(int j = 50*10000; j >= 0; j--){
            if(dp[j]) dp[j+a[i]] = true;
        }
    }
    while(!dp[m]) m++;
    res = m;
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    //solve<ll>();
    cout << fixed << setprecision(12) << solve<ll>() << endl;
    return 0;
}
