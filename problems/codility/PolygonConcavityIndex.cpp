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

// 凸包 : 凸多角形のある一辺上にある点も含む
Polygon convex_hull2(vector<Point> ps) {
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
//struct Point2D{
//    int x;
//    int y;
//    Point2D(int x,int y):x(x),y(y){}
//};
int solution(vector<Point2D> &A){
    Polygon ps;
    int N = (int)A.size();
    for(auto p:A){
        ps.push_back(Point(p.x,p.y));
    }
    auto CH = convex_hull2(ps);
    if(CH.size() == ps.size()) return -1;
    set<Point> st;
    for(auto p:CH){
        st.insert(p);
    }

    for(int i = 0; i < N;i++){
        if(st.find(ps[i])==st.end()){
            return i;
        }
    }
    return -1;
}

int main(){
    vector<Point2D> A;
    A.push_back(Point2D(-1,3));
    A.push_back(Point2D(1,2));
    A.push_back(Point2D(1,1));
    A.push_back(Point2D(3,1));
    A.push_back(Point2D(0,-1));
    A.push_back(Point2D(-2,1));
    A.push_back(Point2D(-1,2));
    cout << solution(A) << endl;
}
