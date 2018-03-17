#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://arc073.contest.atcoder.jp/tasks/arc073_a>
問題文============================================================
 とある銭湯には、スイッチを押すと T 秒間お湯が出るシャワーがあります。
 
 なお、お湯が出ているときにスイッチを押すと、そのタイミングから T 秒間お湯が出つづけます。
 お湯の出る時間が T 秒間延長されるわけではないことに注意してください。
 
 このシャワーの前を、N 人の人がスイッチを押して通り過ぎていきます。
 i 人目の人は、1 人目の人がスイッチを押した ti 秒後にスイッチを押します。
 
 お湯が出る時間の総和は何秒かを求めてください。
 
=================================================================

解説=============================================================
手前から順番にシミュレーションすれば良い
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N, T; cin >> N >> T;
    ll res = 0,pre_t = 0;
    for(int i = 0; i  <N;i++){
        ll t; cin >> t;
        if(i == 0){
            pre_t = t; continue;
        }else{
            res += min(t- pre_t,T); pre_t = t;
        }
    }
    res += T;
    cout << res << endl;
	return 0;
}
