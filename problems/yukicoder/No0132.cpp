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
 <url:https://yukicoder.me/problems/no/132>
 問題文============================================================
 =================================================================
 解説=============================================================
 ３点から平面方程式出して、
 
 平面方程式と点との距離の公式で距離を出せば良い
 ================================================================
 */

typedef long double ld;
ld solve(){
    ld res = 0;
    ll N; cin >> N;
    ld p[3]; for(int i = 0; i < 3;i++) cin >> p[i];
    vector<vector<ld>> q(N,vector<ld>(3));
    for(auto& vec:q) for(auto& in:vec) cin >> in;
    for(int i = 0; i < N;i++){
        for(int j = i+1; j < N;j++){
            for(int k = j+1; k < N;k++){
                vector<ld> ab(3),ac(3);
                for(int l = 0; l < 3;l++){
                    ab[l] = q[j][l] - q[i][l];
                    ac[l] = q[k][l] - q[i][l];
                }
                ld a = ab[1]*ac[2]-ab[2]*ac[1];
                ld b = ab[2]*ac[0]-ab[0]*ac[2];
                ld c = ab[0]*ac[1]-ab[1]*ac[0];
                ld d = -(a*q[i][0]+b*q[i][1]+c*q[i][2]);
                // 平面方程式 ax+by+cz+d=0
                res += abs(a*p[0]+b*p[1]+c*p[2]+d)/sqrt(a*a+b*b+c*c);
            }
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(12) << solve() << endl;
    return 0;
}
