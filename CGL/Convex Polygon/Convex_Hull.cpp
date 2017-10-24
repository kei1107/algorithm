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

/* 多角形 */
typedef vector<Point> Polygon;
// 凸包
Polygon convex_hull(vector<Point> ps) {
    int n = (int)ps.size();
    if(n < 3) return ps;
    sort(ps.begin(), ps.end());
    Polygon u = {ps[0], ps[1]},l = {ps[n-1],ps[n-2]};
    for(int i = 2; i < n; i++){
        for(int j = (int)u.size(); j>=2 && ccw(u[j-2],u[j-1],ps[i])>=0;j--)u.pop_back();
        u.push_back(ps[i]);
    }
    for(int i = n-3;i>=0;i--){
        for(int j = (int)l.size(); j>=2 && ccw(l[j-2],l[j-1],ps[i])>=0;j--)l.pop_back();
        l.push_back(ps[i]);
    }
    reverse(l.begin(),l.end());
    for(int i=(int)u.size()-2; i>= 1; i--)l.push_back(u[i]);
    return l;
}

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    int n; cin >> n;
    Polygon ps;
    for(int i = 0; i < n;i++) ps.emplace_back(input_point());
    Polygon ret = convex_hull(ps);
    
    /* 凸多角形の頂点で最も下にあるものの中で最も左にある頂点から順に、反時計回りで頂点座標を出力*/
    cout << ret.size() << endl;
    int idx = 0;
    for(int i = 1; i < (int)ret.size();i++){
        if( ret[idx].imag() > ret[i].imag() || (ret[idx].imag() == ret[i].imag() && ret[idx].real() > ret[i].real())){
            idx = i;
        }
    }
    for(int i = idx; i < idx + (int)ret.size();i++){
        cout << ret[i%(int)ret.size()].real() << " " << ret[i%(int)ret.size()].imag() << endl;
    }
    return 0;
}



