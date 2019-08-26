#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T>& V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> >& Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T>& mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }
template<typename T>vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}
/*
 <url:https://onlinejudge.u-aizu.ac.jp/challenges/sources/JOI/Prelim/0585?year=2006>
 問題文============================================================
 =================================================================
 解説=============================================================
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
ll ClosestPair(int l, int r,const Polygon& poly){
    if(r-l<2)return 1e16;
    int m = (l+r)/2;
    ll res = min(ClosestPair(l, m, poly),ClosestPair(m, r, poly));
    Polygon v;
    for(int i = l; i < r;i++){
        if(abs(poly[i].real() - poly[m].real()) < res)v.push_back(poly[i]);
    }
    
    sort(v.begin(),v.end(),compY);
    
    auto calc = [](Point l,Point r){
        ll x1,x2,y1,y2;
        x1 = l.real(); y1 = l.imag();
        x2 = r.real(); y2 = r.imag();
        
        return (x1-x2)* (x1-x2) + (y1-y2)*(y1-y2);
    };
    for(int i = 0; i < (int)v.size();i++){
        for(int j = max(0,i - 10);j < i;j++){
            res = min(res,calc(v[i],v[j]));
        }
    }
    return res;
}
template<class Type>
Type solve(Type res = Type()){
    int n ;cin >> n;
    Polygon ps;
    for(int i = 0;i < n;i++) ps.emplace_back(input_point());
    sort(ps.begin(),ps.end());
    res =  ClosestPair(0, n, ps);
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
