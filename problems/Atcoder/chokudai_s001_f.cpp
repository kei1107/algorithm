#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:https://chokudai_s001.contest.atcoder.jp/tasks/chokudai_S001_f>
問題文============================================================
 数列 a に含まれる整数のうち、1≤j<i≤N を満たす任意の j において、
 aj<ai を満たすような i がいくつあるか出力しなさい。
 1≤N≤100,000
=================================================================

解説=============================================================
前から順番に見ていって、それまでの最大値を保存
 次の値を見たとき、保存されている値よりも大きければ+1
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    int n; cin >> n;
    int Max = -1;
    int ans = 0;
    for(int i = 0; i < n;i++){
        int a; cin >> a;
        if(a > Max){
            ans++;
            Max = a;
        }
    }
    cout << ans << endl;
	return 0;
}
