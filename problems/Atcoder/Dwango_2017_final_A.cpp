#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://dwacon2017-honsen.contest.atcoder.jp/tasks/dwango2017final_a>
問題文============================================================
 ニコニコテレビちゃんは、頭の体操として簡単な計算をすることにしました。
 ところでニコニコテレビちゃんは人間ではないので、逆ポーランド記法で計算をします。
 
 具体的には、0 ~ 9, -, + からなる文字列 S について、以下の規則に従い計算をします。
 
 まず、最初の時点では空の、無限に長いスタックを 1 つ持っていると考える。そして、S の文字を前から見ていく。
 もし0 ~ 9が出てきたら、そのままスタックへ積む。
 もし+が出てきたら、スタックから1個取り出し a、もう1個取り出し b とする。そして b+a をスタックへ積む。
 もし-が出てきたら、スタックから1個取り出し a、もう1個取り出し b とする。そして b−a をスタックへ積む。
 最後に、スタックの中身が 1 個ならばそれが答えである
 もし 1 個ではなかったり、途中で取り出そうとしたがスタックが空だったりした場合は S は正しい式ではない。
 ニコニコテレビちゃんは、適当に文字列 S を書きました。
 これに対してただ計算するだけではつまらないので、以下の問題を解くことにしました。
 
 この文字列を K 文字まで書き換えて、正しい式にできるか？
 また、出来るならば正しい式のうち、計算した答えの最大値はいくつか？
 しかしこれは難しすぎたので、あなたが代わりに解いて助けてあげてください。

=================================================================

解説=============================================================

 区間dp苦手
 やってることは所々にコメントとして書いてある
 
================================================================
*/

int N,K;
string S;

// dp[0][..] : 最大  dp[1][..] : 最小
// dp[i][j][k][l] := 閉区間[j,k] を見て 変更回数が k 回残っている
int dp[2][55][55][55];
bool checked[55][55][55];

void rec(int L,int R,int k){
    if(checked[L][R][k]) return;
    checked[L][R][k] = true;
    dp[0][L][R][k] = -INF; dp[1][L][R][k] = INF;
    if(L == R){ // [L,R]
        if(k == 0){ // 変更できないならば、そのまま扱う
            if(isdigit(S[L])){
                dp[0][L][R][k] = max(dp[0][L][R][k],S[L]-'0');
                dp[1][L][R][k] = min(dp[1][L][R][k],S[L]-'0');
            }
        }else { // まだ変更できるならば最適 9 or 0 にした方がいい
            dp[0][L][R][k] = max(dp[0][L][R][k],9);
            dp[1][L][R][k] = min(dp[1][L][R][k],0);
        }
    }
    
    // +
    int tk = k;
    if(S[R] != '+') k--; // S[R]を+にしたい
    for(int M = L; M < R;M++){
        for(int divk = 0; divk <= k;divk++){
            // [L,R] で k 回変更可能を S[R]を + として => [L,M] divk / [M+1][R-1] k-divk に分ける
            rec(L,M,divk); rec(M+1,R-1,k-divk);
            if(dp[0][L][M][divk] != -INF && dp[0][M+1][R-1][k-divk] != -INF){ // 見たい区間が正しく更新済みであれば [L,R] k を更新する
                // + 符号の場合 最大値の更新は 最大値 + 最大値
                dp[0][L][R][tk] = max(dp[0][L][R][tk],
                                     dp[0][L][M][divk] + dp[0][M+1][R-1][k-divk]);
                // + 符号の場合 最小値の更新は 最小値 + 最小値
                dp[1][L][R][tk] = min(dp[1][L][R][tk],
                                     dp[1][L][M][divk] + dp[1][M+1][R-1][k-divk]);
            }
        }
    }
    if(S[R] != '+') k++;
    
    // -
    tk = k;
    if(S[R] != '-') k--; // S[R]を-にしたい
    for(int M = L; M < R;M++){
        for(int divk = 0; divk <= k;divk++){
            // [L,R] で k 回変更可能を S[R]を - として => [L,M] divk / [M+1][R-1] k-divk に分ける
            rec(L,M,divk); rec(M+1,R-1,k-divk);
            if(dp[0][L][M][divk] != -INF && dp[0][M+1][R-1][k-divk] != -INF){ // 見たい区間が正しく更新済みであれば [L,R] k を更新する
                // - 符号の場合 最大値の更新は 最大値 - 最小値
                dp[0][L][R][tk] = max(dp[0][L][R][tk],
                                     dp[0][L][M][divk] - dp[1][M+1][R-1][k-divk]);
                // - 符号の場合 最小値の更新は 最小値 - 最大値
                dp[1][L][R][tk] = min(dp[1][L][R][tk],
                                     dp[1][L][M][divk] - dp[0][M+1][R-1][k-divk]);
            }
        }
    }
    if(S[R] != '-') k++;
}

void solve(){
    cin >> K >> S;
    N = (int)S.length();
    rec(0,N-1,K);
    if(dp[0][0][N-1][K] == -INF){
        cout << "NG" << endl;
    }else{
        cout << "OK" << endl;
        cout << dp[0][0][N-1][K] << endl;
    }
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    solve();
	return 0;
}
