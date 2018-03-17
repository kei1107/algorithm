#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://arc062.contest.atcoder.jp/tasks/arc062_b>
問題文============================================================
 シカのAtCoDeerくんは友達のTopCoDeerくんとあるゲームをして対戦しています。
 このゲームは N ターンからなります。各ターンではそれぞれのプレイヤーはじゃんけんのグーかパーを出します。
 ただし、各プレイヤーは次の条件を満たす必要があります。
 
 (※) 各ターンの後で、(今までにパーを出した回数)≦(今までにグーを出した回数)　を満たす
 
 このゲームでの各プレイヤーの得点は、(勝ったターンの数) − (負けたターンの数) です。
 AtCoDeerくんは特殊能力を持っているので、
 ゲームが始まる前にTopCoDeerくんの出す N ターンの手を全て知ることが出来ました。
 AtCoDeerくんの各ターンでの手を決めて、AtCoDeerくんの得点を最大化してください。
 TopCoDeerくんの出す手の情報は文字列 s で与えられます。
 s の i(1≦i≦N) 文字目が gのときは i ターン目でTopCoDeerくんがグーを出すことを、
 pのときはパーを出すことを表します。
=================================================================

解説=============================================================

 良く考えれば　gpgpgp...と交互に出すのが最適だとわかる
 
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    string s; cin >> s;
    int ans = 0;
    for(int i = 0; i < (int)s.length();i++){
        if(i%2 == 0){
            if(s[i] == 'p') ans--;
        }else{
            if(s[i] == 'g') ans++;
        }
    }
    cout << ans << endl;
	return 0;
}
