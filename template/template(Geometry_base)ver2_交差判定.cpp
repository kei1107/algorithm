#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

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
Point input_point() {ld x, y; cin >> x >> y; return Point(x, y);} // 点の入力
bool eq(ld a, ld b) {return (abs(a - b) < eps);} // 誤差つき等号判定
ld dot(Point a, Point b) {return real(conj(a) * b);} // 内積
ld cross(Point a, Point b) {return imag(conj(a) * b);} // 外積

// 直線の定義
class Line {
public:
    Point a, b;
    Line() : a(Point(0, 0)), b(Point(0, 0)) {}
    Line(Point a, Point b) : a(a), b(b) {}
    Point operator[](const int _num) {
        if (_num == 0)return a;
        else if (_num == 1)return b;
        else assert(false);
    }
};

// 円の定義
class Circle {
public:
    Point p;
    ld r;
    Circle() : p(Point(0, 0)), r(0) {}
    Circle(Point p, ld r) : p(p), r(r) {}
};

// CCW
int ccw(Point a, Point b, Point c) {
    b -= a; c -= a;
    if (cross(b, c) > eps) return 1;   // a,b,cが反時計周りの順に並ぶ
    if (cross(b, c) < -eps) return -1; // a,b,cが時計周りの順に並ぶ
    if (dot(b, c) < 0) return 2;       // c,a,bの順に直線に並ぶ
    if (norm(b) < norm(c)) return -2;  // a,b,cの順に直線に並ぶ
    return 0;                          // a,c,bの順に直線に並ぶ
}

/* 交差判定 */
// 直線と直線の交差判定
bool isis_ll(Line l, Line m) {return !eq(cross(l.b - l.a, m.b - m.a), 0);}
// 直線と線分の交差判定
bool isis_ls(Line l, Line s) {
    return isis_ll(l, s) &&
    (cross(l.b - l.a, s.a - l.a) * cross(l.b - l.a, s.b - l.a) < eps);
}
// 線分と線分の交差判定
bool isis_ss(Line s, Line t) {
    return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 &&
    ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;
}
// 点の直線上判定
bool isis_lp(Line l, Point p) {return (abs(cross(l.b - p, l.a - p)) < eps);}
// 点の線分上判定
bool isis_sp(Line s, Point p) {return (abs(s.a - p) + abs(s.b - p) - abs(s.b - s.a) < eps);}


int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    return 0;
}


