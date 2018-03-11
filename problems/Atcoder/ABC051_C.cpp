#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://abc051.contest.atcoder.jp/tasks/abc051_c>
問題文============================================================
 イルカは x 軸正方向を右、y 軸正方向を上とする 2 次元座標平面にいます。
 イルカは現在点 (sx,sy) にいて、1 秒あたり上下左右に距離 1 だけ進むことができます。
 このとき、移動前と移動後の x 座標、y 座標はともに整数でなければなりません。
 イルカはここから sx<tx と sy<ty を満たす点 (tx,ty) に行き、その後点 (sx,sy) に戻り、また点 (tx,ty) に行き、その後点 (sx,sy) に戻ります。
 このとき、イルカは点 (sx,sy) と点 (tx,ty) を除いて、途中で同じ座標を複数回通らないように移動しなければなりません。
 このような条件を満たすイルカの最短経路を 1 つ求めてください。
=================================================================

解説=============================================================
気合い
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    int sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
    string S;
    int dx = tx - sx;
    int dy = ty - sy;
    
    for (int i = 0; i < dy;i++) {
        S += "U";
    }
    for (int i = 0; i < dx; i++) {
        S += "R";
    }
    for (int i = 0; i < dy;i++) {
        S += "D";
    }
    for (int i = 0; i <= dx; i++) {
        S += "L";
    }
    for (int i = 0; i <= dy;i++) {
        S += "U";
    }
    for (int i = 0; i <= dx; i++) {
        S += "R";
    }
    S += "D";
    S += "R";
    for (int i = 0; i <= dy;i++) {
        S += "D";
    }
    for (int i = 0; i <= dx; i++) {
        S += "L";
    }
    S += "U";
    
    cout << S << endl;
	return 0;
}
