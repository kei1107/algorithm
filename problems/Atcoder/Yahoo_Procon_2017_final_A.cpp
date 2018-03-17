#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
 <url: https://yahoo-procon2017-final-open.contest.atcoder.jp/tasks/yahoo_procon2017_final_a
>
問題文============================================================
 高橋君は，文字列 S を持っています．高橋君は yahoo という文字列が好きなので，
 S を編集することで yahoo の繰り返しで得られる文字列に変えようとしています．
 ここで，yahoo の繰り返しで得られる文字列とは，yahoo を 0 個以上つなげてできる文字列です．
 これらは，短いほうから順に (空文字列)，yahoo，yahooyahoo，… となります．
 
 高橋君は 1 回の操作で次のうちいずれかを行うことができます．
 
 S の任意の 1 文字を選んで，それを任意の英小文字に書き換える．
 S の任意の 1 文字を選んで，その文字を S から取り除く．
 S の任意の位置に，任意の英小文字を挿入する．
 
 高橋君が S を yahoo の繰り返しで得られる文字列にするために，必要な操作の回数の最小値を求めてください．
=================================================================

解説=============================================================

 編集距離の亜種
 
 対象文字がループするので、 dp[i][j] := 基準文字i文字目を見ている時　対象文字(yahoo)の先頭からj文字目を見た距離
 で計算し、かつ、遷移がループした時の対策として２週分行って置く
 
================================================================
*/
void solve(){
    string S; cin >> S;
    vector<vector<ll>> dp(S.length()+1,vector<ll>(5,INF));
    string yahoo = "yahoo";
    
    dp[0][0] = 0;
    for(int i = 0; i < (int)S.length();i++){
        for(int j = 0; j < (int)11;j++){
            dp[i+1][(j+1)%5] = min({
                dp[i+1][j%5] + 1,
                dp[i][(j+1)%5] + 1,
                dp[i][j%5] + (S[i] != yahoo[j%5])
            });
        }
    }
    cout << dp[S.length()][0] << endl;
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    solve();
	return 0;
}
