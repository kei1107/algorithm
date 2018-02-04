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

================================================================
*/

#define MAX_N 100000
const double eps = 1e-10;
const double pi = acos(-1.0);

struct P{
    double x, y;
    P() {}
    P(double x, double y) : x(x), y(y) {}
    P operator + (P p) { return P(x + p.x, y + p.y); }
    P operator - (P p) { return P(x - p.x, y - p.y); }
    P operator * (double d) { return P(x * d, y * d); }
    bool operator < (const P& a) const
    {
        if (x != a.x) return x < a.x;
        else return y < a.y;
    }
    double dot(P p) { return x*p.x + y*p.y; }
    double det(P p) { return x*p.y - y*p.x; }
};

// 凸包
vector<P> convex_hull(P *ps, int N){
    sort(ps, ps + N);
    int k = 0;
    vector<P> qs(N * 2);
    for (int i = 0; i < N; ++i)    {
        while (k > 1 && (qs[k - 1] - qs[k - 2]).det(ps[i] - qs[k - 1]) <= 0) --k;
        qs[k++] = ps[i];
    }
    for (int i = N - 2, t = k; i >= 0; --i)    {
        while (k > t && (qs[k - 1] - qs[k - 2]).det(ps[i] - qs[k - 1]) <= 0) --k;
        qs[k++] = ps[i];
    }
    qs.resize(k - 1);
    return qs;
}

P hs[MAX_N];
double as[MAX_N];

double normalize(double r){
    if (r < -pi / 2.0 + eps) r += pi * 2;
    return r;
}

double atan2(const P& p){
    return normalize(atan2(p.y, p.x));
}

bool double_cmp(double a, double b){
    return a + eps < b;
}

int main() {
    int N; scanf("%d", &N);
    for(int i = 0;i < N;i++) {
        scanf("%lf%lf", &hs[i].x, &hs[i].y);
    }
    vector<P> chs;
    int n = 0;
    if (N > 1) {
        chs = convex_hull(hs, N);
        n = (int)chs.size();
        chs.push_back(chs[0]);
    }
    for(int i = 0; i < n; i++){
        as[i] = atan2(chs[i + 1] - chs[i]);
    }
    sort(as, as + n, double_cmp);
    P p1, p2;
    while (scanf("%lf%lf%lf%lf", &p1.x, &p1.y, &p2.x, &p2.y)!=EOF){
        if (N < 2){
            printf("GOOD\n");
            continue;
        }
        int i = int(upper_bound(as, as + n, atan2(p2 - p1), double_cmp) - as);
        int j = int(upper_bound(as, as + n, atan2(p1 - p2), double_cmp) - as);
        puts((((p2 - p1).det(chs[i] - p1) * (p2 - p1).det(chs[j] - p1) > -eps)) ? "GOOD" : "BAD");
    }
    return 0;
}
