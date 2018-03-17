#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://agc012.contest.atcoder.jp/tasks/agc012_a>
問題文============================================================
 AtCoder Group Contestの参加者に 3N 人が参加します。
 i 番目の参加者の 強さ は整数 ai で表されます。
 参加者が 3 人 1 組となるようにチームを N 組作ることにしました。
 1 人の参加者が複数のチームに所属することはできません。
 
 チームの強さはチームメンバーの強さのうち 2 番目に大きい値で表されます。
 例えば、強さが 1,5,2 のメンバーからなるチームの強さは 2 になり、
 強さが 3,2,3 のメンバーからなるチームの強さは 3 になります。
 
 N 組のチームの強さの和としてありうる値のうち、最大の値を求めてください。
=================================================================

解説=============================================================

 強さを最大にする最適な選びかたは
 強さ順にソートした数列において
 Σ3*N-2*i (1 <= i <= N)
 の値となる
 
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N; cin >> N;
    vector<ll> a(3*N); for(auto& in:a) cin >> in;
    sort(a.begin(),a.end());
    ll ans = 0;
    ll idx = 3*N-2;
    while(N--){
        ans += a[idx];
        idx -= 2;
    }
    cout << ans << endl;
	return 0;
}
