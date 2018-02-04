#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <bitset>
#include <iostream>
#include <iomanip>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <numeric>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <deque>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e16;

/*
<url:>
問題文============================================================

=================================================================

解説=============================================================
http://inazz.jp/pku/1418/
================================================================
*/

typedef double ld;
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

ld change(ld r){
    while(r<0.0) r+= 2*pi;
    while(r>=2*pi) r-= 2*pi;
    return r;
}

int hit(Point p,vector<Point>& ps,vector<ld>& rs){
    for(int i = (int)rs.size()-1; i>= 0; i--) if(abs(ps[i]-p)<rs[i]) return i;
    return -1;
}

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    int n;
    while(cin >> n){
        if(n == 0) break;
        vector<Point> ps;
        vector<ld> rs;
        for(int i = 0; i < n;i++){
            ld x,y,r; cin >> x >> y >> r;
            ps.push_back(Point(x,y)); rs.push_back(r);
        }
        vector<bool> visible(n,false);
        for(int i = 0; i < n;i++){
            vector<ld> radius;
            radius.push_back(0.0);
            radius.push_back(2.0*pi);
            for(int j = 0; j < n;j++){
                ld a = rs[i], b = abs(ps[j] - ps[i]), c = rs[j];
                if(a+b<c || a+c<b || b+c<a)continue;
                double d = arg(ps[j]-ps[i]), e = acos((a*a+b*b-c*c)/(2*a*b));
                radius.push_back(change(d+e)); radius.push_back(change(d-e));
            }
            sort(radius.begin(),radius.end());
            for(int j = 0; j < (int)radius.size()-1;j++){
                ld rad = (radius[j+1]+radius[j])/2.0, diff = 4e-13;
                for(int k = -1; k<= 1;k+=2){
                    int tmp = hit(Point(ps[i].real()+(rs[i]+diff*k)*cos(rad),ps[i].imag()+(rs[i]+diff*k)*sin(rad)),ps,rs);
                    if(tmp==-1)continue;
                    visible[tmp]=true;
                }
            }
        }
        int res = 0;
        for(int i = 0; i < n;i++) if(visible[i]) res++;
        cout << res << endl;
    }
	return 0;
}
