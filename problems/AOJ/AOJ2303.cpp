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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2303>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 制約が小さいので愚直な解法が通る
 
 あるランナーに注目したとき、そのランナーが j回 (0<=j<=M)休憩取る場合に関して決め打ち
 すれば、それ以外のランナーが l回 (0<=l<=M)休憩する場合と比較して確率を出すことができる。
 
 これは O(NMNM)でとけるため間に合う
 
 ================================================================
 */

double powmod(double x, ll n) {
    double res = 1;
    while (n > 0) {
        if (n & 1) { //奇数なら
            res =(res*x);
        }
        x = (x*x);
        n >>= 1;
    }
    return res;
}
void solve(){
    int N,M,L; cin >> N >> M >> L;
    vector<double> P(N),T(N),V(N);
    for(int i = 0; i < N;i++){
        cin >> P[i] >> T[i] >> V[i];
        P[i]/=100.;
    }
    const int MAX_M = 50;
    double comb[MAX_M+1][MAX_M+1];
    for (int i = 0; i <= MAX_M; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i)
                comb[i][j] = 1;
            else
                comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
        }
    }
    
    cout << fixed << setprecision(12);
    for(int i = 0; i < N;i++){
        if(V[i] == 0){ cout << 0. << endl; continue;}
        double ans = 0;
        for(int j = 0; j <= M;j++){
            double tans = powmod(P[i],j)*powmod(1-P[i],M-j)*comb[M][j];
            double Time = T[i]*j + L/V[i];
            for(int k = 0; k < N;k++){
                if(i == k) continue;
                double sum = 0;
                for(int l = 0; l <= M; l++){
                    double TTime = T[k]*l + L/V[k];
                    if(TTime < Time + 1e-9) continue;
                    sum += powmod(P[k],l)*powmod(1-P[k],M-l)*comb[M][l];
                }
                tans *= sum;
            }
            ans += tans;
        }
        cout << ans << endl;
    }
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
