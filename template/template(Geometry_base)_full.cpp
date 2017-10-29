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
Point input_point() { ld x, y; cin >> x >> y; return Point(x, y); } // “_‚Ì“ü—Í
bool eq(ld a, ld b) { return (abs(a - b) < eps); } // Œë·‚Â‚«“™†”»’è
ld dot(Point a, Point b) { return real(conj(a) * b); } // “àÏ
ld cross(Point a, Point b) { return imag(conj(a) * b); } // ŠOÏ

// ’¼ü‚Ì’è‹`
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

// ‰~‚Ì’è‹`
class Circle {
public:
	Point p;
	ld r;
	Circle() : p(Point(0, 0)), r(0) {}
	Circle(Point p, ld r) : p(p), r(r) {}
};

// ‚ü‚Ì‘«
Point proj(Line l, Point p) {
	ld t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
	return l.a + t * (l.a - l.b);
}

// CCW
int ccw(Point a, Point b, Point c) {
	b -= a; c -= a;
	if (cross(b, c) > eps) return 1;   // a,b,c‚ª”½Œvü‚è‚Ì‡‚É•À‚Ô
	if (cross(b, c) < -eps) return -1; // a,b,c‚ªŒvü‚è‚Ì‡‚É•À‚Ô
	if (dot(b, c) < 0) return 2;       // c,a,b‚Ì‡‚É’¼ü‚É•À‚Ô
	if (norm(b) < norm(c)) return -2;  // a,b,c‚Ì‡‚É’¼ü‚É•À‚Ô
	return 0;                          // a,c,b‚Ì‡‚É’¼ü‚É•À‚Ô
}

/* Œğ·”»’è */
// ’¼ü‚Æ’¼ü‚ÌŒğ·”»’è
bool isis_ll(Line l, Line m) { return !eq(cross(l.b - l.a, m.b - m.a), 0); }
// ’¼ü‚Æü•ª‚ÌŒğ·”»’è
bool isis_ls(Line l, Line s) {
	return isis_ll(l, s) &&
		(cross(l.b - l.a, s.a - l.a) * cross(l.b - l.a, s.b - l.a) < eps);
}
// ü•ª‚Æü•ª‚ÌŒğ·”»’è
bool isis_ss(Line s, Line t) {
	return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 &&
		ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;
}
// “_‚Ì’¼üã”»’è
bool isis_lp(Line l, Point p) { return (abs(cross(l.b - p, l.a - p)) < eps); }
// “_‚Ìü•ªã”»’è
bool isis_sp(Line s, Point p) { return (abs(s.a - p) + abs(s.b - p) - abs(s.b - s.a) < eps); }

/* ‹——£ */
// ’¼ü‚Æ’¼ü‚ÌŒğ“_
Point is_ll(Line s, Line t) {
	Point sv = s.b - s.a, tv = t.b - t.a;
	assert(cross(sv, tv) != 0);
	return s.a + sv * cross(tv, t.a - s.a) / cross(tv, sv);
}

// ’¼ü‚Æ“_‚Ì‹——£
ld dist_lp(Line l, Point p) {
	return abs(p - proj(l, p));
}

// ’¼ü‚Æ’¼ü‚Ì‹——£
ld dist_ll(Line l, Line m) {
	return isis_ll(l, m) ? 0 : dist_lp(l, m.a);
}

// ’¼ü‚Æü•ª‚Ì‹——£
ld dist_ls(Line l, Line s) {
	return isis_ls(l, s) ? 0 : min(dist_lp(l, s.a), dist_lp(l, s.b));
}

// ü•ª‚Æ“_‚Ì‹——£
ld dist_sp(Line s, Point p) {
	Point r = proj(s, p);
	return isis_sp(s, r) ? abs(r - p) : min(abs(s.a - p), abs(s.b - p));
}

// ü•ª‚Æü•ª‚Ì‹——£
ld dist_ss(Line s, Line t) {
	if (isis_ss(s, t)) return 0;
	return min({ dist_sp(s, t.a), dist_sp(s, t.b), dist_sp(t, s.a), dist_sp(t, s.b) });
}

/* ‰~ */
// ‰~‚Æ‰~‚ÌŒğ“_
vector<Point> is_cc(Circle c1, Circle c2) {
	vector<Point> res;
	ld d = abs(c1.p - c2.p);
	ld rc = (d * d + c1.r * c1.r - c2.r * c2.r) / (2 * d);
	ld dfr = c1.r * c1.r - rc * rc;
	if (abs(dfr) < eps) dfr = 0.0;
	else if (dfr < 0.0) return res; // no intersection
	ld rs = sqrt(dfr);
	Point diff = (c2.p - c1.p) / d;
	res.push_back(c1.p + diff * Point(rc, rs));
	if (dfr != 0.0) res.push_back(c1.p + diff * Point(rc, -rs));
	return res;
}
// ‰~‚Æ’¼ü‚ÌŒğ“_
vector<Point> is_lc(Circle c, Line l) {
	vector<Point> res;
	ld d = dist_lp(l, c.p);
	if (d < c.r + eps) {
		ld len = (d > c.r) ? 0.0 : sqrt(c.r * c.r - d * d); //safety;
		Point nor = (l.a - l.b) / abs(l.a - l.b);
		res.push_back(proj(l, c.p) + len * nor);
		res.push_back(proj(l, c.p) - len * nor);
	}
	return res;
}
// ‰~‚Æü•ª‚Ì‹——£
vector<Point> is_sc(Circle c, Line l) {
	vector<Point> v = is_lc(c, l), res;
	for (Point p : v)
		if (isis_sp(l, p)) res.push_back(p);
	return res;
}
// ‰~‚Æ“_‚ÌÚü
vector<Line> tangent_cp(Circle c, Point p) {
	vector<Line> ret;
	Point v = c.p - p;
	ld d = abs(v);
	ld l = sqrt(norm(v) - c.r * c.r);
	if (isnan(l)) { return ret; }
	Point v1 = v * Point(l / d, c.r / d);
	Point v2 = v * Point(l / d, -c.r / d);
	ret.push_back(Line(p, p + v1));
	if (l < eps) return ret;
	ret.push_back(Line(p, p + v2));
	return ret;
}
// ‰~‚Æ‰~‚ÌÚü
vector<Line> tangent_cc(Circle c1, Circle c2) {
	vector<Line> ret;
	if (abs(c1.p - c2.p) - (c1.r + c2.r) > -eps) {
		Point center = (c1.p * c2.r + c2.p * c1.r) / (c1.r + c2.r);
		ret = tangent_cp(c1, center);
	}
	if (abs(c1.r - c2.r) > eps) {
		Point out = (-c1.p * c2.r + c2.p * c1.r) / (c1.r - c2.r);
		vector<Line> nret = tangent_cp(c1, out);
		ret.insert(ret.end(), nret.begin(), nret.end());
	}
	else {
		Point v = c2.p - c1.p;
		v /= abs(v);
		Point q1 = c1.p + v * Point(0, 1) * c1.r;
		Point q2 = c1.p + v * Point(0, -1) * c1.r;
		ret.push_back(Line(q1, q1 + v));
		ret.push_back(Line(q2, q2 + v));
	}
	return ret;
}

/* ‘½ŠpŒ` */
typedef vector<Point> Polygon;
// –ÊÏ
ld area(const Polygon &p) {
    ld res = 0;
    int n = (int)p.size();
    for (int j = 0;j < n;j++) res += cross(p[j], p[(j + 1) % n]);
    return res / 2;
}
// ‘½ŠpŒ`‚Ì‰ñ“]•ûŒü
bool is_counter_clockwise(const Polygon &poly) {
    ld angle = 0;
    int n = (int)poly.size();
    for (int i = 0;i < n;i++) {
        Point a = poly[i], b = poly[(i + 1) % n], c = poly[(i + 2) % n];
        angle += arg((c - b) / (b - a));
    }
    return angle > eps;
}
// “Ê«”»’è
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
// ‰~‚Ì“àŠO”»’è
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
// “Ê•ï : “Ê‘½ŠpŒ`‚Ì‚ ‚éˆê•Óã‚É‚ ‚é“_‚àŠÜ‚Ş
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
// “Ê•ï : “Ê‘½ŠpŒ`‚Ì‚ ‚éˆê•Óã‚É‚ ‚é“_‚ğŠÜ‚Ü‚È‚¢
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
// “Ê‘½ŠpŒ`‚Ì’¼Œa
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
// “ÊƒJƒbƒg
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

// ‰~‚Æ‘½ŠpŒ`‚Ì‹¤’Ê•”•ª
double area_of_polygon_and_circle(const Polygon& poly, const Circle c) {
	int n = (int)poly.size();
	ld r = 0;
	for (int i = n - 1, j = 0; j < n; i=j++) {
		Point v = abs(poly[j] - poly[i]) / (poly[j] - poly[i]);
		if (poly[j] == poly[i])continue;
		assert(poly[j] != poly[i]);
		Point a = (poly[i] - c.p)*v, b = (poly[j] - c.p)*v;
		ld d = norm(c.r) - norm(a.imag());
		if (abs(a.imag()) < eps) continue;
		if (d < 0)d = 0;
		d = sqrt(d);
		double l, m;
		r += norm(c.r)*((l = atan2(b.imag(), min(b.real(), -d)) - atan2(a.imag(), min(a.real(), -d)))
			+ (m = atan2(b.imag(), max(b.real(), d)) - atan2(a.imag(), max(a.real(), d))))
			+ a.imag()*(min(d, max(a.real(), -d)) - max(-d, min(b.real(), d)));
		assert(-pi < l && -pi < m && l < pi && m < pi);
	}
	return r / 2;
}

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);

	return 0;
}