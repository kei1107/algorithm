#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://arc075.contest.atcoder.jp/tasks/arc075_a>
問題文============================================================
 あなたはコンピュータで試験を受けています。試験は N 問の問題からなり、
 i 問目の問題の配点は si です。
 それぞれの問題に対するあなたの解答は「正解」または「不正解」のいずれかとして判定され、
 正解した問題の配点の合計があなたの成績となります。
 あなたが解答を終えると、解答がその場で採点されて成績が表示される…はずでした。
 
 ところが、試験システムに欠陥があり、成績が 10 の倍数の場合は、画面上で成績が 0 と表示されてしまいます。
 それ以外の場合は、画面に正しい成績が表示されます。
 この状況で、成績として画面に表示されうる最大の値はいくつでしょうか？
=================================================================

解説=============================================================

 全体の合計からが１０の倍数でなければそれが答え
 10の倍数であれば、最も小さい10の倍数でない一つの要素を引けば答え
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N; cin >> N;
    vector<ll> s(N);
    for(auto &in:s) cin >> in;
    ll Sum = accumulate(s.begin(), s.end(), 0LL);
    ll ans = Sum%10 == 0 ? 0 : Sum;
    for(int i = 0; i < N;i++){
        if(s[i]%10 == 0) continue;
        ans = max(ans,Sum-s[i]);
    }
    cout << ans << endl;
	return 0;
}
