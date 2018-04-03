#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://agc008.contest.atcoder.jp/tasks/agc008_a>
問題文============================================================
 すぬけ君は電卓を持っています。 この電卓にはディスプレイと 2 個のボタンが付いています。
 
 最初、ディスプレイの値は整数 x です。
 すぬけ君の目標は、ディスプレイの値を整数 y にすることです。
 そのために、すぬけ君は次の 2 個のボタンを好きな順番で何回か押すことができます。
 
 ボタン A : ディスプレイの値を 1 増やす。
 ボタン B : ディスプレイの値の符号を反転する。
 目標を達成するためにすぬけ君がボタンを押す回数の最小値を求めてください。
 なお、整数 x, y の値によらず、必ず目標を達成できることが示せます。
=================================================================

解説=============================================================

 x,yの符号が一致しており、かつ y - x >= 0 となれば答えは y - xとなる
 よって、x,yの符号をそれぞれ変化させた時、上記条件を満たす最小の値を求めれば良い
 
================================================================
*/
ll F(ll x,ll y){
    if(y - x >= 0) return y - x;
    else return LINF;
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll x,y; cin >> x >> y;
    cout << min({F(x,y),F(x,-y)+1,F(-x,y)+1,F(-x,-y)+2}) << endl;
	return 0;
}