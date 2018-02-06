#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2200>
問題文============================================================
 グラフが与えられて、その最短経路を求める
 各点を移動するときに複数の制約が存在（省略
=================================================================

解説=============================================================
ワーシャルフロイドを行い、dpを行う
 
 dp[i][j] := i番目の配達先にいて、j番に船がおいてある時の答え
 
 とする
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N,M;
    while(cin >> N >> M){
        if(N == 0 && M == 0) break;
        vector<vector<ll>> L(N + 1, vector<ll>(N + 1, INF)), S(N + 1, vector<ll>(N + 1, INF));
        
        for (int i = 0; i < N + 1;i++) L[i][i] = S[i][i] = 0;
        
        for (int i = 0; i < M;i++) {
            ll x, y, t; char sl;
            cin >> x >> y >> t >> sl;
            if (sl == 'L') { L[x][y] = L[y][x] = min(L[x][y],t); }
            else { S[x][y] = S[y][x] = min(S[x][y], t); }
        }
        for (int i = 0; i < N+1;i++)
            for (int j = 0; j < N+1;j++)
                for (int k = 0; k < N + 1;k++) {
                    S[j][k] = min(S[j][k], S[j][i] + S[i][k]);
                    L[j][k] = min(L[j][k], L[j][i] + L[i][k]);
                }
        
        ll R; cin >> R;
        vector<ll> z(R);
        for (int i = 0; i < R; i++) cin >> z[i];
        
        vector<vector<ll>> dp(R, vector<ll>(N+1, INF));
        dp[0][z[0]] = 0;
        for (int i = 1; i < R;i++) {
            for (int j = 1; j < N + 1;j++) {
                if (dp[i - 1][j] == INF)continue;
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + L[z[i - 1]][z[i]]);
                for (int k = 1; k < N + 1;k++) {
                    dp[i][k] = min(dp[i][k], dp[i - 1][j] + L[z[i - 1]][j] + S[j][k] + L[k][z[i]]);
                }
            }
        }
        ll ans = INF;
        for (int i = 1; i < N + 1;i++) ans = min(ans, dp[R - 1][i]);
        cout << ans << endl;
    }
	return 0;
}
