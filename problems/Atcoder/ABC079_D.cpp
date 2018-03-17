#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://abc079.contest.atcoder.jp/tasks/abc079_d>
問題文============================================================
 魔法少女のjoisinoお姉ちゃんは、この世にあるすべての数字を 1 に変えてやろうと思い立ちました。
 
 1 つの数字を i から j(0≦i,j≦9) に書き変えるには魔力 ci,j が必要です。
 
 今、目の前にある壁は縦方向に H、横方向に W のマス目になっていて、
 1 つ以上のマス目に 0 以上 9 以下の整数が 1 つずつ書かれています。
 
 上から i(1≦i≦H) 番目、左から j(1≦j≦W) 番目のマスの情報として Ai,j が与えられ、
 
 Ai,j≠−1 の場合はマスに Ai,j が書かれている
 Ai,j=−1 の場合はマスに数字が書かれていない
 ことを意味します。
 
 この壁に書かれている数字を最終的に全て 1 に変えるのに必要な魔力の最小量を求めてください。
=================================================================

解説=============================================================
ワーシャルフロイドで数字変換の最小魔力を求めておき、
 順番にマスを１に変換していけば良い
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll H,W; cin >> H >> W;
    ll G[10][10] = {0};
    for(int i = 0; i < 10;i++)for(int j = 0; j < 10;j++) cin >> G[i][j];
    for(int i = 0; i  < 10;i++)for(int j = 0; j < 10;j++) for(int k = 0; k < 10;k++)
        G[j][k] = min(G[j][k],G[j][i] + G[i][k]);
    ll ans = 0;
    for(int i = 0; i < H;i++){
        for(int j = 0; j < W;j++){
            ll A; cin >> A;
            if(A == -1) continue;
            ans += G[A][1];
        }
    }
    cout << ans << endl;
	return 0;
}
