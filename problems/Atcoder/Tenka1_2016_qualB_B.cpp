#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
 <url:https://tenka1-2016-qualb.contest.atcoder.jp/tasks/tenka1_2016_qualB_b>
問題文============================================================
 天下一魔力発電所は不思議な魔術で電気を生み出すことができる発電所です。
 
 魔力発電に用いる燃料は以下の様な文字列 S です。
 
 S は ( と ) で構成されており、S の文字数は偶数です。
 
 天下一ワープロでこの文字列を対応の取れた文字列に書き換えることで魔力発電に成功します。
 
 対応が取れた文字列とは、以下の文字列です。
 
 () は対応が取れた文字列である。
 T が対応が取れた文字列であるとき、(T) も対応が取れた文字列である。
 T, U が対応が取れた文字列であるとき、TUも対応が取れた文字列である。
 天下一ワープロには以下 4 通りの操作があります。
 
 はじめはカーソルは S の先頭の文字を指します。
 
 カーソルを右に動かす（カーソルが末尾の文字を指す場合は動かない）
 カーソルを左に動かす（カーソルが先頭の文字を指す場合は動かない）
 カーソルが指す文字が ( のとき、その文字を ) に変更する
 カーソルが指す文字が ) のとき、その文字を ( に変更する

 発電所の責任者であるフデくんは最も少ない操作回数で文字列を対応が取れた文字列に書き換えたいです。
 
 S が与えられるので、対応の取れた文字列に書き換える最も少ない操作回数を求めてください。
=================================================================

解説=============================================================

 dp[i][j][k] := 最後にカーソルを変更した位置i , 文字を変更した回数 j , '('の個数 - ')' k
 
================================================================
*/
string S;
ll dp[110][110][110];
void init(){
    for(int i = 0; i < 110;i++)
        for(int j = 0; j < 110; j++)
            for(int k = 0; k < 110;k++)
                dp[i][j][k] = INF;
}

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    init();
    cin >> S;
    dp[0][0][0] = 0;
    int N = (int)S.length();
    for(int i = 0; i < N;i++){
        for(int j = 0; j < N;j++){
            for(int k = 0; k < N;k++){
                if(S[i] == '('){
                    dp[i+1][j][k+1] = min(dp[i+1][j][k+1],dp[i][j][k]);
                    if(k > 0){
                        dp[i+1][i][k-1] = min(dp[i+1][i][k-1],dp[i][j][k] + 1 + abs(j-i));
                    }
                }else{
                    if(k > 0){
                        dp[i+1][j][k-1] = min(dp[i+1][j][k-1],dp[i][j][k]);
                    }
                    dp[i+1][i][k+1] = min(dp[i+1][i][k+1],dp[i][j][k] + 1 + abs(j-i));
                }
            }
        }
    }
    ll ans = INF;
    for(int i = 0; i <=N;i++) ans = min(ans,dp[N][i][0]);
    cout << ans << endl;
	return 0;
}