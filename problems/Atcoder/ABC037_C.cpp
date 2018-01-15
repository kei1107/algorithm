#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e16;

/*
<url:https://beta.atcoder.jp/contests/abc037/tasks/abc037_c>
問題文============================================================

 略
 
=================================================================

解説=============================================================
 
 区間の長さがKと初めから与えてられているので
 (0,K) -> (1,K+1) -> ... -> (N - 1 - K,N - 1)
 とスライドさせてその和を見ていけばよい
 
 一つ右にスライドさせたときの合計は
 現時点での合計 + a[i] - a[i - K]
 でO(1)で求まる
 
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N,K; cin >> N >> K;
    vector<ll> a(N);
    for(auto& in:a) cin >> in;
    ll ans = 0;
    ll sum = 0;
    for(int i = 0; i < K;i++){
        sum += a[i];
    }
    ans += sum;
    for(int i = K; i < N;i++){
        sum += a[i]; sum -= a[i - K];
        ans += sum;
    }
    cout << ans << endl;
	return 0;
}
