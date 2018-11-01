#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S, class T> ostream& operator << (ostream& out, const pair<S, T>& o) { out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out, const vector<T> V) { for (int i = 0; i < V.size(); i++) { out << V[i]; if (i != V.size() - 1) out << " "; } return out; }
template<class T> ostream& operator << (ostream& out, const vector<vector<T> > Mat) { for (int i = 0; i < Mat.size(); i++) { if (i != 0) out << endl; out << Mat[i]; } return out; }
template<class S, class T> ostream& operator << (ostream& out, const map<S, T> mp) { out << "{ "; for (auto it = mp.begin(); it != mp.end(); it++) { out << it->first << ":" << it->second; if (mp.size() - 1 != distance(mp.begin(), it)) out << ", "; } out << " }"; return out; }

/*
 <url:https://yukicoder.me/problems/no/245>
 問題文============================================================
 =================================================================
 解説=============================================================
 よくあるぎりぎりをつめる問題
 
 すべての頂点で直線をつくり、すべての線分との交差判定を行う
 （直線状に乗っかってしまう場合があるので通常の交差判定は危険、距離を用いて判別する）
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
ostream& operator << (ostream& out, const Line& line) {
    out << "[" << line.a << "," << line.b << "]";
    return out;
}

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
bool isis_ll(Line l, Line m) { return !eq(cross(l.b - l.a, m.b - m.a), 0); }
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
bool isis_lp(Line l, Point p) { return (abs(cross(l.b - p, l.a - p)) < eps); }
// 点の線分上判定
bool isis_sp(Line s, Point p) { return (abs(s.a - p) + abs(s.b - p) - abs(s.b - s.a) < eps); }
// 垂線の足
Point proj(Line l, Point p) {
    ld t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
    return l.a + t * (l.a - l.b);
}

// 直線と点の距離
ld dist_lp(Line l, Point p) {
    return abs(p - proj(l, p));
}
// 直線と線分の距離
ld dist_ls(Line l, Line s) {
    return isis_ls(l, s) ? 0 : min(dist_lp(l, s.a), dist_lp(l, s.b));
}
int solve() {
    int res = 1;
    int N; cin >> N;
    vector<Line> lines(N);
    for (int i = 0; i < N;i++) {
        lines[i] = Line(input_point(), input_point());
    }
    for (int i = 0; i < N;i++) {
        for (int j = i + 1; j < N;j++) {
            {
                int cnt = 0;
                Line line(lines[i].a, lines[j].a);
                for (int k = 0; k < N;k++) {
                    cnt += (dist_ls(line, lines[k]) < eps);
                }
                res = max(res, cnt);
            }
            {
                int cnt = 0;
                Line line(lines[i].a, lines[j].b);
                for (int k = 0; k < N;k++) {
                    cnt += (dist_ls(line, lines[k]) < eps);
                }
                res = max(res, cnt);
            }
            {
                int cnt = 0;
                Line line(lines[i].b, lines[j].a);
                for (int k = 0; k < N;k++) {
                    cnt += (dist_ls(line, lines[k]) < eps);
                }
                res = max(res, cnt);
            }
            {
                int cnt = 0;
                Line line(lines[i].b, lines[j].b);
                for (int k = 0; k < N;k++) {
                    cnt += (dist_ls(line, lines[k]) < eps);
                }
                res = max(res, cnt);
            }
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
