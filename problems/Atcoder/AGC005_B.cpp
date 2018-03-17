#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://agc005.contest.atcoder.jp/tasks/agc005_b>
問題文============================================================
 すぬけ君はある日友人から長さ N の順列 a1,a2,…,aN を貰いました。
 
 Σ{l = 1..N}Σ{r = l..N} min(al,al+1,...,ar)
 
 を求めてください。
 
 制約
 1≦N≦200,000
 (a1,a2,…,aN) は (1,2,…,N) を並び替えたものである

=================================================================

解説=============================================================

 問題をそのまま計算すると O(N^2)となってTLE
 
 よって、別視点の考えをする。
 ある数値 a[i]に関して、その左右で a[i] が最小となるのがどの範囲であるか。
 この考えを行えば 左側に関して a[i] より小さいものの　位置を l, 右側に関して、a[i]よりも
 小さいものの　位置を r とすれば
 
 (i - l) * (r - l) 個分　a[i]が最小となる。
 
 よって各 a[i] に関して、その個数を 平衡木などを用いて数え上げてやれば良い
 
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N; cin >> N;
    vector<ll> b(N+1,0);
    for(int i = 1; i <= N;i++){
        ll a; cin >> a;
        b[a] = i;
    }
    set<ll> s; s.insert(0); s.insert(N+1);
    ll ans = 0;
    for(ll i = 1; i <= N; i++){
        auto it = s.lower_bound(b[i]);
        ans += i * (*it - b[i]) * (b[i] - *(--it));
        s.insert(b[i]);
    }
    cout << ans << endl;
	return 0;
}
