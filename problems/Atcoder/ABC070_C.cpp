#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://abc070.contest.atcoder.jp/tasks/abc070_c>
問題文============================================================
 N 台の時計があり、i(1≦i≦N) 番目の時計の針はちょうど Ti 秒で時計盤を 1 周します。
 最初、全ての時計の針は真っ直ぐ上に向いており、止まっています。
 イルカは、全ての時計の針を同時に動かし始めました。
 再び、全ての時計の針が真っ直ぐ上に向くのは何秒後でしょうか?
=================================================================

解説=============================================================
lcmだね
================================================================
*/

inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N; cin >> N;
    ll res = 1;
    for(int i = 0; i < N;i++){
        ll x; cin >> x;
        res = lcm(res,x);
    }
    cout << res << endl;
	return 0;
}
