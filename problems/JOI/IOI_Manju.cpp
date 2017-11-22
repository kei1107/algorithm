#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
 <url:https://joi2014ho.contest.atcoder.jp/img/other/joi2014ho/joi2014ho2.pdf>
 問題文============================================================
 
 Incredible Okashi Inc. は「途方もなくおいしいお菓子(incredible okashi)」を製作している会社である．
 ここでは略してIOI 社と呼ぶ．IOI 社は特製のIOI 饅頭を作ったので，それを販売することになった．
 IOI 社はMM 種類の饅頭を1 個ずつ作った．作られたMM 個の饅頭はすべて同じ大きさであるが，
 ひとつひとつ異なる味なので価格は様々であり，i 番目(1≤i≤M)(1≤i≤M) の饅頭の価格はPi 円である．
 
 ところで，あなたはJust Odd Inventions 社を知っているだろうか？
 この会社の業務は「ただ奇妙な発明(just odd inventions)」をすることである．ここでは略してJOI 社と呼ぶ．
 IOI 社は，饅頭を詰めるための高級な箱をJOI 社に発注することになった．
 JOI 社の製作する饅頭用の箱はNN 種類あり，
 j 番目(1≤j≤N)(1≤j≤N)の箱は最大でCj 個の饅頭を詰められる大きさであり，販売価格はEjEj 円である．
 これらのNN 種類の箱のうちの何種類か(0 種類以上NN 種類以下) を1 個ずつ発注し，
 饅頭をそれらの箱に詰め分けてセットで販売することになった．
 各饅頭セットの価格は，それに含まれる饅頭の価格の合計である．
 
 すべての饅頭セットが売れるとした場合，IOI 社が得ることができる利益の最大値はいくらだろうか．
 ここで利益とは，販売した饅頭セットの価格の合計から，発注した箱の価格の合計を引いた値である．
 なお，箱に詰めなかった饅頭については，IOI 社のスタッフがおいしくいただくため，利益には影響しないものとする．
 
 
 各饅頭の価格と，各箱の大きさと価格が与えられたとき，
 IOI 社が得ることができる利益の最大値を求めるプログラムを作成せよ．
 
 =================================================================
 解説=============================================================
 
 むつかしい
 
 dp[i][j] := i番目の箱まで見たとき、j個の饅頭が入る時の最小の箱の総価格
 を求め、
 降順に並べられた饅頭の価格の合計との差をとった時の最大
 ================================================================
 */
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll M,N; cin >> M >> N;
    vector<ll> P(M);
    vector<ll> C(N),E(N);
    
    for(int i = 0; i < M;i++)cin >> P[i];
    for(int j = 0; j < N;j++)cin >> C[j] >> E[j];
    
    sort(P.begin(),P.end());
    reverse(P.begin(),P.end());
    
    vector<vector<ll>> dp(N+1,vector<ll>(M+1,LINF));
    dp[0][0] = 0; dp[1][0] = 0;
    for(int j = 1; j <= min(M,C[0]);j++) dp[1][j] = E[0];
    for(int i = 1; i < N;i++){
        for(int j = 0; j <= M;j++){
            dp[i+1][j] = min(dp[i+1][j],dp[i][j]);
            dp[i+1][min(M,j+C[i])] = min(dp[i+1][min(M,j+C[i])],dp[i][j] + E[i]);
        }
    }
    
    ll res = 0;
    vector<ll> cusum(M+1,0);
    for(int i = 0; i < M;i++)cusum[i+1] = cusum[i] + P[i];

    for(int i = 0; i <=M;i++){
        res = max(res,cusum[i] - dp[N][i]);
    }
    cout << res << endl;
    return 0;
}
