#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
 <url:https://www.ioi-jp.org/camp/2010/2010-sp-tasks/2010-sp-day1_20.pdf>
 問題文============================================================
 あなたは，階段の上り方が何通りあるかを調べたくなった．
 階段は N 段からなり，k(1 <= k <= N) 段目の段差は h_k mm である．
 あなたは，段差の和が P mm 以下の段を一度に上ることができる．
 階段を上るときに，同じ段で足踏みしたり，下ったりはしない．
 また，用いた段が同じ時に同じ上り方とみなす．
 
 階段の上り方の場合の数の 1234567 による余りを求めよ．
 
 =================================================================
 解説=============================================================
 累積和的なdp
 ================================================================
 */
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    const ll MOD = 1234567;
    ll N, P; cin >> N >> P;
    vector<ll> h(N);
    for (auto& in : h) cin >> in;
    
    vector<ll> dp(N + 2, 0);
    dp[0] = 0; dp[1] = 1;
    ll l = 0, r = 0;
    ll Sum = 0;
    for (int i = 0; i < N;i++) {
        while (r <= i) { Sum += h[r]; r++; }
        while (l < r && P < Sum) { Sum -= h[l]; l++; }
        dp[r + 1] = (dp[r] + (dp[r] - dp[l] + MOD) % MOD) % MOD;
    }
    cout << ((dp[N + 1] - dp[N] + MOD) % MOD) << endl;
    return 0;
}
