#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://agc021.contest.atcoder.jp/tasks/agc021_a>
問題文============================================================
 問題文
 N 以下の正の整数の 10 進法での各桁の和の最大値を求めてください。
 
 制約
 1≤N≤10^16
 N は整数である
=================================================================

解説=============================================================

 各桁に関して 1繰り下げて それ以下の位を全て 9にした場合を全探索すれば良い
 
================================================================
*/

void solve(){
    ll N; cin >> N;
    string S = to_string(N);
    ll ans = 0;
    ll tmp = 0;
    for(int i = 0; i < (int)S.length();i++){
        ll X = 9*(S.length() - 1 - i) + (S[i] - '0' - 1) + tmp;
        ans = max(ans,X);
        tmp += (S[i] - '0');
    }
    ans = max(ans,tmp);
    cout << ans << endl;
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    solve();
	return 0;
}
