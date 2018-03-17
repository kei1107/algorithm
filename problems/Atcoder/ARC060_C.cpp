#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://arc060.contest.atcoder.jp/tasks/arc060_a>
問題文============================================================
 高橋君は、N 枚のカードを持っています。 i (1≤i≤N) 番目のカードには、整数 xi が書かれています。
 高橋君は、これらのカードの中から 1 枚以上を選び、
 選んだカードに書かれた整数の平均をちょうど A にしたいと考えています。
 そのようなカードの選び方が何通りあるか求めてください。
=================================================================

解説=============================================================

 dp[i][j][k] := i番目のカードを見る時、それまでに選んがカードがj枚で、合計が k である時の選び方
 でdpすれば良い。
 
 あとはdp結果から選びかたを加算していく
================================================================
*/
ll dp[55][55][50*50+1];
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N,A; cin >>N >> A;
    vector<ll> x(N);
    for(auto& in:x) cin >> in;
    dp[0][0][0] = 1;
    for(int i = 0; i < N;i++){
        for(int j = 0; j <= i; j++){
            for(int k = 0; k <= N*50; k++){
                if(dp[i][j][k] == 0) continue;
                dp[i+1][j][k] += dp[i][j][k];
                dp[i+1][j+1][k+x[i]] += dp[i][j][k];
            }
        }
    }
    ll ans = 0;
    for(int i = 1; i <= N;i++){
        ans += dp[N][i][i*A];
    }
    cout << ans << endl;
	return 0;
}
