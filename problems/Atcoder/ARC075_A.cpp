#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e16;

/*
<url:https://beta.atcoder.jp/contests/abc063/tasks/arc075_a>
問題文============================================================

 （略）
 
=================================================================

解説=============================================================

 合計が10の倍数になったらその合計は０と判断される
 
 先にs1~snまでの総和を求めておく、
 ここで総和が10の倍数でなければ、それが答え
 
 10の倍数であれば、
 s1~snまでの中で一番小さく10の倍数でない数字を一つだけ引けば
 その総和は10の倍数でなくなるので、順番にs1~snを見ていけば良い
 
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N; cin >> N;
    vector<ll> s(N);
    for(auto &in:s) cin >> in;
    sort(s.begin(),s.end());
    ll sum = 0;
    for(auto v:s) sum += v;
    ll ans = 0;
    if(sum % 10 != 0){
        ans = max(ans,sum);
    }
    for(auto v:s){
        if((sum - v)%10 != 0){
            ans = max(ans,sum - v);
        }
    }
    cout << ans << endl;
	return 0;
}
