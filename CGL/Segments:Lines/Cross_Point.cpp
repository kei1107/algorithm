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

// 直線と直線の交点
Point is_ll(Line s, Line t) {
    Point sv = s.b - s.a, tv = t.b - t.a;
    assert(cross(sv, tv) != 0);
    return s.a + sv * cross(tv, t.a - s.a) / cross(tv, sv);
}

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    int q; cin >> q;
    for(int i = 0;i<q;i++){
        Line s1(input_point(),input_point()), s2(input_point(),input_point());
        Point ret = is_ll(s1,s2);
        cout << fixed << setprecision(10) << ret.real() << " " << ret.imag() << endl;
    }
    return 0;
}



