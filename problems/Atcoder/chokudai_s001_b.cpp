#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:https://chokudai_s001.contest.atcoder.jp//tasks/chokudai_S001_b>
問題文============================================================
数列 a の和を出力してください。
=================================================================

解説=============================================================
hai
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    int n; cin >> n;
    int res = 0;
    for(int i = 0; i < n;i++) {
        int a; cin >> a;
        res += a;
    }
    cout << res << endl;
	return 0;
}
