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
 <url:https://yukicoder.me/problems/no/134>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 dp[mask][i] := mask状態の場所に到達済みであり、現在位置がiであるときの最短距離
 でbitdpしてやれば良い
 ================================================================
 */

typedef long double ld;
typedef complex<ld> Point;
inline ld norm_l1(Point p){
    return abs(imag(p))+abs(real(p));
}
ld solve(){
    ld res = INF;
    ld x,y; cin >> x >> y;
    Point p(x,y);
    
    int N; cin >> N;
    vector<Point> ps(N);
    vector<ld> w(N);
    for(int i = 0; i < N;i++){
        cin >> x >> y;
        ps[i] = Point(x,y);
        cin >> w[i];
    }
    ld W = accumulate(w.begin(),w.end(),(ld)0);
    vector<vector<ld>> dp(1<<N,vector<ld>(N,INF));
    for(int i = 0; i < N;i++) dp[1<<i][i] = norm_l1(p-ps[i])*(W+100)/120;
    for(int i = 1; i < (1<<N);i++){
        for(int j = 0; j < N;j++){
            if(dp[i][j]>=INF) continue;
            ld haveW = W;
            for(int k = 0; k < N;k++) if(i>>k&1) haveW -= w[k];
            for(int k = 0; k < N;k++){
                if(i>>k&1) continue;
                dp[i|(1<<k)][k] = min(dp[i|(1<<k)][k],dp[i][j]+norm_l1(ps[j]-ps[k])*(haveW+100)/120);
            }
        }
    }
    
    for(int i = 0; i < N;i++) res = min(res,W+dp[(1<<N)-1][i]+norm_l1(p-ps[i])*100/120);
    
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(12) << solve() << endl;
    return 0;
}
