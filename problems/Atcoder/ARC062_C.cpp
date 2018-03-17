#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
 <url:https://arc062.contest.atcoder.jp/tasks/arc062_a>
 問題文============================================================
 シカのAtCoDeerくんは選挙速報を見ています。選挙には二人の候補高橋くんと青木くんが出ています。
 速報では、現在の二人の得票数の比が表示されていますが、得票数そのものは表示されていません。
 AtCoDeerくんは N 回画面を見て、 i(1≦i≦N) 回目に見たときに表示されている比は Ti:Ai でした。
 ここで、
 AtCoDeerくんが選挙速報の画面を1回目に見た段階で既にどちらの候補にも少なくとも一票は入っていたことがわかっています。
 N 回目に画面を見たときの投票数(二人の得票数の和)として考えられるもののうち最小となるものを求めてください。
 ただし、得票数が途中で減ることはありません。
 =================================================================
 
 解説=============================================================
 
 比率を満たす、最小のt,aを順番に求めていけば良い
 
 ================================================================
 */
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll N; cin >> N;
    vector<ll> T(N),A(N);
    ll t = 1, a = 1;
    for(int i = 0; i < N;i++) cin >> T[i] >> A[i];
    for(int i = 0; i < N;i++){
        ll mul = max((t+T[i]-1)/T[i],(a+A[i]-1)/A[i]);
        t = mul*T[i];
        a = mul*A[i];
    }
    cout << t + a << endl;
    return 0;
}
