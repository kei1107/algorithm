#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://abc073.contest.atcoder.jp/tasks/abc073_d>
問題文============================================================
 Atcoder国には N 個の町があり、M 本の双方向に移動可能な道で結ばれています。
 
 また、 i 本目の道は町 Ai と町 Bi の間を距離 Ci で結んでいます。
 
 joisinoお姉ちゃんは、この国の R 個の町 r1,r2..rR を訪れることとなりました。
 
 最初に訪れる町までの移動と、最後に訪れる町からの移動は空路で行うが、それ以外は道を使わなければなりません。
 
 町を訪れる順番を、道での移動距離が最小となるように決めた時の移動距離を答えてください。
 
=================================================================

解説=============================================================
 
 先にワーシャルフロイドで目的地間の最短距離を調べておけば、
 この問題は実質、頂点数高々８個の全頂点巡回問題となる。
 また、始点、終点は任意でいいので
 
 dp[i][j] := 現在値が i個目の目的地 の時、 j(集合）の目的地に到達済みの時の最小距離
 
 でもとまる。（制約が小さいので、最初の始点を決めての貪欲でも間に合う）
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N,M,R; cin >> N >> M >> R;
    vector<ll> r(R); for(auto &in:r){ cin >> in; in--; }
    vector<vector<ll>> G(N,vector<ll>(N,INF));
    for(int i = 0; i < N;i++) G[i][i] = 0;
    for(int i = 0; i < M;i++){
        ll A,B,C; cin >> A >> B >> C;
        A--; B--;
        G[A][B] = G[B][A] = min(G[A][B],C);
    }
    for(int i = 0; i < N;i++) for(int j = 0; j < N;j++) for(int k = 0; k < N;k++)
        G[j][k] = min(G[j][i] + G[i][k],G[j][k]);
    
    vector<vector<ll>> dp(R,vector<ll>(1<<R,LINF));
    for(int i = 0 ; i < R;i++) dp[i][1<<i] = 0;
    for(int j = 0; j < (1<<R);j++){
        for(int i = 0; i < R;i++){
            if(dp[i][j] == LINF) continue;
            for(int k = 0; k < R; k++){
                if((j>>k)&1) continue;
                dp[k][j|(1<<k)] = min(dp[k][j|(1<<k)],dp[i][j] + G[r[i]][r[k]]);
            }
        }
    }
    ll ans = LINF;
    for(int i = 0; i < R;i++) ans = min(ans,dp[i][(1<<R)-1]);
    cout << ans << endl;
	return 0;
}
