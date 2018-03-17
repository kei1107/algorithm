#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://code-thanks-festival-2017-open.contest.atcoder.jp/tasks/code_thanks_festival_2017_c>
問題文============================================================
 工場にプレゼントを作る機械が N 台あります。i(1≦i≦N) 番目の機械は、最初 ai 秒でプレゼントを 1 個作れます。
 しかし、ある機械でプレゼントを 1 個作るたびにその機械のみが劣化して、
 プレゼントを 1 個作るのにかかる時間が bi 秒増えます。
 したがって、i(1≦i≦N) 番目の機械で si 個目のプレゼントを作るのに　ai+(si−1)×bi 秒かかります。
 また、工場に供給される電力が少ないため、複数の機械を同時に動かすことはできません。
 
 イルカはプレゼント K 個をできる限り短い時間で製造したいです。
 プレゼントの製造にかかる最小の合計時間を求めてください。
=================================================================

解説=============================================================

 今、その機械を使った時の所要時間をキーとしたpriority_queueを用いることによって
 O(Klog(N))で解ける
 
================================================================
*/
struct machine{
    ll T;
    ll A;
    ll B;
    ll C;
    machine(){}
    machine(ll t,ll a,ll b,ll c):T(t),A(a),B(b),C(c){}
    bool operator < (const machine& m) const{
        return T < m.T;
    }
    bool operator > (const machine& m) const{
        return T > m.T;
    }
};
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N,K; cin >> N >> K;
    vector<ll> a(N),b(N);
    for(int i = 0; i < N;i++) cin >> a[i] >> b[i];
    priority_queue<machine,vector<machine>,greater<machine>> pq;
    for(int i = 0; i < N;i++){
        pq.push(machine(a[i],a[i],b[i],0));
    }
    ll ans = 0;
    while(K--){
        auto m = pq.top(); pq.pop();
        ans += m.T;
        pq.push(machine(m.A + (m.C+1)*m.B,m.A,m.B,m.C+1));
    }
    cout << ans << endl;
	return 0;
}
