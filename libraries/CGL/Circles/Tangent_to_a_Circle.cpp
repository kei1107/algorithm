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
Point input_point() { ld x, y; cin >> x >> y; return Point(x, y); } // �_�̓���
bool eq(ld a, ld b) { return (abs(a - b) < eps); } // �덷����������
ld dot(Point a, Point b) { return real(conj(a) * b); } // ����
ld cross(Point a, Point b) { return imag(conj(a) * b); } // �O��

														 // �����̒�`
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

// �~�̒�`
class Circle {
public:
	Point p;
	ld r;
	Circle() : p(Point(0, 0)), r(0) {}
	Circle(Point p, ld r) : p(p), r(r) {}
};

// �����̑�
Point proj(Line l, Point p) {
	ld t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
	return l.a + t * (l.a - l.b);
}

// CCW
int ccw(Point a, Point b, Point c) {
	b -= a; c -= a;
	if (cross(b, c) > eps) return 1;   // a,b,c�������v����̏��ɕ���
	if (cross(b, c) < -eps) return -1; // a,b,c�����v����̏��ɕ���
	if (dot(b, c) < 0) return 2;       // c,a,b�̏��ɒ����ɕ���
	if (norm(b) < norm(c)) return -2;  // a,b,c�̏��ɒ����ɕ���
	return 0;                          // a,c,b�̏��ɒ����ɕ���
}

/* �������� */
// �����ƒ����̌�������
bool isis_ll(Line l, Line m) { return !eq(cross(l.b - l.a, m.b - m.a), 0); }
// �����Ɛ����̌�������
bool isis_ls(Line l, Line s) {
	return isis_ll(l, s) &&
		(cross(l.b - l.a, s.a - l.a) * cross(l.b - l.a, s.b - l.a) < eps);
}
// �����Ɛ����̌�������
bool isis_ss(Line s, Line t) {
	return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 &&
		ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;
}
// �_�̒����㔻��
bool isis_lp(Line l, Point p) { return (abs(cross(l.b - p, l.a - p)) < eps); }
// �_�̐����㔻��
bool isis_sp(Line s, Point p) { return (abs(s.a - p) + abs(s.b - p) - abs(s.b - s.a) < eps); }

/* ���� */
// �����ƒ����̌�_
Point is_ll(Line s, Line t) {
	Point sv = s.b - s.a, tv = t.b - t.a;
	assert(cross(sv, tv) != 0);
	return s.a + sv * cross(tv, t.a - s.a) / cross(tv, sv);
}

// �����Ɠ_�̋���
ld dist_lp(Line l, Point p) {
	return abs(p - proj(l, p));
}

// �����ƒ����̋���
ld dist_ll(Line l, Line m) {
	return isis_ll(l, m) ? 0 : dist_lp(l, m.a);
}

// �����Ɛ����̋���
ld dist_ls(Line l, Line s) {
	return isis_ls(l, s) ? 0 : min(dist_lp(l, s.a), dist_lp(l, s.b));
}

// �����Ɠ_�̋���
ld dist_sp(Line s, Point p) {
	Point r = proj(s, p);
	return isis_sp(s, r) ? abs(r - p) : min(abs(s.a - p), abs(s.b - p));
}

// �����Ɛ����̋���
ld dist_ss(Line s, Line t) {
	if (isis_ss(s, t)) return 0;
	return min({ dist_sp(s, t.a), dist_sp(s, t.b), dist_sp(t, s.a), dist_sp(t, s.b) });
}


// �~�ƒ����̌�_
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

// �~�Ɠ_�̐ڐ�
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

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	Point p, cp; ld r;
	p = input_point(); cp = input_point(); cin >> r;
	Circle c(cp, r);

	auto ls = tangent_cp(c, p);
	vector<Point> ps;
	auto p1 = is_lc(c, ls[0]), p2 = is_lc(c, ls[1]);
	ps.push_back(p1[0]); ps.push_back(p2[0]);

	sort(ps.begin(), ps.end());
	cout << fixed << setprecision(10);

	for (int i = 0; i < 2;i++) {
		cout << ps[i].real() << " " << ps[i].imag() << endl;
	}
	return 0;
}