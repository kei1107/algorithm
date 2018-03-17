#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://code-thanks-festival-2017-open.contest.atcoder.jp/tasks/code_thanks_festival_2017_f>
問題文============================================================
 N 個の正の整数が与えられ、i(1≦i≦N) 番目の正の整数は ai です。
 N 個の整数のうち 0 個以上を選んで、選んだ全ての整数のビットごとの排他的論理和を計算します。
 計算結果が K となるような整数の選び方の個数を 109+7 で割った余りを求めてください。
 ただし、0 個選んだときのビットごとの排他的論理和は 0 とします。
 
 1≦N≦10^5
 0≦K≦10^5
 1≦ai(1≦i≦N)
 a1+…+aN≦10^5
 入力は全て整数である。
=================================================================

解説=============================================================

 dp[i][j] := i番目を見た時 xor が j となる総数で dp
 
 このままだと間に合わないので a1+…+aN≦10^5 より
 sort順に見ていけば見なければならない範囲は少ないだろうと判断して　探索範囲に制限を設ける
 
================================================================
*/
const ll MOD = 1e9+7;
ll dp[2][1<<20];
ll solve(){
    ll ret = 0;
    ll N,K; cin >> N >> K;
    vector<ll> a(N);
    for(auto &in:a) cin >> in;
    sort(a.begin(),a.end());
    dp[0][0] = 1;
    ll Lim = 0;
    for(int i = 0; i < N;i++){
        for(int j = 0; j <= Lim; j++){
            (dp[(i+1)%2][j] += dp[i%2][j])%=MOD;
            (dp[(i+1)%2][j^a[i]] += dp[i%2][j])%=MOD;
        }
        Lim |= a[i];
        for(int j = 0; j <= Lim;j++){
            dp[i%2][j] = 0;
        }
    }
    return ret = dp[N%2][K];
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    cout << solve() << endl;
	return 0;
}
