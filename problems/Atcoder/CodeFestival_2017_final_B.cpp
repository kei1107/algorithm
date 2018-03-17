#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://cf17-final-open.contest.atcoder.jp/tasks/cf17_final_b>
問題文============================================================
 問題文
 すぬけ君は a、b、c の 3 種類の文字のみからなる文字列 S を持っています。
 
 回文恐怖症のすぬけ君は S の文字を自由に並び替えて、
 2 文字以上の回文を部分文字列として含まないようにしようと思いました。
 これが可能かどうかを判定して下さい。
 
 制約
 1≤|S|≤10^5
 S は a、b、c 以外の文字を含まない。

=================================================================

解説=============================================================

 制約の "  S は a、b、c 以外の文字を含まない。 "
 
 で問題がかなり簡単になる
 考えられる文字が三文字しかない場合　二文字以上の回文には
 
 abcabcabc....
 acbacbacb....
 bacbacbac....
 bcabcabca....
 cabcabcab....
 cbacbacba....
 
 しか考えられない。よってこのいづれかのものを作ることができるかを確認すれば良い
 
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    string S; cin >> S;
    int abc[3] = {};
    for(int i = 0; i < S.length();i++){
        abc[S[i]-'a']++;
    }
    int Min = min({abc[0],abc[1],abc[2]});
    abc[0] -= Min; abc[1] -= Min; abc[2] -= Min;
    if(abc[0] >= 2 || abc[1] >= 2 || abc[2] >= 2) cout << "NO" << endl;
    else cout << "YES" << endl;
	return 0;
}
