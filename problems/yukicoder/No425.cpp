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
 <url:https://yukicoder.me/problems/no/425>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 無限回まであいこの場合を考えなければならないが誤差許容範囲が1e-6なので、
 ある程度回数をこなせば十分
 
 よって、dp[i][j]:=i回あいこで、今の確率がjの場合の確率
 でdpを行いつつ勝つ確率を加算していけばいい
 
 ================================================================
 */


double dp[1005][101];
template<class T>
T solve(T res){
    int p,q; cin >> p >> q;
    dp[0][p] = res = 1/3.0;
    for(int i = 0; i <= 1000;i++){
        for(int j = 0; j < 101;j++){
            if(abs(dp[i][j]) < 1e-9) continue;
            res += dp[i][j]*(j/100.0)/2.0;
            dp[i+1][max(j-q,0)] += dp[i][j]*(j/100.0)/2.0;
            
            res += dp[i][j]*(1-j/100.0)/3.0;
            dp[i+1][min(j+q,100)] += dp[i][j]*(1-j/100.0)/3.0;
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15) << solve(0.0) << endl;
    return 0;
}
