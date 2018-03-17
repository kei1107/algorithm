#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://agc008.contest.atcoder.jp/tasks/agc008_b>
問題文============================================================
 N 個のマスが横一列に並んでいます。 左から i 番目のマスには整数 ai が書かれています。
 
 最初、すべてのマスは白色です。 すぬけ君は次の操作を好きな回数だけ繰り返します。
 
 連続する K 個のマスを選び、それらすべてを白く塗るか、それらすべてを黒く塗る。
 このとき、各マスの色は上書きされる。
 すぬけ君が操作を終えた後、黒いマスに書かれた整数の総和がスコアになります。
 考えられるスコアの最大値を求めてください。
=================================================================

解説=============================================================
 
 自由に塗り替える色を黒か白かに決定できるので、
 最終的に 任意の連続するK個の区間が　黒 or 白　で統一さえしていれば、
 他のマスは自由な色付けをすることができる。
 
 よって、区間の総和を累積和でとっておき、
 ある区間を黒 or 白にした時の総和と他のマスで正となっているものの総和を全探索すれば良い
 
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N,K; cin >> N >> K;
    vector<ll> a(N);
    for(auto &in:a) cin >> in;
    vector<ll> cusum(N+1,0);
    vector<ll> p_cusum(N+1,0);
    for(int i = 0; i < N;i++) {
        cusum[i+1] = cusum[i] + a[i];
        p_cusum[i+1] = p_cusum[i] + max(a[i],0LL);
    }
    ll ans = 0;
    for(int i = 0;i <= N - K;i++){
        ll sec_sum = cusum[i+K] - cusum[i];
        ll l_sum = p_cusum[i];
        ll r_sum = p_cusum[N] - p_cusum[i+K];
        ans = max(ans,max(sec_sum,0LL) + l_sum + r_sum);
    }
    cout << ans << endl;
	return 0;
}
