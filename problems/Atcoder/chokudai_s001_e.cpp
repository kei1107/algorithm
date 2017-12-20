#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:https://chokudai_s001.contest.atcoder.jp/tasks/chokudai_S001_e>
問題文============================================================
数列 a に含まれる整数のうち、何番目の整数が 1 であるかを出力してください。
=================================================================

解説=============================================================
hai
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    int n; cin >> n;
    int ans = -1;
    for(int i = 1; i <= n;i++){
        int a; cin >> a;
        if(a == 1) ans = i;
    }
    cout << ans << endl;
	return 0;
}
