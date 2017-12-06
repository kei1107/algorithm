#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll R,C; cin >> R >> C;
    vector<string> S(R);
    for(auto& in:S) cin >> in;
    vector<int> bitcnt(1<<C);
    for(int i = 0; i < (1<<C);i++){
        bitcnt[i] = __builtin_popcount(i);
    }
    vector<vector<int>> dp(2,vector<int>(1<<C,-1));
    int cur = 0, next = 1;
    dp[cur][0] = 0;
    for(int i = 0; i < R;i++){
        for(int j = 0; j < C;j++){
            for(int k = 0; k < (1<<C);k++) dp[next][k] = -1;
            for(int k = 0; k < (1<<C);k++){
                if(dp[cur][k] == -1) continue;
                int cur_cnt = bitcnt[k&(1<<j) - 1];
                if(cur_cnt < S[i].length()){
                    int tmp = dp[cur][k];
                    if(cur_cnt > 0 && (k & 1<<(j-1))){
                        if(S[i][cur_cnt-1] == S[i][cur_cnt]) tmp++;
                    }
                    if(i > 0 && (k & (1<<j))){
                        if(S[i][cur_cnt] == S[i-1][S[i-1].length() - bitcnt[k >> j]]) tmp++;
                    }
                    dp[next][k|1<<j] = max(dp[next][k|1<<j],tmp);
                }
                if(C - j > S[i].length() - cur_cnt){
                    dp[next][k & ~(1<<j)] = max(dp[next][k & ~(1<<j)],dp[cur][k]);
                }
            }
            cur = (cur == 0)? 1:0;
            next = (next == 0)?1:0;
        }
    }
    cout <<2 * (*max_element(dp[cur].begin(), dp[cur].end())) << endl;
    return 0;
}
