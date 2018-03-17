#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://arc078.contest.atcoder.jp/tasks/arc078_a>
問題文============================================================
 すぬけくんとアライグマは N 枚のカードの山を作りました。
 カードの山の上から i 番目のカードには整数 ai が書かれています。
 
 N 枚のカードを分け合うことにしました。
 すぬけくんがカードの山の上から何枚かのカードを取ったあと、アライグマは残ったカード全てを取ります。
 このとき、すぬけくんもアライグマも 1 枚以上のカードを取る必要があります。
 
 すぬけくんとアライグマが持っているカードに書かれた数の総和をそれぞれ x,y として、
 |x−y| を最小化したいです。 |x−y| としてありうる値の最小値を求めなさい。

=================================================================

解説=============================================================

 累積和を用意れば,各山の総和がO(1)でもとまる
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll n; cin >> n;
    vector<ll> a(n);
    for(auto &in:a) cin >> in;
    vector<ll> cusum(n+1,0);
    for(int i = 0; i < n;i++){
        cusum[i+1] = cusum[i] + a[i];
    }
    ll ans = LINF;
    for(int i = 1; i < n;i++){
        ans = min(ans,abs(cusum[i] - (cusum[n] - cusum[i])));
    }
    cout << ans << endl;
	return 0;
}
