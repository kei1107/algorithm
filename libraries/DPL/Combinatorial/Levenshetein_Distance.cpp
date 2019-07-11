#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/* http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_E&lang=jp
編集距離
２つの文字列 s1、s2 の編集距離（レーベンシュタイン距離）を求めて下さい。

編集距離とは、以下３種類の操作によって、１つの文字列を別の文字列に変形するのに必要な手順の最小回数です：

挿入: 文字列に１つの文字を挿入する。
削除: 文字列から１つの文字を削除する。
置換: 文字列の中の１文字を別な文字に置き換える。

*/

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	string s1, s2; cin >> s1 >> s2;
	vector<vector<ll>> dp(s1.length() + 1, vector<ll>(s2.length() + 1, INF));

	/* dp[i][j] := 文字列s1[0..(i-1)] から 文字列s2[0..(j-1)]の編集距離 ( 添え字0はヌル ) */
	dp[0][0] = 0;
	for (int i = 1; i <= s1.length();i++) dp[i][0] = i;
	for (int j = 1; j <= s2.length(); j++) dp[0][j] = j;

	for (int i = 1; i <= s1.length(); i++) {
		for (int j = 1; j <= s2.length(); j++) {
			dp[i][j] = min({
				dp[i][j - 1] + 1,
				dp[i - 1][j] + 1,
				dp[i - 1][j - 1] + (s1[i - 1] != s2[j - 1])
			});
		}
	}

	/*for (int i = 0; i <= s1.length();i++) {
		for (int j = 0; j <= s2.length(); j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	cout << dp[s1.length()][s2.length()] << endl;
	return 0;
}
