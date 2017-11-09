#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
 <url:https://www.ioi-jp.org/camp/2007/2007-sp-tasks/2007-sp-day1_20.pdf>
 問題文============================================================
 m x n の各マスに価値が割り当てられ、指定されたa x b の長方形ブロックを得たい時、
 必要とする費用の最小値を出力する。しかし、マスには指定することができないものも含まれている
 =================================================================
 解説=============================================================
 
 最大長方形で行う前処理と累積和を組み合わせる。
 まず、縦・横どちらでもいいので今いるブロックから縦、横にどれだけの高さがあるのかを
 求める.O(N^2) : dp_init
 
 次に、ブロックの累積和を求めるO(N^2) : cusum_init
 
 この時、全てのブロックに対して、a x bの長方形を作りうるのであれば累積和から
 必要な費用を計算すればよいO(N^2)
 
 ================================================================
 */

ll m,n;
ll a,b;
vector<vector<ll>> masu;
vector<vector<ll>> dp;

void dp_init(){
    for(int i = 1; i <= n;i++){
        for(int j = 1; j <=m;j++){
            if(masu[i][j] == -1)continue;
            dp[i][j] = dp[i-1][j] + 1;
        }
    }
}

void cusum_init(){
    for(int i = 1; i <= n;i++){
        for(int j = 1; j <= m;j++){
            masu[i][j] = masu[i-1][j] + masu[i][j-1]
                            - masu[i-1][j-1] + ((masu[i][j] == -1)?0:masu[i][j]);
        }
    }
}

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> m >> n >> a >> b;
    masu.assign(n+1,vector<ll>(m+1,0));
    dp.assign(n+1,vector<ll>(m+1,0));
    for(int i = 1; i <= n;i++){
        for(int j = 1; j <= m;j++){
            cin >> masu[i][j];
        }
    }
    
    /* preprocessing */
    dp_init();
    cusum_init();
    
    /* solve */
    ll res = LINF;
    for(int i = b; i<= n;i++){
        ll l = 0;
        for(int j = 1; j <= m;j++){
            if(dp[i][j] < b){
                l = j;
                continue;
            }
            if(j - l >= a){
                res = min(res,masu[i][j] - masu[i-b][j] - masu[i][j-a] + masu[i-b][j-a]);
            }
        }
    }
    cout << res << endl;
    return 0;
}
