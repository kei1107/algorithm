#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0358>
問題文============================================================
 あなたは、今日発売された新刊「プログラミング甲子園必勝法」を買うために、友達のＡ君と本屋に来ています。
 あなたはどうしてもその本を買いたいので、手持ちの金額で足りないときは、Ａ君からお金を借りようと思っています。
 それでも足りなければ、今回はあきらめるしかありません。
 
 あなたの手持ちの金額、Ａ君の手持ちの金額、本の値段が与えられたとき、
 本を買うためにＡ君から借りなければならない最小の金額を出力するプログラムを作成せよ。

=================================================================

解説=============================================================
hai
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll m,f,b; cin >> m >> f >> b;
    if(m + f < b){
        cout << "NA" << endl;
    }else{
        cout << ((m < b)?b-m:0) << endl;
    }
	return 0;
}
