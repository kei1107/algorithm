#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
 <url:https://www.ioi-jp.org/joi/2011/2012-ho-prob_and_sol/2012-ho.pdf>
 問題文============================================================
 N(1<=N<=3000)個の夜店がある。夜店iで遊んだ時に得る楽しさはAi,遊ぶのに必要な時間はBiである。
 また、時刻Sに最も大きな花火が打ち上げられるため、これは見たい。
 夏祭りの始め（時刻０）から終わり（時刻T）までで花火を見てかつ遊ぶ楽しさをできる限り大きくしたい
 なお同じ夜店は2度選ぶことはできず、夜店は番号の小さい順に遊び、かつ２つの夜店で同時に遊べない
 =================================================================
 解説=============================================================
 
 dpだね、ナップサック問題で指定値Sをまたがないように条件を加えれば良い
 
 ================================================================
 */
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll N,T,S; cin >> N >> T >> S;
    vector<ll> A(N),B(N);
    for(int i = 0; i < N;i++) cin >> A[i] >> B[i];
    vector<vector<ll>> dp(N+1,vector<ll>(T+1,0));
    for(int i = 0; i < N;i++){
        for(int j = 0; j <= T;j++){
            dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
            if(j < S && j + B[i] > S)continue;
            if(j + B[i] > T)continue;
            dp[i+1][j+B[i]] = max(dp[i+1][j+B[i]],dp[i][j] + A[i]);
        }
    }
    ll res = 0;
    for(int i = 0; i <=T;i++){
        res = max(res,dp[N][i]);
    }
    cout << res << endl;
    return 0;
}
