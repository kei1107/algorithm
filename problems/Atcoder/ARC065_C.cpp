#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://arc065.contest.atcoder.jp/tasks/arc065_a?lang=en>
問題文============================================================
 英小文字からなる文字列 S が与えられます。
 Tが空文字列である状態から始め、以下の操作を好きな回数繰り返すことで S=T とすることができるか判定してください。
 
 T の末尾に dream dreamer erase eraser のいずれかを追加する。

=================================================================

解説=============================================================

 追加するにて、後ろ側から見た時、同じ部分文字となる部分が存在しないので、
 Sを後ろから見て行った時に追加する文字を一意に決められる
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    string S; cin >> S;
    string s[4] = {"dream" , "dreamer", "erase" ,"eraser"};
    int at = (int)S.length();
    while(at > 0){
        bool f = false;
        for(int i = 0; i < 4;i++){
            if(at < s[i].length()) continue;
            string tmp = S.substr(at-s[i].length(),s[i].length());
            if(tmp == s[i]){
                f = true;
                at -= s[i].length();
                break;
            }
        }
        if(!f){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
	return 0;
}
