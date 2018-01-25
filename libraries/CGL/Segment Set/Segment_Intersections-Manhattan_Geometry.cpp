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

/* ��������(�}���n�b�^����) */
// �Z�_�̎��
#define BOTTOM 0
#define LEFT 1
#define RIGHT 2
#define TOP 3

class EndPoint {
public:
	Point p;
	ll seg, st; // ���͐�����ID, �[�_�̎��
	EndPoint() {}
	EndPoint(Point p, ll seg, ll st) :p(p), seg(seg), st(st) {}
	
	bool operator < (const EndPoint& ep) const {
		// y ���W�����������ɐ���
		if (p.imag() == ep.p.imag()) {
			return st < ep.st; // y ������̏ꍇ��, ���[�_, ���[�_, �E�[�_, ��[�_�̏��ɕ��ׂ�
		}
		else return p.imag() < ep.p.imag();
	}
};

vector<EndPoint> EP;
// �����������: �}���n�b�^����
ll manhattanIntersection(vector<Line> S) {
	ll n = S.size();

	for (int i = 0, k = 0; i < n;i++) {
		// �[�_ p1, p2 ����������ɕ��Ԃ悤�ɒ���
		if (S[i].a.imag() == S[i].b.imag()) {
			if (S[i].a.real() > S[i].b.real()) swap(S[i].a, S[i].b);
		}
		else if (S[i].a.imag() > S[i].b.imag()) swap(S[i].a, S[i].b);

		if (S[i].a.imag() == S[i].b.imag()) {	// ����������[�_���X�g�ɒǉ�
			EP[k++] = EndPoint(S[i].a, i, LEFT);
			EP[k++] = EndPoint(S[i].b, i, RIGHT);
		}
		else {									// ����������[�_���X�g�ɒǉ�
			EP[k++] = EndPoint(S[i].a, i, BOTTOM);
			EP[k++] = EndPoint(S[i].b, i, TOP);
		}
	}
	sort(EP.begin(), EP.end()); // �[�_�� y ���W�Ɋւ��ď����ɐ���

	set<ll> BT; // �񕪒T����
	BT.insert(INF); // �ԕ���ݒu
	ll cnt = 0;

	for (int i = 0; i < 2 * n;i++) {
		if (EP[i].st == TOP) {
			BT.erase(EP[i].p.real()); // ��[�_���폜
		}
		else if (EP[i].st == BOTTOM) {
			BT.insert(EP[i].p.real()); // ���[�_��ǉ�
		}
		else if (EP[i].st == LEFT) {
			auto b = lower_bound(BT.begin(), BT.end(), S[EP[i].seg].a.real()); // O(log n)
			auto e = upper_bound(BT.begin(), BT.end(), S[EP[i].seg].b.real()); // O(log n)
			cnt += distance(b, e); // b �� e �̋���(�_�̐�)�����Z, O(k)
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