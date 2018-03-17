#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://arc072.contest.atcoder.jp/tasks/arc072_b>
問題文============================================================
 AliceとBrownはゲームをするのが好きです。今日は以下のゲームを思いつきました。
 
 2つの山があり、はじめにX,Y個の石が置かれています。
 AliceとBrownは毎ターン以下の操作を交互に行い、操作を行えなくなったプレイヤーは負けとなります。
 
 片方の山から 2i 個の石を取り、そのうち i 個の石を捨て、残りの i 個の石をもう片方の山に置く。
 ここで、整数 i(1≦i) の値は山に十分な個数の石がある範囲で自由に選ぶことができる。
 Aliceが先手で、二人とも最適にプレイすると仮定したとき、
 与えられた X,Y に対しどちらのプレイヤーが勝つか求めてください。
 

=================================================================

解説=============================================================

 解説を見た
 参考：
 https://atcoder.jp/img/arc072/editorial.pdf
 http://ronly.hatenablog.com/entry/2017/10/12/182048
 
 (x,y) = (0,0),(1,0),(0,1),(1,1) ならば必ず自分が負ける
 この状態から逆に遷移させて考える
 
 負け:L 勝ち:W
 
    0 1 2 3 4 5 6
  0 L L W W W W W
  1 L L L W W W W
  2 W L L L W W W
  3 W W L L L W W
  4 W W W L L L W
  5 W W W W L L L
  6 W W W W W L L
 
 => |x - y| <= 1 then Win Brown
    |x - y| >= 2 then Win Alice
================================================================
*/
void solve(){
    ll X,Y; cin >> X >> Y;
    if(abs(X-Y)<= 1){
        cout << "Brown" << endl;
    }else{
        cout << "Alice" << endl;
    }
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    solve();
	return 0;
}
