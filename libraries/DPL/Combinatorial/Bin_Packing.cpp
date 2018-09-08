/*
 ビンパッキング問題
 与えられた「荷物（重さや個数がついている）」をつめる「箱（ビンやコンテナなど）」の最小数を見つけるものである
 
 荷物の数 N
 容量 T
 荷物の大きさ t[i]
 dp[i][j] := 問題の集合iをj人で解けるだけ解いたとき、解かれずに残った問題の容量の合計の最小値
 O(N^2 2^N)
 
 ================================================================
 */

ll solve(){
    ll res = 0;
    ll T,N; cin >> T >> N;
    vector<ll> t(N); for(auto& in:t) cin >> in;

    vector<vector<ll>> dp(1<<N,vector<ll>(N+1,INF));
    for(int j = 0; j <= N;j++) dp[0][j] = 0;
    
    for(int i = 1; i < (1<<N);i++){
        for(int j = 0; j < N;j++){
            if(!((i>>j)&1)) continue;
            for(int k = 0; k < N;k++){
                dp[i][k] = min(dp[i][k],dp[i^(1<<j)][k]+t[j]);
                if(dp[i][k] <= T) dp[i][k+1] = 0;
            }
        }
    }
    
    for(int i = 0; i <= N;i++){
        if(!dp[(1<<N)-1][i]){
            res = i;
            break;
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
