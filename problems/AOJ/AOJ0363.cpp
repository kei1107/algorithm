#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0363>
問題文============================================================
会津海上運送会社に、新たな積み荷の輸送依頼が舞い込んだ。
 今回依頼された荷物は、すべて同じ大きさで、横幅が２ｍ、縦幅が２ｍである。
 貨物室は長方形で、横幅が４ｍで固定されているが、縦幅はさまざまである。
 また、荷物は横と縦それぞれ１ｍを単位とした区画の境界に合わせて置く必要があり（５０ｃｍずらしたりなどはできない）、
 傾けて置いたり、重ねて置いたりすることはできない。また、荷物が置けない区画もある。
 
 現在使える船の貨物室に荷物をできるだけ積んで輸送したいが、最大でいくつ積めるかを知りたい。
 貨物室の縦の長さと、その中で荷物が置けない区画が与えられたとき、
 最大でいくつの荷物が積めるかを報告するプログラムを作成せよ。
=================================================================

解説=============================================================
 dp[i][S] := i-1番目まで見た時、i-1番目の列の状況がSの時の最大個数
================================================================
*/

ll H,N;
ll dp[10010][1<<4];
bool masu[10010][4];

bool ok(int x,int y,int S){
    if(x < 3 && y < H - 1){
        return !masu[y][x] && !masu[y][x+1] && !masu[y+1][x] && !masu[y+1][x+1] && !((S>>x)&1) && !((S>>(x+1))& 1);
    }else return false;
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    cin >> H >> N;
    for(int i = 0; i < N;i++){
        ll x,y; cin >> x >> y;
        masu[y][x] = true;
    }
    for(int i = 0; i < H;i++){
        for(int j = 0; j < (1<<4);j++){
            if(ok(0,i,j)){
                if(ok(2,i,j)){
                    dp[i+1][(1<<4)-1] = max(dp[i+1][(1<<4)-1],dp[i][j]+2);
                }
                dp[i+1][(1<<2)-1] = max(dp[i+1][(1<<2)-1],dp[i][j]+1);
            }
            if(ok(1,i,j)){
                dp[i+1][6] = max(dp[i+1][6],dp[i][j]+1);
            }
            if(ok(2,i,j)){
                dp[i+1][12] = max(dp[i+1][12],dp[i][j]+1);
            }
            dp[i+1][0] = max(dp[i+1][0],dp[i][j]);
        }
    }
    ll res = 0;
    for(int i = 0; i < (1<<4);i++){
        res = max(res,dp[H][i]);
    }
    cout << res << endl;
	return 0;
}
