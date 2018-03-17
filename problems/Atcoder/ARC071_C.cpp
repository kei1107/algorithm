#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://arc071.contest.atcoder.jp/tasks/arc071_a>
問題文============================================================
 すぬけ君は、文字列の書かれた紙から文字をいくつか切り抜いて、並び替えて別の文字列を作るのが好きです。
 
 明日になると、すぬけ君は文字列 S1,…,Sn のうちどれか 1 つが書かれた紙がもらえます。
 すぬけ君は文字列を作る事をとても楽しみにしているので、どんな文字列を作るか計画を立てることにしました。
 ただし、すぬけ君はまだどの文字列が書かれた紙がもらえるかを知らないため、
 どの文字列が書かれていた場合にも作れる文字列を考えることにしました。
 
 S1,…,Sn のどの文字列が書かれていても作れる文字列のうち、最長のものを求めてください。
 最長のものが複数ある場合は、辞書順で最小のものを求めてください。

=================================================================

解説=============================================================

 全ての文字で各単語がいくつ現れるかを確認する。
 答えの文字列に含まれる各単語の個数は、あらかじめ確認した個数の一番少ないものである。
 
 答えはa-zへ順番に作っていけば最小となるのは明らか
 
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<string> S(n);
    for(auto &in:S) cin >> in;
    vector<vector<int>> alpha(n,vector<int>(26,0));
    for(int x = 0; x < n;x++){
        string & s = S[x];
        for(int i = 0; i < (int)s.length();i++){
            alpha[x][s[i]-'a']++;
        }
    }
    string ans ="";
    for(int i = 0; i < 26;i++){
        int minv = INF;
        for(int j = 0; j < n;j++){
            minv = min(minv,alpha[j][i]);
        }
        ans += string(minv,'a'+i);
    }
    cout << ans << endl;
	return 0;
}
