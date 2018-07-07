#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

/*
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2774>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 prim法の要領で辺を追加するたびに、各頂点への最短距離を更新していけば良い
 ================================================================
 */
typedef double ld;
typedef complex<ld> Point;
const ld eps = 1e-9, pi = acos(-1.0);
namespace std {
    bool operator < (const Point& lhs, const Point& rhs) {
        if (lhs.real() < rhs.real() - eps) return true;
        if (lhs.real() < rhs.real() + eps) return false;
        return lhs.imag() < rhs.imag();
    }
}

class Line {
public:
    Point a, b;
    Line() :a(Point(0, 0)), b(Point(0, 0)) {}
    Line(Point a, Point b) :a(a), b(b) {}
    Point operator[](const int _num) {
        if (_num == 0) return a;
        else if (_num == 1) return b;
        else assert(false);
    }
};

ld dot(Point a, Point b) { return real(conj(a)*b); }
Point proj(Line l, Point p) {
    ld t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
    return l.a + t * (l.a - l.b);
}
bool isis_sp(Line s, Point p) {
    return (abs(s.a - p) + abs(s.b - p) - abs(s.b - s.a) < eps);
}

ld dist_sp(Line s, Point p) {
    Point r = proj(s, p);
    return isis_sp(s, r) ? abs(r - p) : min(abs(s.a - p), abs(s.b - p));
}

void solve() {
    int N, M, X, Y; cin >> N >> M >> X >> Y;
    vector<int> flag(N+1, 0);
    vector<Point> ps(N+1);
    ps[0] = Point(X, Y); flag[0] = 1;
    for (int i = 1; i <= N; i++) {
        int a, b; cin >> a >> b;
        ps[i] = Point(a, b);
    }
    
    ld ans = 0;
    vector<double> dist(N + 1, LINF);
    for (int i = 0; i <= N; i++) {
        dist[i] = abs(ps[i] - ps[0]);
    }
    for (int i = 0; i < M; i++) {
        ld len = LINF;
        int idx = -1;
        for (int i = 0; i <= N; i++) {
            if (flag[i] == 1) continue;
            if (len > dist[i]) {
                len = dist[i];
                idx = i;
            }
        }
        
        len = LINF;
        int pidx = -1;
        for (int i = 0; i <= N; i++) {
            if (flag[i] == 1) {
                ld d = abs(ps[i] - ps[idx]);
                if (len > d) {
                    len = d;
                    pidx = i;
                }
            }
        }
        ans += abs(ps[idx] - ps[pidx]);
        flag[idx] = 1;
        Line L(ps[idx], ps[pidx]);
        for (int i = 0; i <= N; i++) {
            if (flag[i] == 1) continue;
            dist[i] = min(dist[i], dist_sp(L, ps[i]));
        }
    }
    cout << fixed << setprecision(12) << ans << endl;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
