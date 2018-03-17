#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream &operator << (ostream& out,const pair<S,T>& o){
    out << "(" << o.first << "," << o.second << ")"; return out;
}

/*
<url:https://arc079.contest.atcoder.jp/tasks/arc079_c>
問題文============================================================
 長さ N の非負整数列 ai に対し、数列の最大値が N−1 以下になるまで以下の操作を繰り返し行うことを考えます。
 なお、この操作はD問題で考える操作と同一です。
 
 数列のうち最も大きい要素を求める、複数ある場合はどれか 1 つ選ぶ。
 この要素の値を N 減らす。これ以外の要素の値を 1 増やす。
 
 なお、この操作を行い続けると、いつかは数列の最大値が N−1 以下になることが証明できます。
 
 ここで、数列 ai が与えられるので、何回操作を行うことになるかを求めてください。

=================================================================

解説=============================================================

 直感的なものになってしまうが、
 操作に関して 「数列のうち最も大きい要素を求める」という条件は無視してよく
 任意に選ぶことができる
 
 よって、全ての数列に関して a[i]/Nの総和を求め
 各 a[i]/N*N を減じ、 Σa[k]/N - a[i]/N を加算すれば
 全ての要素に関してまとめて計算ができる。
 
 よってこの操作を繰り返していけば良い
================================================================
*/
ll solve(){
    ll res = 0;
    ll N; cin >> N;
    vector<ll> a(N);
    for(auto &in:a) cin >> in;
    while(
          [&]{
              ll S = 0;
              for(int i = 0; i < N;i++) S += a[i]/N;
              if(S == 0) return false;
              res += S;
              for(int i = 0; i < N;i++){
                  ll cnt = a[i]/N;
                  a[i] -= cnt*N; a[i] += S - cnt;
              }
              return true;
          }()
        );
    return res;
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    cout << solve() << endl;
	return 0;
}
