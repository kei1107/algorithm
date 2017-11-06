#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
 <url:https://www.ioi-jp.org/joi/2011/2012-yo-prob_and_sol/2012-yo-t4/2012-yo-t4.html>
 問題文============================================================
 あなたはパスタが大好物であり，毎日，晩御飯にパスタを作って食べている．
 あなたはトマトソース，クリームソース，バジルソースの 3 種類のパスタを作ることができる．
 N 日間の晩御飯の予定を考えることにした．
 それぞれの日に 3 種類のパスタから 1 種類を選ぶ．ただし，同じパスタが続くと飽きてしまうので，
 3 日以上連続して同じパスタを選んではいけない．また，N 日のうちの K 日分のパスタはすでに決めてある．
 入力として N の値と，K 日分のパスタの情報が与えられたとき，
 条件をみたす予定が何通りあるかを 10000 で割った余りを求めるプログラムを作成せよ．
 =================================================================
 解説=============================================================
 
 dpっぽい問題だからdp(dfsでもできそう,制約小さいし))
 
 dp[i][j][k] := i日目にピザjを連続してk個食べている時の総数とする
 
 ================================================================
 */
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll N,K; cin >> N >> K;
    vector<ll> pasta(N+1,-1);
    for(int i = 0; i < K;i++){
        ll A,B; cin >> A >> B;
        A--; B--;
        pasta[A] = B;
    }
    
    vector<vector<vector<ll>>> dp(N+1,vector<vector<ll>>(3,vector<ll>(2,0)));
    
    if(pasta[0] == -1){
         dp[0][0][0] = dp[0][1][0] = dp[0][2][0] = 1;
    }else{
        dp[0][pasta[0]][0] = 1;
    }
    for(int i = 0;i < N-1;i++){
        for(int j = 0; j < 3;j++){
            for(int k = 0; k < 2;k++){
                if(dp[i][j][k] == 0)continue;
                if(pasta[i+1] == -1){
                    for(int l = 0; l < 3;l++){
                        if(l == j && k == 1)continue;
                        (dp[i+1][l][(l == j)?(k+1):0] += dp[i][j][k])%=10000;
                    }
                }else{
                    if(pasta[i+1] == j && k == 1)continue;
                    (dp[i+1][pasta[i+1]][(pasta[i+1]==j)?(k+1):0] += dp[i][j][k])%=10000;
                }
            }
        }
    }
    ll res = 0;
    for(int j = 0;j < 3;j++){
        for(int k = 0; k < 2;k++){
            (res += dp[N-1][j][k])%=10000;
        }
    }
    cout << res << endl;
    return 0;
}
