#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://abc076.contest.atcoder.jp/tasks/abc076_d>
問題文============================================================
 2168年、AtCoder 社は成長し、ついに "AtCoder特急" という鉄道を建設することを決めた。
 
 さて、社長の高橋君は、"AtCoder特急" の列車を以下のように運行することを計画した。
 
 列車の走行時間は、(t1+t2+t3+…+tN) 秒である。
 最初の t1 秒間は、列車は速度 v1 m/s 以内で走っていなければならない。
 また、次の t2 秒間は、列車は速度 v2 m/s 以内で走っていなければならない。
 次の t3 秒間、またそれ以降についても同様である。
 
 最後の tN 秒間は、列車は速度 vN m/s 以内で走っていなければならない。
 ただし、列車の性能上、加速度は ±1m⁄s2 以内でなければならない。
 また、走行開始時と走行終了時には列車は止まっていなければならない。
 
 列車が発車してから停車するまでに走れる最大の距離を求めなさい。
=================================================================

解説=============================================================
 区間[l,r] の最大速度が v の集合だと考える
 
 時間 t において
     t <= l であれば
         その時出せる最大速度は v + (l - t)
     t >= r であれば
         その時出せる最大速度は v + (t - r)
     l <= t <= r であれば
         その時出せる最大速度は v
 となるので、
 全区間・時間に関してこれらの最大値を求めて面積を計算していけば良い
 
 t = 0.5刻みで行えば十分
================================================================
*/

// 区間[l,r] の最大 v
struct _f {
    ll v, l, r;
    _f() {}
    _f(ll v, ll l, ll r) :v(v), l(l), r(r) {}
};

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll N; cin >> N;
    vector<ll> t(N), v(N);
    for (int i = 0; i < N;i++) cin >> t[i];
    for (int i = 0; i < N;i++) cin >> v[i];
    
    vector<_f> F; F.push_back(_f(0, 0, 0));
    ll t_sum = 0;
    for (int i = 0; i < N;i++) {
        F.push_back(_f(v[i], t_sum, t_sum + t[i]));
        t_sum += t[i];
    }
    F.push_back(_f(0, t_sum, t_sum));
    
    double res = 0.0;
    double pre_v = 0.0;
    for (double T = 0.5; T <= t_sum;T += 0.5) {
        double next_v = INF;
        for (auto _F : F) {
            if (T <= _F.l) { next_v = min(next_v, (double)(_F.v + (_F.l - T))); }
            else if (T >= _F.r) { next_v = min(next_v, (double)(_F.v + (T - _F.r))); }
            else { next_v = min(next_v, (double)_F.v); }
        }
        // 面積計算
        res += (pre_v + next_v)*0.5 / 2.0;
        pre_v = next_v;
    }
    cout << fixed << setprecision(10) << res << endl;
    return 0;
}
