#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
 <url:https://arc085.contest.atcoder.jp/tasks/arc085_b>
 問題文============================================================
 N 枚のカードからなる山札があります。カードにはそれぞれ数が書かれており，
 上から i 枚目には ai が書かれています。
 
 この山札を使い，X さんと Y さんが 2 人でゲームをします。
 X, Y さんは最初，Z,W が書かれたカードを持っています。 そして X さんから交互に以下を行います。
 
 山札から何枚かカードを引く。そして今持っているカードを捨て，最後に引いたカードを代わりに持つ。
 ただし，必ず 1 枚は引かなくてはならない。
 山札がなくなるとゲームは終了で，2 人の持っているカードに書かれた数の差の絶対値がこのゲームのスコアになります。
 
 X さんはスコアを最大化するように，Y さんはスコアを最小化するようにゲームをプレイした時，
 スコアはいくつになるでしょうか？
 
 =================================================================
 
 解説=============================================================
 
 よくよく考えると 最適にするには X君は a_N or a_N-1 のカードをとらなければ行けないことがわかる
 よって O(1)
 
 
 ちなみに min-max法 + αβ法　を使えば　ゴリ押せる
 
 ================================================================
 */

// ===================================== //
// O(1)
void solve1(){
    ll N,Z,W; cin >> N >> Z >> W;
    vector<ll> a(N);
    for(auto &in:a) cin >> in;
    if(N != 1){
        cout << max({abs(a[N-1] - W),abs(a[N-2] - a[N-1])}) << endl;
    }else{
        cout << abs(a[N-1]-W) << endl;
    }
}

// ===================================== //
// minmax + αβ
ll N, Z, W;
ll dp[2001][2001];
vector<ll> a;
ll rec(ll i,ll j, ll k,ll alpha, ll beta) {
    ll& res = dp[i][j];
    if (res != -LINF)return res;
    if (i == N || j == N) {
        ll X = (i == 0) ? Z : a[i];
        ll Y = (j == 0) ? W : a[j];
        res = abs(X - Y);
        return res;
    }
    if (k == 1) {
        res = LINF;
        for (int y = i + 1; y <= N;y++) {
            res = min(res, rec(i, y, 0, alpha, res));
            if (alpha >= res) {
                return alpha;
            }
        }
    }
    else {
        for (int x = j + 1; x <= N;x++) {
            res = max(res, rec(x, j, 1, res, beta));
            if (res >= beta) {
                return beta;
            }
        }
    }
    return res;
}
void solve_minmax(){
    cin >> N >> Z >> W;
    a.resize(N + 1);
    for (int i = 1; i <= N;i++) cin >> a[i];
    for (int i = 0; i <= N;i++) {
        for (int j = 0; j <= N;j++) {
            dp[i][j] = -LINF;
        }
    }
    cout << rec(0, 0, 0, -LINF, LINF) << endl;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    solve1();
//    solve_minmax();
    return 0;
}
