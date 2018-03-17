#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://cf16-exhibition-final-open.contest.atcoder.jp/tasks/cf16_exhibition_final_b>
問題文============================================================
 すぬけ君は、誕生日プレゼントに三角形をもらいました。
 三頂点の座標は (x1,y1), (x2,y2), (x3,y3) でした。
 
 すぬけ君は、三角形の内部に半径の等しい二つの円を、重ならないように描きたいです (二円が点で接していてもいいです)。
 円の半径の最大値を求めてください。

=================================================================

解説=============================================================

 色々計算すると
 三角形の各辺の長さを a,b,c
 内接円の半径を r
 M := max(a,b,c)
 とすると
 
 M(2+M/r)) が答え
 
 
 三角形の内部で辺に接するように　半径 x の円を描いた時、その円の中心の軌跡をたどると
 内部に三角形と相似になる　小さい　三角形ができる
 この時、その小さな三角形の二点を用いて 2x 以上の長さとなるようであれば 半径 x の円を二つ描くことができる
 あとは、それをギリギリまで詰めると　↑の式が出てくる
================================================================
*/

typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-9, pi = acos(-1.0);
namespace std {
    bool operator<(const Point &lhs, const Point &rhs) {
        if (lhs.real() < rhs.real() - eps) return true;
        if (lhs.real() > rhs.real() + eps) return false;
        return lhs.imag() < rhs.imag();
    }
}
Point input_point() { ld x, y; cin >> x >> y; return Point(x, y); } // 点の入力
bool eq(ld a, ld b) { return (abs(a - b) < eps); } // 誤差つき等号判定
ld dot(Point a, Point b) { return real(conj(a) * b); } // 内積
ld cross(Point a, Point b) { return imag(conj(a) * b); } // 外積

ld solve(){
    Point p1 = input_point(), p2 = input_point(), p3 = input_point();
    ld a = abs(p1-p2), b = abs(p2-p3), c = abs(p3-p1);
    ld S = abs(cross(p2-p1,p3-p1)/2);
    ld r = 2*S/(a+b+c);
    ld M = max({a,b,c});
    ld ret = M/(2+M/r);
    return ret;
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    cout << fixed << setprecision(15) << solve() << endl;
	return 0;
}
