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
 <url:https://yukicoder.me/problems/no/301>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 Nが小さい時は https://yukicoder.me/problems/129
 の解法をそのまま持ってこればいい
 
 Nが大きい時は実際に結果を見ていくと
 N+5/3に収束する事がわかるのでこれを出力すればいい
 ================================================================
 */

template<typename T>
vector<T> gauss_jordan(const vector<vector<T>>& A, const vector<T>& b) {
    const double EPS = 1e-9; int n = (int)A.size();
    vector<vector<T>> B(n, vector<T>(n + 1));
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) B[i][j] = A[i][j];
    for (int i = 0; i < n; i++) B[i][n] = b[i];
    
    for (int i = 0; i < n; i++) {
        int pivot = i;
        for (int j = i; j < n; j++) {if (abs(B[i][j]) > abs(B[pivot][i]))pivot = j; }
        swap(B[i], B[pivot]);
        
        if (abs(B[i][i]) < EPS) { //解がないか一意でない
            cerr << "error be." << endl; return vector<T>();
        }
        
        for (int j = i + 1; j <= n; j++)B[i][j] /= B[i][i];
        for (int j = 0; j < n; j++) {
            if (i != j) {
                for (int k = i + 1; k <= n; k++) B[j][k] -= B[j][i] * B[i][k];
            }
        }
    }
    vector<T> x(n);//解
    for (int i = 0; i < n; i++) x[i] = B[i][n];
    return x;//veci.
}
double solve(ll K){
    double res = 0;
    vector<vector<double>> A(K+1,vector<double>(K+1,0));
    vector<double> b(K+1,0);
    for(int i = 0; i < K;i++){
        A[i][i] = 6.0;
        for(int j = 1; j <= 6; j++){
            if(i+j<=K) A[i][i+j]--;
            else A[i][0]--;
        }
        b[i] = 6;
    }
    A[K][K] = 1;
    auto E = gauss_jordan(A,b);
    res = E[0];
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    ll T; cin >> T;
    while(T--){
        ll N; cin >> N;
        if(N<=200) cout << solve(N) << endl;
        else cout << (N+5.0/3.0) << endl;
    }
    return 0;
}
