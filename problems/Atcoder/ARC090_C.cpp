#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://arc090.contest.atcoder.jp/tasks/arc090_a>
問題文============================================================
 2×N のマス目があります。上から i 行目、左から j 列目 (1≤i≤2, 1≤j≤N) のマスをマス (i,j) と表すことにします。
 
 あなたははじめ、左上のマス (1,1) にいます。
 あなたは、右方向または下方向への移動を繰り返し、右下のマス (2,N) に移動しようとしています。
 
 マス (i,j) には Ai,j 個のアメが置かれています。
 あなたは移動中に通ったマスに置いてあるアメをすべて回収します。
 左上および右下のマスにもアメが置かれており、あなたはこれらのマスに置かれているアメも回収します。
 
 移動方法をうまく選んだとき、最大で何個のアメを回収できるでしょうか。
=================================================================

解説=============================================================
 dp[i][j] := マス(i,j)に到達した時点で持っている（(i,j)のあめは未回収）あめの数
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N; cin >> N;
    vector<vector<ll>> A(2,vector<ll>(N));
    for(int i = 0; i < 2;i++)for(int j = 0; j < N;j++) cin >> A[i][j];
    vector<vector<ll>> dp(3,vector<ll>(N+1,0));
    for(int i = 0; i < 2;i++){
        for(int j = 0; j < N;j++){
            dp[i+1][j] = max(dp[i+1][j],dp[i][j]+A[i][j]);
            dp[i][j+1] = max(dp[i][j+1],dp[i][j]+A[i][j]);
        }
    }
    cout << dp[1][N-1] + A[1][N-1] << endl;
	return 0;
}
