#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://code-festival-2017-qualc.contest.atcoder.jp/tasks/code_festival_2017_qualc_c>
問題文============================================================
 問題文
 英小文字のみからなる文字列 s があります。
 すぬけ君は、次の操作を繰り返し行うことができます。
 
 s の任意の位置 (先頭および末尾を含む) をひとつ選び、英小文字 x をひとつ挿入する。
 すぬけ君の目標は、s を回文にすることです。
 すぬけ君の目標が達成可能か判定し、達成可能ならば必要な操作回数の最小値を求めてください。
 
 注釈
 回文とは、前後を反転しても変わらない文字列のことです。
 例えば、a, aa, abba, abcba は回文ですが、ab, abab, abcda は回文ではありません。
 
 制約
 1≤|s|≤10^5
 s は英小文字のみからなる。
=================================================================

解説=============================================================

 x は自由に挿入可能だが、それ以外の文字は挿入することができない
 
 よって、 x を無視した文字列がすでに回文になっていなければ文字列を回文にすることができない
 
 よって、xを無視して回文かどうかを調べればいい
 
 あとは、いくつ x を挿入すればいいかに関しては、
 今度は x を無視せずに調べていき、 xが出てきてかつ、そのxがすでに回文の一部でなければ
 xを挿入 => 操作回数＋１
 して行けばいい
 
================================================================
*/
ll solve(){
    string s; cin >> s;
    ll ret = 0;
    
    ll l = 0, r = s.length()-1;
    while(l <= r){
        if(s[l] == s[r]){
            l++; r--;
        }else{
            if(s[l] == 'x'){
                l++; ret++;
                continue;
            }
            if(s[r] == 'x'){
                r--; ret++;
                continue;
            }
            return -1;
        }
    }
    return ret;
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    cout << solve() << endl;
	return 0;
}
