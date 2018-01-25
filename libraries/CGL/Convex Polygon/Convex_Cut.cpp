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

// 垂線の足
Point proj(Line l, Point p) {
    ld t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
    return l.a + t * (l.a - l.b);
}

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

/* 距離 */
// 直線と直線の交点
Point is_ll(Line s, Line t) {
    Point sv = s.b - s.a, tv = t.b - t.a;
    assert(cross(sv, tv) != 0);
    return s.a + sv * cross(tv, t.a - s.a) / cross(tv, sv);
}

// 直線と点の距離
ld dist_lp(Line l, Point p) {
    return abs(p - proj(l, p));
}

// 直線と直線の距離
ld dist_ll(Line l, Line m) {
    return isis_ll(l, m) ? 0 : dist_lp(l, m.a);
}

// 直線と線分の距離
ld dist_ls(Line l, Line s) {
    return isis_ls(l, s) ? 0 : min(dist_lp(l, s.a), dist_lp(l, s.b));
}

// 線分と点の距離
ld dist_sp(Line s, Point p) {
    Point r = proj(s, p);
    return isis_sp(s, r) ? abs(r - p) : min(abs(s.a - p), abs(s.b - p));
}

// 線分と線分の距離
ld dist_ss(Line s, Line t) {
    if (isis_ss(s, t)) return 0;
    return min({ dist_sp(s, t.a), dist_sp(s, t.b), dist_sp(t, s.a), dist_sp(t, s.b) });
}

/* 多角形 */
typedef vector<Point> Polygon;
// 面積
ld area(const Polygon &p) {
    ld res = 0;
    int n = (int)p.size();
    for (int j = 0;j < n;j++) res += cross(p[j], p[(j + 1) % n]);
    return res / 2;
}
// 凸カット カットした左側の多角形を返却
Polygon convex_cut(const Polygon &ps, Line l) {
    int n = (int)ps.size();
    Polygon Q;
    for (int i = 0;i < n;i++) {
        Point A = ps[i], B = ps[(i + 1) % n];
        Line m = Line(A, B);
        if (ccw(l.a, l.b, A) != -1) Q.push_back(A);
        if (ccw(l.a, l.b, A) * ccw(l.a, l.b, B) < 0 && isis_ll(l, m))
            Q.push_back(is_ll(l, m));
    }
    return Q;
}

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    int n; cin >> n;
    Polygon ps;
    for(int i = 0; i < n;i++) ps.emplace_back(input_point());
    int q; cin >> q;
    for(int i = 0; i < q;i++){
        /* 各入力(直線)で凸カットした左側の多角形の面積を出力*/
        Point p1 = input_point(), p2 = input_point();
        Line l(p1,p2);
        ld res = area(convex_cut(ps, l));
        cout << fixed << setprecision(10) << res << endl;
    }
    return 0;
}
