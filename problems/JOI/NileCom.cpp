#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
 <url:https://www.ioi-jp.org/camp/2008/2008-sp-tasks/2008-sp_tr-day2_21.pdf>
 問題文============================================================
 
 D日間のN店舗の価格情報が与えられる。ここで、同じ店舗で２日連続で購入すると
 1割引、３日連続で購入すると3割引、それ以降は継続して3割引になる。
 
 D日間に支払う合計金額の最小値を求めよ
 
 =================================================================
 解説=============================================================
 
 dp[i][j][k] := i日目にj店舗の店をk回連続で買い物をしている時の最小値
 
 ================================================================
 */

ll N,D;
ll P[366][3001];
ll dp[366][3001][3];
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> N >> D;
    
    for(int i = 0; i < D;i++){
        for(int j = 0; j < N;j++){
            cin >> P[i][j];
        }
    }
    
    for(int i = 0; i < 366;i++)for(int j = 0; j < 3001;j++)for(int k = 0; k < 3;k++) dp[i][j][k] = INF;
    
    for(int i = 0; i < N;i++){
        dp[1][i][0] = P[0][i];
    }
    for(int d = 1; d < D;d++){
        ll tmp = INF;
        for(int n = 0; n < N;n++){
            tmp = min({
                tmp,
                dp[d][n][0],
                dp[d][n][1],
                dp[d][n][2]
            });
        }
        
        for(int n = 0; n < N;n++){
            dp[d+1][n][0] = tmp + P[d][n];
            dp[d+1][n][1] = dp[d][n][0] + (P[d][n] * 9)/10;
            dp[d+1][n][2] = min(dp[d][n][1],dp[d][n][2]) + (P[d][n]*7)/10;
        }
    }
    
    ll res = LINF;
    for(int i = 0; i < N;i++){
        res = min({
            res,
            dp[D][i][0],
            dp[D][i][1],
            dp[D][i][2]
        });
    }
    cout << res << endl;
    return 0;
}
