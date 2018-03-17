#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://arc073.contest.atcoder.jp/tasks/arc073_b>
問題文============================================================
 あなたは N 個の物と、強度 W のバッグを持っています。 i 個目の物は、重さが wi で価値が vi です。
 
 あなたは、物のうちいくつかを選び、バッグに入れます。 ただし、選んだ物の重さの和は W 以下でなくてはいけません。
 
 あなたは、バッグに入れた物の価値の総和を最大化したいです。
 
 制約
 1≦N≦100
 1≦W≦10^9
 1≦wi≦10^9
 すべての i=2,3,…,N について、w1≦wi≦w1+3
 1≦vi≦10^7
 W,wi,vi はすべて整数である

=================================================================

解説=============================================================

 制約で wもvも大きいので他の部分に注目する
  => すべての i=2,3,…,N について、w1≦wi≦w1+3
 
 これによって、w1を基準とすればwiが大きくなる範囲をかなり限定できる
 よって、入れる物全ての総和は　100*(w1+3) = 100*w1 + 300
 ここで、この問題は w1を高々100個　＋　余剰分で重さがさらに高々 300 増えるナップサック問題と捉えることができる
 
 したがって、このようなdpを考えることができる
 
 dp[i][j][k] := i番目の物を見た時、重さが j*w1 + k となっている時の価値の最大
 
 計算量は 100 * 100 * 300 = 3*10^6 で十分間に合う
 
================================================================
*/

ll dp[110][110][330];

void init(){
    for(int i = 0; i < 110; i++) for(int j = 0; j < 110; j++) for(int k = 0; k < 330; k++)
        dp[i][j][k] = -1;
}

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    init();
    ll N,W; cin >> N >> W;
    vector<ll> w(N),v(N);
    for(int i = 0; i < N;i++) cin >> w[i] >> v[i];
    ll base_w = w[0];
    for(int i = 0; i < N;i++) w[i] -= base_w;
    
    dp[0][0][0] = 0;
    for(int i = 0; i < N;i++){
        for(int j = 0; j < 110; j++){
            for(int k = 0; k < 330; k++){
                if(dp[i][j][k] == -1) continue;
                dp[i+1][j][k] = max(dp[i+1][j][k],dp[i][j][k]);
                dp[i+1][j+1][k+w[i]] = max(dp[i+1][j+1][k+w[i]],dp[i][j][k] + v[i]);
            }
        }
    }
    ll ans = 0;
    for(int j = 0; j < 110; j++){
        for(int k = 0; k < 330; k++){
            if(dp[N][j][k] == -1) continue;
            if(base_w*j + k <= W){
                ans = max(ans,dp[N][j][k]);
            }
        }
    }
    cout << ans << endl;
	return 0;
}
