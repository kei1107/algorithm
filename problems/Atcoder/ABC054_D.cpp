#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://abc054.contest.atcoder.jp/tasks/abc054_d>
問題文============================================================
 イルカは、微量の物質Cを生成したいと考えています。
 物質Cを生成するためには、タイプAの物質とタイプBの物質の混合比が Ma:Mb となる溶液を用意する必要があります。
 しかし、イルカは薬品を1つも持っていないため、薬局へ薬品を買いに行くことにしました。
 薬局では、N 種類の薬品を取り扱っており、各薬品 i の在庫はちょうど1つです。
 各薬品 i は、タイプAの物質 ai グラム、タイプBの物質 bi グラム含んでおり、価格 ci 円で売られています。
 イルカは、いくつかの薬品を薬局で買います。買った薬品は全て使わなければなりません。
 物質Cを生成するために、必要な最小予算を求めてください。
 薬局で売られている薬品の組み合わせで、物質Cを生成できない場合はそれを報告してください。
=================================================================

解説=============================================================

 dp[i][j][k] := i番目の薬品を見たとき, タイプAが jグラム, Bが kグラム溜まっているときの最小価格
 としてdpすれば良い
 
================================================================
*/

#define MAX_N 40
#define MAX_AB 10
// 40 * 400 * 400 = 4^3 * 10^5
int dp[MAX_N+1][MAX_N*MAX_AB+1][MAX_N*MAX_AB+1];
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    int N,Ma,Mb; cin >> N >> Ma >> Mb;
    vector<int> a(N),b(N),c(N);
    for(int i = 0; i < N;i++) cin >> a[i] >> b[i] >> c[i];

    for(int i = 0; i <= N;i++)
        for(int j = 0; j <= MAX_N*MAX_AB;j++)
            for(int k = 0; k <=MAX_N*MAX_AB;k++) dp[i][j][k] = INF;
    
    dp[0][0][0] = 0;
    
    for(int i = 0; i < N;i++){
        for(int j = 0; j <= MAX_N*MAX_AB;j++){
            for(int k = 0; k <=MAX_N*MAX_AB;k++){
                if(dp[i][j][k] == INF) continue;
                dp[i + 1][j + a[i]][k + b[i]] = min(dp[i + 1][j + a[i]][k + b[i]], dp[i][j][k] + c[i]);
                dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]);
            }
        }
    }
    
    int ans = INF;
    for(int i = 1; i <= MAX_N*MAX_AB;i++){
        for(int j = 1; j <= MAX_N*MAX_AB;j++){
            if(i*Mb == j*Ma){
                ans = min(ans,dp[N][i][j]);
            }
        }
    }
    if(ans == INF){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
	return 0;
}
