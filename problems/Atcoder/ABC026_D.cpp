#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e16;
const double eps = 1e-9, pi = acos(-1.0);
/*
<url:https://beta.atcoder.jp/contests/abc026/tasks/abc026_d>
問題文============================================================

 (略)
 
=================================================================

解説=============================================================

 f(t)=A×t+B×sin(C×t×π)
 を図で書くと、増減はするものの右上に向かって増加して行く関数であることがわかる
 
 ここで、f(t) = 100となりうる場所に実際に横線を引くと
 解を一つだけ求めればよいのであれは、通常の二分探索で収束できることがわかる
 
 よって二分探索
 
================================================================
*/

double A,B,C;
inline double f(double t){
    return A*t + B*sin(C*pi*t);
}

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    cin >> A >> B >> C;
    double l = 0, r = INF;
    for(int i = 0; i < 100;i++){
        double m = (l+r)/2;
        if(f(m) > 100){
            r = m;
        }else{
            l = m;
        }
    }
    cout << fixed << setprecision(13) << r << endl;
    
	return 0;
}
