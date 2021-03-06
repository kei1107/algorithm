#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
 <url:https://www.ioi-jp.org/joi/2016/2017-yo/2017-yo-t4/2017-yo-t4.html>
 問題文============================================================
 ある JOI 関係者は，おもちゃ屋で働いている．今日は，店内にあるぬいぐるみコーナーの整理をすることになった．
 
 ぬいぐるみコーナーの棚には，N 個のぬいぐるみが左から右に一列に並べられている．
 棚は仕切りにより N 個の区画に区切られており，1 つの区画に 1 個のぬいぐるみを置く．
 このおもちゃ屋は合計 M 種類のぬいぐるみを売っており，それぞれ 1 から M までの番号が付けられている．
 棚に並べられた N 個のぬいぐるみは，それぞれこの M 種類のうちのいずれかである．
 また，それぞれの種類のぬいぐるみは，少なくとも 1 個は存在する．
 
 見栄えを良くするため，同じ種類のぬいぐるみが全て連続して棚に置かれるように，ぬいぐるみを並べ替えたい．
 次のような方法で，ぬいぐるみを並べ替えることにした．
 
     N 個のぬいぐるみのうちいくつかを選び，棚から取り出す．取り出さなかったぬいぐるみの位置は動かさない．
     取り出したぬいぐるみを，好きな順に棚の空いている区画に戻していく．
 
 並べ替えた後，同じ種類のぬいぐるみが全て連続して棚に置かれていなければならない．
 並べ替えるために取り出すぬいぐるみの個数の最小値を求めるプログラムを作成せよ．
 
 =================================================================
 解説=============================================================
 
 ditDP + 累積和
 
 dp[i] := i にてフラグが立っている集合がすでに揃えられている時の最小の移動回数
 
 * 既に並べられている要素の順番は気にしなくても良い
 ================================================================
 */
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll N,M; cin >> N >> M;
    vector<vector<ll>> cusum(N+1,vector<ll>(M,0));
    for(int i = 1; i <= N;i++){
        ll t; cin >> t; t--;
        for(int j = 0; j < M;j++){
            cusum[i][j] = cusum[i-1][j] + (j == t);
        }
    }
    vector<ll> dp(1<<M,LINF);
    dp[0] = 0;
    for(int i = 0; i < (1<<M);i++){
        ll cnt = 0;
        for(int j = 0; j < M;j++){
            if((i>>j)&1) cnt += cusum[N][j];
        }
        for(int j = 0; j < M;j++){
            if((i>>j)&1)continue;
            dp[i | (1<<j)] = min(dp[i | (1<<j)],dp[i] + cusum[N][j] - cusum[cnt+cusum[N][j]][j] + cusum[cnt][j]);
        }
    }
    cout << dp[(1<<M)-1] << endl;
    return 0;
}
