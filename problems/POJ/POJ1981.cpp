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
typedef pair<double,double> Point;
const double eps = 1e-9;
Point P[305];

inline double Abs(const Point& p1,const Point& p2){
    return sqrt((p1.first - p2.first)*(p1.first - p2.first) + (p1.second - p2.second)*(p1.second - p2.second));
}
int main(void) {
//	cin.tie(0); ios::sync_with_stdio(false);
    int N;
    while(true){
        scanf("%d",&N);
        if(N == 0) break;
        for(int i = 0; i < N;i++){
            double x,y; scanf("%lf%lf",&x,&y);
            P[i] = Point(x,y);
        }
        if(N == 1){
            printf("1\n");
            continue;
        }
        int ans = 1;
        for(int i = 0; i < N;i++){
            for(int j = i + 1; j < N;j++){
                double dist = Abs(P[i],P[j]);
                if(dist > 2) continue;
                double r = sqrt(1 - dist*dist/4);
                Point cp = make_pair(-(P[i].second - P[j].second)*r/dist + (P[i].first + P[j].first)/2.0,
                                     (P[i].first - P[j].first)*r/dist + (P[i].second + P[j].second)/2.0);
                int cnt = 0;
                for(int k = 0; k < N;k++){
                    if(Abs(cp,P[k]) < 1.0 + eps) cnt++;
                }
                ans = max(ans,cnt);
            }
        }
        printf("%d\n",ans);
    }
	return 0;
}
