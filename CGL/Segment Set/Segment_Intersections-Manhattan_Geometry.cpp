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
Point input_point() { ld x, y; cin >> x >> y; return Point(x, y); } // 点の入力
bool eq(ld a, ld b) { return (abs(a - b) < eps); } // 誤差つき等号判定
ld dot(Point a, Point b) { return real(conj(a) * b); } // 内積
ld cross(Point a, Point b) { return imag(conj(a) * b); } // 外積

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

/* 線分交差(マンハッタン幾何) */
// 短点の種類
#define BOTTOM 0
#define LEFT 1
#define RIGHT 2
#define TOP 3

class EndPoint {
public:
	Point p;
	ll seg, st; // 入力線分のID, 端点の種類
	EndPoint() {}
	EndPoint(Point p, ll seg, ll st) :p(p), seg(seg), st(st) {}
	
	bool operator < (const EndPoint& ep) const {
		// y 座標が小さい順に整列
		if (p.imag() == ep.p.imag()) {
			return st < ep.st; // y が同一の場合は, 下端点, 左端点, 右端点, 上端点の順に並べる
		}
		else return p.imag() < ep.p.imag();
	}
};

vector<EndPoint> EP;
// 線分交差問題: マンハッタン幾何
ll manhattanIntersection(vector<Line> S) {
	ll n = S.size();

	for (int i = 0, k = 0; i < n;i++) {
		// 端点 p1, p2 が左下を基準に並ぶように調整
		if (S[i].a.imag() == S[i].b.imag()) {
			if (S[i].a.real() > S[i].b.real()) swap(S[i].a, S[i].b);
		}
		else if (S[i].a.imag() > S[i].b.imag()) swap(S[i].a, S[i].b);

		if (S[i].a.imag() == S[i].b.imag()) {	// 水平線分を端点リストに追加
			EP[k++] = EndPoint(S[i].a, i, LEFT);
			EP[k++] = EndPoint(S[i].b, i, RIGHT);
		}
		else {									// 垂直線分を端点リストに追加
			EP[k++] = EndPoint(S[i].a, i, BOTTOM);
			EP[k++] = EndPoint(S[i].b, i, TOP);
		}
	}
	sort(EP.begin(), EP.end()); // 端点の y 座標に関して昇順に整列

	set<ll> BT; // 二分探索木
	BT.insert(INF); // 番兵を設置
	ll cnt = 0;

	for (int i = 0; i < 2 * n;i++) {
		if (EP[i].st == TOP) {
			BT.erase(EP[i].p.real()); // 上端点を削除
		}
		else if (EP[i].st == BOTTOM) {
			BT.insert(EP[i].p.real()); // 下端点を追加
		}
		else if (EP[i].st == LEFT) {
			auto b = lower_bound(BT.begin(), BT.end(), S[EP[i].seg].a.real()); // O(log n)
			auto e = upper_bound(BT.begin(), BT.end(), S[EP[i].seg].b.real()); // O(log n)
			cnt += distance(b, e); // b と e の距離(点の数)を加算, O(k)
		}
	}
	return cnt;
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	ll n; cin >> n;
	EP.resize(2 * n);
	vector<Line> S;
	for (int i = 0; i < n;i++) {
		Point a = input_point(), b = input_point();
		S.push_back(Line(a, b));
	}
	cout << manhattanIntersection(S) << endl;
	return 0;
}