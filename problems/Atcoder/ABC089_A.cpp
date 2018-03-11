#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://beta.atcoder.jp/contests/abc089/tasks/abc089_a>
問題文============================================================
 ある学校には、N 人の生徒がいます。
 
 生徒たちをいくつかのグループに分け、グループごとにあるテーマについて話し合ってもらうこととなりました。
 
 あなたは、 2 人以下のグループだと効果的な話し合いが出来ないと考えており、
 なるだけ多くのグループを 3 人以上にしたいです。
 
 生徒たちを上手く分けて、 3 人以上のグループの数を最大化してください。
=================================================================

解説=============================================================
 N/3 が答え
================================================================
*/

void solve_A(){
    ll N; cin >> N;
    cout << N/3 << endl;
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    solve_A();
	return 0;
}
