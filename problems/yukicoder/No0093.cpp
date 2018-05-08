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
 <url:https://yukicoder.me/problems/no/93>
 問題文============================================================
 
 直樹くんは N×N マスの将棋盤と N 個の「飛馬」という不思議な駒を持っています。
 「飛馬」とは飛車と桂馬の動きを併せ持つ駒です。
 
 ある日駒を適当に並べていると、「互いに取られないような N 個の飛馬の配置」があることを発見しました。
 あなたは、この条件を満たす駒の配置のパターン数を 10^9+7 で割った余りを求めるプログラムを書いて下さい。
 ただしそれぞれの駒は区別できず、またすべて上を向いているとしてください。
 =================================================================
 解説=============================================================
 
 解説読んだ
 
 いや、むずいし、無理っしょ解ける気がしない
 ================================================================
 */

#define MAX_N 1005
const ll MOD = 1e9+7;
void add(ll& a,ll b){ (a+=b)%=MOD;}
ll dp[MAX_N][MAX_N][2][2]; // n, ng, (n-3,n-1), (n-2,n)
ll solve(){
    ll res = 0;
    ll N; cin >> N;
    if(N <= 2){
        return res = N;
    }
    dp[2][0][0][0] = 2;
    for(int n = 1; n < N;n++){
        for(int ng = 0; ng < n; ng++){
            // (n-3,n-1)(n-2,n)
            ll v = dp[n][ng][1][1];
            if(v){
                add(dp[n+1][ng-1][0][0],v);
                add(dp[n+1][ng][1][1],v);
                add(dp[n+1][ng+1][1][1],v);
                add(dp[n+1][ng-1][1][0],v*(ng-2));
                add(dp[n+1][ng][1][0],v*((n+1)-(ng+1)));
            }
            // (n-3, n-1)
            v = dp[n][ng][1][0];
            if (v) {
                add(dp[n+1][ng][0][1], v);
                add(dp[n+1][ng+1][0][1], v);
                add(dp[n+1][ng-1][0][0], v*(ng-1));
                add(dp[n+1][ng][0][0], v*((n+1)-(ng+1)));
            }
            // (n-2, n)
            v = dp[n][ng][0][1];
            if (v) {
                add(dp[n+1][ng-1][0][0], v);
                add(dp[n+1][ng+1][1][1], 2*v);
                add(dp[n+1][ng-1][1][0], v*(ng-1));
                add(dp[n+1][ng][1][0], v*((n+1)-(ng+2)));
            }
            // none
            v = dp[n][ng][0][0];
            if (v) {
                add(dp[n+1][ng+1][0][1], 2*v);
                if (ng > 0) add(dp[n+1][ng-1][0][0], v*ng);
                add(dp[n+1][ng][0][0], v*((n+1)-(ng+2)));
            }
        }
    }
    res = dp[N][0][0][0];
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
