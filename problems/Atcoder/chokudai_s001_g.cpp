#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:https://chokudai_s001.contest.atcoder.jp/tasks/chokudai_S001_g>
問題文============================================================
数列 a を連結させた整数を、 1,000,000,007 で割った余りを求めなさい。
=================================================================

解説=============================================================
はい
================================================================
*/
const ll MOD = 1e9+7;
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    int n; cin >> n;
    string ans = "0";
    for(int i = 0; i < n;i++){
        string a; cin >> a;
        ans += a;
        ll tmp = atoll(ans.c_str());
        tmp%=MOD;
        ans = to_string(tmp);
    }
    cout << ans << endl;
	return 0;
}
