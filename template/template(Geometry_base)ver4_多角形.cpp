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
// 多角形の回転方向
bool is_counter_clockwise(const Polygon &poly) {
    ld angle = 0;
    int n = (int)poly.size();
    for (int i = 0;i < n;i++) {
        Point a = poly[i], b = poly[(i + 1) % n], c = poly[(i + 2) % n];
        angle += arg((c - b) / (b - a));
    }
    return angle > eps;
}
// 凸性判定
bool isConvex(const Polygon &poly){
    int n = (int)poly.size();
    if(n < 3) return false;
    int s = -3;
    for(int i = 0; i < n;i++){
        int r = ccw(poly[(i+n-1)%n],poly[i%n],poly[(i+1)%n]);
        if(r == 1 && s == -3) s = r;
        if(s*r == -1) return false;
    }
    return true;
}
// 円の内外判定
//  2 => out : 0 => on : 1 => in
int is_in_polygon(const Polygon &poly, Point p) {
    ld angle = 0;
    int n = (int)poly.size();
    for (int i = 0;i < n;i++) {
        Point a = poly[i], b = poly[(i + 1) % n];
        if (isis_sp(Line(a, b), p)) return 1;
        angle += arg((b - p) / (a - p));
    }
    return eq(angle, 0) ? 0 : 2;
}
// 凸包 : 凸多角形のある一辺上にある点も含む
Polygon convex_hull(vector<Point> ps) {
	int n = (int)ps.size();
	if (n < 3) return ps;
	sort(ps.begin(), ps.end());
	Polygon u = { ps[0], ps[1] }, l = { ps[n - 1],ps[n - 2] };
	for (int i = 2; i < n; i++) {
		for (int j = (int)u.size(); j >= 2 && ccw(u[j - 2], u[j - 1], ps[i]) >= 0;j--)u.pop_back();
		u.push_back(ps[i]);
	}
	for (int i = n - 3;i >= 0;i--) {
		for (int j = (int)l.size(); j >= 2 && ccw(l[j - 2], l[j - 1], ps[i]) >= 0;j--)l.pop_back();
		l.push_back(ps[i]);
	}
	reverse(l.begin(), l.end());
	for (int i = (int)u.size() - 2; i >= 1; i--)l.push_back(u[i]);
	return l;
}
// 凸包 : 凸多角形のある一辺上にある点を含まない
/*
Polygon convex_hull(vector<Point> ps) {
	int n = ps.size();
	int k = 0;
	sort(ps.begin(), ps.end());
	Polygon ch(2 * n);
	for (int i = 0; i < n; ch[k++] = ps[i++])
		while (k >= 2 && ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0) --k;
	for (int i = n - 2, t = k + 1; i >= 0; ch[k++] = ps[i--])
		while (k >= t && ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0) --k;
	ch.resize(k - 1);
	return ch;
}
*/
// 凸多角形の直径
ld convex_diameter(const Polygon& poly){
    int n = (int)poly.size();
    int ii = 0, jj = 0;
    for(int i = 1;i < n;i++){
        if(poly[i].imag() > poly[ii].imag())ii = i;
        if(poly[i].imag() < poly[jj].imag())jj = i;
    }
    ld res = abs(poly[ii] - poly[jj]);
    
    int i, maxi,j,maxj;
    i = maxi = ii; j = maxj = jj;
    do{
        if(cross(poly[(i+1)%n] - poly[i],poly[(j+1)%n] - poly[j]) >= 0) j = (j+1)%n;
        else i = (i+1)%n;
        if(abs(poly[i] - poly[j]) > res){
            res = abs(poly[i] - poly[j]);
            maxi = i; maxj = j;
        }
    }while(i != ii || j != jj);
    return res;
}
// 凸カット
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
    return 0;
}


