#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
 <url:https://www.ioi-jp.org/joi/2009/2010-ho-prob_and_sol/2010-ho.pdf>
 問題文============================================================
 長さN(even)の棒がある。
 ここで、この棒を複数本に切断して、合計N/2になるように２集合に分けたい。
 棒の各点(1ミリずつ)で切断にかかる時間tiが決まっている時、２集合に分けるための最小値を求める
 
 2<=N<=10000 , 1<=ti<=10000
 =================================================================
 解説=============================================================

 難しい
 
 2集合をA,Bと分けると
 dp[N][Aの個数][AorB] := 最小値
 でdpする
 
 dp[i+1][Aの個数+1][A] = min(dp[i][Aの個数][A],dp[i][Aの個数][B] + 時間);
 dp[i+1][Aの個数][B] = min(dp[i][Aの個数][A]+時間,dp[i][Aの個数][B]);
 
 ================================================================
 */

ll dp[2][5005][2];
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<int> B(N);
    for(int i = 0; i < N-1;i++) cin >> B[i];
    for(int i = 0; i < 2;i++)for(int j = 0;j < N/2;j++)for(int k = 0;k < 2;k++)dp[i][j][k] =LINF;
    dp[0][0][0] = 0;
    for(int i = 0; i < N;i++){
        for(int j = 0; j < N/2;j++){
            dp[(i+1)%2][j+1][0] = min(dp[i%2][j][0],dp[i%2][j][1] + B[i]);
            dp[(i+1)%2][j][1] = min(dp[i%2][j][0]+B[i],dp[i%2][j][1]);
        }
        for(int j = 0; j < N/2;j++)dp[i%2][j][0] = dp[i%2][j][1] = LINF;
    }
    cout << dp[N%2][N/2][0] << endl;
    return 0;
}
