#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://arc067.contest.atcoder.jp/tasks/arc067_b>
問題文============================================================
 東西方向にのびる直線上に、N 個の町があります。 町には、西から順に 1 から N までの番号がついています。
 直線上には座標が設定されていて、東に行くほど座標が大きくなります。 町 i の座標は Xi です。
 
 あなたは今、町 1 にいて、これからほかの全ての町を訪れたいです。 移動する手段は次の 2 種類あります。
 
 直線上を歩いて移動する。 東西どちらに歩いても、1 移動する度に疲労度が A 上がります。
 
 好きな場所へテレポートする。 テレポートをすると、移動した距離によらず疲労度が B 上がります。
 
 この 2 種類の移動を繰り返して全ての町を最適に回った時、疲労度の上昇値の合計の最小値がいくつになるか求めてください。
 
=================================================================

解説=============================================================

 これは簡単
 街は順番に昇順に並んでいるのでそのまま順番に訪れて行ったほうがいい
 また、テレポートするなら初めから次の街に行ったほうがいいので
 順番に街と街の間を 歩いて or テレポート
 のどちらが疲労度が小さくなるかを見て行けばよい
 
================================================================
*/
ll solve(){
    ll N,A,B; cin >> N >> A >> B;
    vector<ll> X(N); for(auto &in:X) cin >> in;
    ll res = 0;
    for(int i = 0; i < N-1;i++){
        res += min(A*(X[i+1]-X[i]),B);
    }
    return res;
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    cout << solve() << endl;
	return 0;
}
