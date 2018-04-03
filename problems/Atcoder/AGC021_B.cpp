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
 <url:https://agc021.contest.atcoder.jp/tasks/agc021_b>
 問題文============================================================
 
 平面上に N 個の穴があります。i 個目の穴の座標は、(xi,yi) です。
 
 R=10^10^10^10 とします。りんごさんは、以下の操作を行います。
 
 原点を中心とする半径 R の円内から無作為に 1 点を選び、すぬけ君を置く。
 すぬけ君は、置かれた点からユークリッド距離が最も近い穴に移動し、落ちる。
 そのような穴が複数ある場合は、添え字の最も小さいものを選ぶ。
 
 全ての 1≤i≤N に対し、すぬけ君が i 番目の穴に落ちる確率を求めてください。
 
 ただし、半径 R の円内から無作為に 1 点を選ぶ操作とは、以下の操作を指します。
 
 [−R,R] 上の独立な一様分布にしたがって実数 x,y を選ぶ。
 もしx2+y2≤R2 なら、座標 (x,y) を選ぶ。そうでないなら、その条件が満たされるまで実数 x,y を選びなおし続ける。
 
 
 =================================================================
 
 解説=============================================================
 
 無限に大きい空間の中でいかに自身が領域を取得できるか
    =>　隣あう点との垂直二等分線で仕切られて自身の領域をいかにモテるか
    =>  無限に大きい空間では、与えられた点同士に位置による垂直二等分線の原点からのずれは無視することができる
    =>  原点から各頂点を見た時、いかに自身が占有する角度を持つか、という問題に帰着できる
 
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

void solve(){
    ll N; cin >> N;
    vector<Point> p(N);
    for(int i = 0; i < N;i++){ p[i] = input_point(); }
    if(N == 2){
        cout << 0.5 << endl;
        cout << 0.5 << endl;
        return;
    }
    for(int i = 0; i < N;i++){
        vector<double> area;
        for(int j = 0; j < N; j++){
            if(i == j) continue;
            area.push_back(atan2(p[j].real()-p[i].real(),p[j].imag()-p[i].imag()));
        }
        sort(area.begin(),area.end());
        area.push_back(area[0]+2*pi);
        double ans = 0;
        for(int j = 0; j < area.size()-1;j++){
            if(area[j+1]-area[j]>=pi) ans=area[j+1]-area[j]-pi;
        }
        cout << fixed << setprecision(12) << ans/2/pi << endl;
    }
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    solve();
    return 0;
}
