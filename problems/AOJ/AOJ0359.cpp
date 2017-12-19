#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0359>
問題文============================================================
 ２０１７年９月９日は土曜日です。２０１７年の９月Ｘ日は何曜日でしょうか？
 
 ２０１７年９月の日にちが与えられたとき、その日が何曜日か報告するプログラムを作成せよ。
 
 与えられた日の曜日を１行に出力する。
 ただし、
 月曜日は "mon"、火曜日は"tue"、水曜日は "wed"、木曜日は "thu"、
 金曜日は "fri"、土曜日は "sat"、日曜日は "sun" と出力せよ。
 

=================================================================

解説=============================================================
hai
================================================================
*/

string youbi[7] = {"fri","sat","sun","mon","tue","wed","thu"};
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    int X; cin >> X;
    cout << youbi[(X-1)%7] << endl;
	return 0;
}
