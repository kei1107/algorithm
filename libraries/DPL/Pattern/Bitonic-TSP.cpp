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
 <url:>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */


/*
 Bitonic-TSP
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
ld solve(){
    ld res = LINF;
    ll N; cin >> N;
    vector<Point> ps(N);
    for(int i = 0; i < N;i++){
        ld x,y; cin >> x >> y;
        ps[i] = Point(x,y);
    }
    
 
    // ==== Bitonic-TSP === //
    // メイン処理部分
    sort(ps.begin(),ps.end());
    vector<vector<ld> > L(N, vector<ld>(N, 0.0));
    for (int j = 1; j < N; j++) {
        for (int i = 0; i < j; i++) {
            if (i == 0 && j == 1) {
                L[i][j] = abs(ps[i]-ps[j]);
            } else if (i < j - 1) {
                L[i][j] = L[i][j-1] + abs(ps[j-1]-ps[j]);
            } else {
                L[i][j] = LINF;
                for (int k = 0; k < i; k++){
                    L[i][j] = min(L[i][j], L[k][i] + abs(ps[k]-ps[j]));
                }
            }
        }
    }
    // ==== Bitonic-TSP === //
    
    res = LINF;
    for (int k = 0; k < N-1; k++){
        res = min(res, L[k][N-1] + abs(ps[k]-ps[N-1]));
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(12) << solve() << endl;
    return 0;
}
