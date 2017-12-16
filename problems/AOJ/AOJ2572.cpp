#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2572>
 問題文============================================================
 長方形領域と、二つの円の面積、二つの円の共通面積が与えられる

 長方形領域内で与えられた条件を満たす配置がある場合、その円の座標を出力
 =================================================================
 解説=============================================================

 共通面積を得られる円配置はにぶたんで求まる

 その後、大きい方の円を長方形領域の隅に配置して、上で求まった配置で満たす場所が
 あるかどうか180度回してみていけば良い
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
Point input_point() {ld x, y; cin >> x >> y; return Point(x, y);} // 点の入力
bool eq(ld a, ld b) {return (abs(a - b) < eps);} // 誤差つき等号判定
ld dot(Point a, Point b) {return real(conj(a) * b);} // 内積
ld cross(Point a, Point b) {return imag(conj(a) * b);} // 外積

ll W,H,A,B,S;
ld ra,rb;
ld check(ld theta){
    ld res = 0.0;

    ld x = ra * cos(theta/2), y = ra*sin(theta/2);

    ld x2 = sqrt(rb*rb - y*y);
    ld ox = x2 + x;

    ld theta2 = 2 * asin(y/rb);

    ld SAB = 0.5 * ra * ra * sin(theta) + 0.5 * rb * rb * sin(theta2);

    ld S1 = pi * ra * ra * theta / (2*pi);
    ld S2 = pi * rb * rb * theta2 / (2*pi);

    res = S1 + S2 - SAB;
    return res;
}

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    while(cin >> W >> H >> A >> B >> S, W|H|A|B|S){
        bool f = false;
        if(A > B) {
            swap(A,B);
            f = true;
        }
        ra = sqrt(A/pi);
        rb = sqrt(B/pi);
        ld l = 0, r = 2*pi;
        for(int i = 0; i < 300; i++){
            ld m = (l + r)/2.0;
            ld area = check(m);
            if(area > S){
                r = m;
            }else{
                l = m;
            }
        }
        ld theta = r;

        ld XA,YA,XB,YB;

        XB = rb + 0.0001; YB = rb + 0.0001;

        if(XB + rb > (ld)W + 0.0001 || (YB + rb) > (ld)H + 0.0001){
            cout << "impossible" <<endl;
            continue;
        }

        ld x = ra * cos(theta/2), y = ra*sin(theta/2);
        ld x2 = sqrt(rb*rb - y*y);
        ld ox = x2 + x;

        bool f2 = false;
        for(ld T = 0.0; T < pi + eps; T += 0.0001){
            ld X = XB + ox * cos(T);
            ld Y = YB + ox *sin(T);
            if(((X + ra) < (ld)W + 0.0001) && ((X - ra) > -0.0001)){
                if(((Y + ra) < (ld)H + 0.0001) && ((Y - ra) > -0.0001)){
                    XA = X; YA = Y;
                    f2 = true;
                    break;
                }
            }
        }
        if(!f2){
            cout << "impossible" << endl;
            continue;
        }
        if(f){
            swap(XA,XB);
            swap(YA,YB);
            swap(ra,rb);
        }
        cout << fixed << setprecision(10) << XA << " " << YA << " " << ra << " " << XB << " " << YB << " " << rb << endl;
    }
    return 0;
}
