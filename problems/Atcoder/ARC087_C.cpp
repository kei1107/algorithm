#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://arc087.contest.atcoder.jp/tasks/arc087_a>
問題文============================================================
 長さ N の正整数の列 a=(a1,a2,…,aN) が与えられます。
 あなたの目標は、a のうちいくつかの要素を取り除き、a を 良い数列 にすることです。
 
 ここで、数列 b が 良い数列 であるとは、次の条件が成り立つことです。
 
 b の各要素 x について、b に値 x はちょうど x 個含まれる。
 例えば、(3,3,3), (4,2,4,1,4,2,4), () (空の数列) は良い数列です。
 一方、(3,3,3,3), (2,4,1,4,2) は良い数列ではありません。
 
 a を良い数列にするために取り除くべき要素の個数の最小値を求めてください。
=================================================================

解説=============================================================

 連想配列である数値が何個存在するのかを保存しておき、順番に見ていけば良い
 
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N; cin >> N;
    map<ll,ll> mp;
    for(int i = 0; i < N;i++){
        ll A; cin >> A;
        mp[A]++;
    }
    ll ans = 0;
    for(auto p:mp){
        if(p.first < p.second) ans += p.second - p.first;
        else if(p.first > p.second) ans += p.second;
    }
    cout << ans << endl;
	return 0;
}
