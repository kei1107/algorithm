#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream &operator << (ostream& out,const pair<S,T>& o){
    out << "(" << o.first << "," << o.second << ")"; return out;
}
/*
<url:https://beta.atcoder.jp/contests/abc090/tasks/abc090_a>
問題文============================================================
 3行3列の正方形状のマス目があり、各マスには英小文字が書かれています。
 上からi行目、左からj 列目のマスに書かれた文字は、cij です。
 
 マス目の左上と右下を結ぶような対角線上のマス目に書かれた文字を、
 左上から順に読んでできる3 文字の文字列を出力してください。
=================================================================

解説=============================================================
 cout << c[i][i] << endl;
================================================================
*/
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    char c[3][3];
    for(int i = 0; i < 3;i++) for(int j = 0; j < 3;j++) cin >> c[i][j];
    for(int i = 0; i < 3;i++) cout << c[i][i]; cout << endl;
    return 0;
}

