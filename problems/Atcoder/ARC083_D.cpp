#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://arc083.contest.atcoder.jp/tasks/arc083_b>
問題文============================================================
 かつて存在した高橋王国には N 個の都市があり、いくつかの都市の組は道路で双方向に結ばれていました。
 道路の構造は以下のようであったことがわかっています。
 
 都市間の移動は道路を通ってのみ行われ、
 どの都市からどの都市へも必要なら他の都市を経由することで移動できるようになっていた。
 
 道路の長さは道路によって異なっていたかもしれないが、全て正整数であった。
 考古学者のすぬけ君は、高橋王国の遺跡で整数からなる N×N の表 A を発見しました。
 すぬけ君は、この表は高橋王国における都市間の道路に沿った最短距離を表した表ではないかと考えました。
 
 すべての u,v について、A の u 行目 v 列目の整数 Au,v が都市 u から都市 v への最短経路の長さとなるような
 道路の構造が存在するかどうか判定してください。
 さらに、存在する場合、
 そのような道路の構造のうち、存在する道路の長さの和が最小となるようなものについて、その和を求めてください。
 
=================================================================

解説=============================================================

 入力からワーシャルフロイドを行なって、各頂点間の距離が変化（厳密には小さくなる）ようであれば
 条件を満たす構造が存在しないため -1
 
 また、必要な最低限の辺に関していえば
 
 頂点 (j,k) において
 dist[j][k] == dist[j][i] + dist[i][k] となる点 i が存在するならば
 直接 j-kへの辺を引くよりも j-i-k へ辺を引くほうが都合がよく
 全ての辺について同様のことを調べて、最終的に 引いたほうが良い辺のコストの総和を出力すれば答え
 
================================================================
*/
ll solve(){
    ll ret = -1;
    ll N; cin >> N;
    vector<vector<ll>> G(N,vector<ll>(N,0));
    for(int i = 0; i < N;i++) for(int j = 0; j < N;j++) cin >> G[i][j];
    
    auto tG = G;
    for(int i = 0; i < N;i++) for(int j = 0; j < N;j++) for(int k = 0; k < N;k++){
        G[j][k] = min(G[j][k],G[j][i] + G[i][k]);
    }
    for(int i = 0; i < N;i++) for(int j = 0; j < N;j++) if(G[i][j] != tG[i][j]) return ret;

    ret = 0;
    vector<vector<int>> use(N,vector<int>(N,1));
    
    for(int i = 0; i < N;i++) for(int j = 0; j < N;j++) for(int k = 0; k < N;k++){
        if(i == j || i == k || j == k) continue;
        if(G[j][k] == G[j][i] + G[i][k]) use[j][k] = 0;
    }

    for(int i = 0; i < N;i++) for(int j = 0; j < N;j++)if(use[i][j]) ret += G[i][j];
    ret /= 2;
    return ret;
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    cout << solve() << endl;
	return 0;
}
