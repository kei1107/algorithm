#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:https://chokudai_s001.contest.atcoder.jp/tasks/chokudai_S001_j>
問題文============================================================
 数列 a をバブルソートした時、スワップが何回発生するかを出力しなさい。
=================================================================

解説=============================================================
BITを使った反転数の数え上げ
================================================================
*/

struct BIT {
    int N;
    vector<ll> bit;
    BIT(int N):N(N) {
        /* BITは[1..N]で扱う */
        bit.resize(N + 1, 0);
    }
    
    void add(int x, int val)
    {
        while (x <= N) {
            bit[x] += val;
            x += x & -x;
        }
    }
    
    int sum(int x)
    {
        int ret = 0;
        while (x) {
            ret += bit[x];
            x &= (x - 1);
        }
        
        return (ret);
    }
};

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll ans = 0;
    ll n; cin >> n;
    struct BIT B(n);
    for(int i = 0; i < n;i++){
        ll a; cin >> a;
        ans += i - B.sum(a);
        B.add(a,1);
    }
    cout << ans << endl;
	return 0;
}
