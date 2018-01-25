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


typedef vector<Point> Polygon;
/* 最近接点対 : 分割統治法 */
bool compY (const Point& a,const Point& b){return a.imag() != b.imag() ? a.imag() < b.imag() : a.real() < b.real();}
ld ClosestPair(int l, int r,const Polygon& poly){
    if(r-l<2)return 1e16;
    int m = (l+r)/2;
    ld res = min(ClosestPair(l, m, poly),ClosestPair(m, r, poly));
    Polygon v;
    for(int i = l; i < r;i++){
        if(abs(poly[i].real() - poly[m].real()) < res)v.push_back(poly[i]);
    }
    
    sort(v.begin(),v.end(),compY);
    
    for(int i = 0; i < (int)v.size();i++){
        for(int j = max(0,i - 10);j < i;j++){
            res = min(res,abs(v[i]-v[j]));
        }
    }
    return res;
}

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    int n ;cin >> n;
    Polygon ps;
    for(int i = 0;i < n;i++) ps.emplace_back(input_point());
    sort(ps.begin(),ps.end());
    cout << fixed << setprecision(20) << ClosestPair(0, n, ps) << endl;
    return 0;
}
