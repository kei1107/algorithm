#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:https://chokudai_s001.contest.atcoder.jp/tasks/chokudai_S001_k>
問題文============================================================
 長さ N の順列のうち、a は辞書順で何番目になるかを求めなさい。
 ただし、答えは非常に大きくなるため、1,000,000,007 で割った余りを出力しなさい。
=================================================================

解説=============================================================
桁ごとに計算
================================================================
*/
const ll MOD = 1e9+7;
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
    ll n; cin >> n;
    vector<ll> a(n),fact(n+1);
    for(auto& in:a) cin >> in;
    fact[0] = 1;
    for(int i = 1; i <= n;i++) fact[i] = (fact[i-1]*i)%MOD;
    
    BIT b(n);
    ll res = 0;
    for(int i = 0; i < n;i++){
        int cnt = b.sum(a[i]);
        res += fact[n - 1 - i] * (a[i] - 1 - cnt);
        res %= MOD;
        b.add(a[i],1);
    }
    cout << res + 1 << endl;
	return 0;
}
