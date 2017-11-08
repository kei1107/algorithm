#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2595>
 問題文============================================================
 D日でN個のクッキーを食べる時のその食べ方の総数を求める。
 ただし、一日に食べる枚数はX枚未満でなければならない
 =================================================================
 解説=============================================================
 dp[i][j] := i日でj枚食べる場合の数
 として計算したのち、
 dp[i][N] * dCi (i .. N) の総和が答え
 ================================================================
 */

const ll MOD = 1e9+7;
ll powmod(ll a,ll b) {ll res=1;a%=MOD; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
vector<ll> inv(2001,0);
void init_inv(){
    inv[0] = inv[1] = 1;
    for(int i = 2; i <= 2000;i++){
        inv[i] = powmod(i,MOD-2)%MOD;
    }
}

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    init_inv();
    ll N,D,X;
    vector<vector<ll>> dp;
    while(cin >> N >> D >> X){
        if(N == 0 && D == 0 && X == 0)break;
        dp.assign(N+1,vector<ll>(N+1,0));
        dp[0][0] = 1;
        for(int i = 0; i < N;i++){
            for(int j = i; j < N;j++){
                dp[i+1][j+1] = (dp[i+1][j] + dp[i][j])%MOD;
                if(j + 1 >= X){
                    dp[i+1][j+1] = (dp[i+1][j+1] - dp[i][j - X + 1] + MOD)%MOD;
                }
            }
        }
        
        ll res = 0;
        for(int i = 1; i <= min(N,D);i++){
            ll T = dp[i][N];
            for(int j = 0; j < i;j++){
                (T = (D - j)%MOD * T%MOD)%=MOD;
                (T = T*inv[i-j])%=MOD;
            }
            (res+=T)%=MOD;
        }
        cout << res << endl;
    }
    return 0;
}
