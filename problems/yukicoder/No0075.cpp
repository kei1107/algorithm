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
 <url:https://yukicoder.me/problems/no/75>
 問題文============================================================
 1個のサイコロを何回か振って目の合計をちょうどKにしたい。
 もしKを超えてしまったら合計を0にリセットする。
 ただしサイコロを振った回数はリセットされない。
 例えば、K=5のときサイコロを1回振って6が出たとする。
 この場合はKを超えてしまったので合計を0に戻し2回目を振ることになる。
 サイコロは目の合計がちょうどKになるまで振り続ける。
 サイコロを振る回数の期待値を求めよ。
 =================================================================
 解説=============================================================
 
 色々解法がある。
 
 連立方程式、
 二分探索、
 モンテカルロ
 
 今回は連立方程式を愚直に解いた
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

double solve(int K){
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
    int K; cin >> K;
    cout << fixed << setprecision(12) << solve(K) << endl;
    return 0;
}
