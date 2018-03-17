#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://arc084.contest.atcoder.jp/tasks/arc084_a>
問題文============================================================
 今年もすぬけ祭の季節がやってきました。
 りんごさんは、まず手始めにすぬけ君召喚の儀式を執り行おうと思っています。
 儀式には祭壇が必要で、祭壇は上部、中部、下部の 3 つのカテゴリーのパーツ 1 つずつからなります。
 
 祭壇の 3 カテゴリーのパーツがそれぞれ N 個ずつあります。
 i 個目の上部のパーツのサイズは Ai 、i 個目の中部のパーツのサイズは Bi 、i 個目の下部のパーツのサイズは Ci です。
 
 祭壇を作るにあたっては、中部のパーツのサイズは上部のパーツのサイズより真に大きく、
 下部のパーツのサイズは中部のパーツのサイズより 真に大きくなければなりません。
 逆に、この条件を満たす任意の 3 つのピースを組み合わせて祭壇を作ることができます。
 
 りんごさんが作ることのできる祭壇は何種類あるでしょうか。
 ただし、2 つの祭壇が異なるとは、上部、中部、下部に使われるピースのうち 少なくとも 1 つが異なることを言います。
 
=================================================================

解説=============================================================

 注目すべき場所は中部の段
 この段のサイズを決定すれば、上部はそれよりも小さいもの全て、下部はそれよりも大きいもの全て
 を用いて祭壇を作ることができる
 
 よって、中部の祭壇に関して、順番に見て行き、lower_bound upper_boundなどを用いて
 上部、下部の祭壇の数を求めれば良い
 
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N; cin >> N;
    vector<ll> A(N),B(N),C(N);
    for(auto& in:A) cin >> in;
    for(auto& in:B) cin >> in;
    for(auto& in:C) cin >> in;
    sort(A.begin(),A.end()); sort(B.begin(),B.end()); sort(C.begin(),C.end());
    ll ans = 0;
    for(int i = 0; i < N;i++){
        auto ue = lower_bound(A.begin(),A.end(),B[i]);
        auto sita = upper_bound(C.begin(),C.end(),B[i]);
        if(ue == A.begin()) continue;
        ans += (ue - A.begin()) * (C.end() - sita);
    }
    cout << ans << endl;
	return 0;
}
