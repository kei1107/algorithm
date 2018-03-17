#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://abc073.contest.atcoder.jp/tasks/abc073_c>
問題文============================================================
 あなたは、joisinoお姉ちゃんと以下のようなゲームをしています。
 
 最初、何も書いていない紙がある。
 joisinoお姉ちゃんが一つの数字を言うので、その数字が紙に書いてあれば紙からその数字を消し、
 書いていなければその数字を紙に書く。これを N 回繰り返す。
 その後、紙に書かれている数字がいくつあるかを答える。
 joisinoお姉ちゃんが言った数字が、言った順番に A1,…,AN として与えられるので、
 ゲーム終了後に紙に書かれている数字がいくつあるか答えてください。
=================================================================

解説=============================================================
setでやるだけ
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N; cin >> N;
    set<ll> s;
    for(int i = 0; i < N;i++){
        ll A; cin >> A;
        if(s.find(A) == s.end()) s.insert(A);
        else s.erase(A);
    }
    cout << s.size() << endl;
	return 0;
}
