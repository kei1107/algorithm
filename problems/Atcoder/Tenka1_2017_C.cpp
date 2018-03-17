#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://tenka1-2017.contest.atcoder.jp/tasks/tenka1_2017_c>
問題文============================================================
 整数 N が与えられる。
 
 4⁄N=1⁄h+1⁄n+1⁄w を満たす正整数 h,n,w を求めよ。
 
 条件を満たす解が複数ある場合、どれを出力しても良い。
 
 制約
 N に対して h,n,w≤3500 となる解が存在することが保証される。

 
=================================================================

解説=============================================================

 4/N = 1/h + 1/n + 1/w
 x4hnwN
 4hnw = nwN + whN + hnN
 移行
 4hn*w - nN*w - hN*w = hnN
 wについてまとめる
 (4hn - nN - hN)*w = hnN
 よって、 h,nを決めうちした時, w を推測できる。
 
 制約より O(3500^2)
 
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N; cin >> N;
    for(int i = 1; i <= 3500;i++){
        for(int j = 1;j<=3500; j++){
            ll X = 4*i*j - i*N - j*N;
            ll Y = i*j*N;
            if(X <= 0) continue;
            if(Y%X == 0){
                cout << i << " " << j << " " << Y/X << endl;
                return 0;
            }
        }
    }
	return 0;
}
