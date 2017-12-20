#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:https://chokudai_s001.contest.atcoder.jp/tasks/chokudai_S001_h>
問題文============================================================
数列 a から好きな整数を好きなだけ取り除き、単調増加な数列を作るとき、その数列の長さの最大値を求めなさい。
=================================================================

解説=============================================================
最長増加部分列の長さ
================================================================
*/
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n;i++) cin >> a[i];
    
    vector<ll> dp(n, INF);
    for (int i = 0; i < n;i++) {
        *lower_bound(dp.begin(), dp.end(), a[i]) = a[i];
    }
    
    ll ans = lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
    cout << ans << endl;
    return 0;
}
