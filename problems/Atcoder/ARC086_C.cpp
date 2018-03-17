#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://arc086.contest.atcoder.jp/tasks/arc086_a>
問題文============================================================
 高橋君は，N 個のボールを持っています． 最初，i 番目のボールには，整数 Ai が書かれています．
 
 高橋君は，いくつかのボールに書かれている整数を書き換えて，
 N 個のボールに書かれている整数が K 種類以下になるようにしたいです．
 
 高橋君は，少なくとも何個のボールの整数を書き換える必要があるでしょうか？

=================================================================

解説=============================================================

 ある数字が何個存在するのかを確認し、K種類より大きければ、K種類以下になるように、
 数が少ないものから順に書き換えていけば良い
 
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N,K; cin >> N >> K;
    vector<ll> A(N);
    for(auto &in:A) cin >> in;
    map<ll,ll> mp;
    for(auto v:A) mp[v]++;
    vector<ll> ps;
    for(auto c:mp) ps.push_back(c.second);
    sort(ps.begin(),ps.end());
    ll ans = 0;
    for(int i = 0; i < (int)ps.size()-K;i++){
        ans += ps[i];
    }
    cout << ans << endl;
	return 0;
}
