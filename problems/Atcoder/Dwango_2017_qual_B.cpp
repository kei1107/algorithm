#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://dwacon2017-prelims.contest.atcoder.jp/tasks/dwango2017qual_b>
問題文============================================================
 ニコニコ文字列とは、25 を 0 回以上繰り返した文字列のことをいいます。
 たとえば 25 や 252525 や空文字列はニコニコ文字列ですが、123 や 225 はニコニコ文字列ではありません。
 
 ある文字列 S がその連続した部分文字列として含む最長のニコニコ文字列の長さを S の ニコニコレベル といいます。
 たとえば 52525, 25025, 12151 のニコニコレベルはそれぞれ 4, 2, 0 です。
 
 ニワンゴくんは 0 から 9 の数字と ? からなる文字列 T を持っており、
 それぞれの ? を好きな数字に置き換えることで、数字のみからなる文字列 T' を作ろうとしています。
 ニワンゴくんが作ることのできる文字列 T' のニコニコレベルの最大値を求めて下さい。
=================================================================

解説=============================================================

 偶数indexから2が始まるパターンと
 奇数indexから2が始まるパターン、それぞれについて最大のニコニコ文字列長を確認すれば良い
 
================================================================
*/

bool check(int n,string& s){
    if(n + 1 >= s.length()) return false;
    return (s[n] == '?' || s[n] == '2') && (s[n+1] == '?' || s[n+1] == '5');
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    string T; cin >> T;
    int ans = 0;
    int len = 0;
    for(int i = 0; i < T.size();i+=2){
        if(check(i,T)) len += 2;
        else len = 0;
        ans = max(ans,len);
    }
    len = 0;
    for(int i = 1; i < T.size();i+=2){
        if(check(i,T)) len += 2;
        else len = 0;
        ans = max(ans,len);
    }
    cout << ans << endl;
	return 0;
}
