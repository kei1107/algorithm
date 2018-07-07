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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1328>
 問題文============================================================
 
 n次式の f(x)に対して
 
 f(0),f(1),...,f(n+2) の結果が与えられる。
 しかし、このうちひとつの結果が間違っているとする時、
 その間違っているものを特定せよ
 =================================================================
 解説=============================================================
 
 n次式であれば n+1個の結果がわかっていれば連立方程式を解くことで元の係数を推定することができる。
 
 よって、n+1C2の全通りを愚直に試して、矛盾を探せば良い
 
 誤差判定で落ちることがあるので epsは適当な値で実験する
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

const double eps = 1e-5;
int d;
int solve(){
    int res = 0;
    vector<double> v(d+3);
    for(auto& in:v) cin >> in;
    vector<int> cnt(d+3,0);
    for(int i = 0; i < d+3; i++){
        for(int j = i + 1; j < d+3;j++){
            vector<vector<double>> A(d+1,vector<double>(d+1,0));
            vector<double> B(d+1);
            int idx = 0;
            for(int k = 0; k < d+3;k++){
                if(k == i || k == j) continue;
                for(int l = d; l >= 0; l--){
                    A[idx][l] = pow(k,l);
                }
                B[idx] = v[k];
                idx++;
            }
            auto x = gauss_jordan(A, B); // Ax = B

            bool ok1 = false;
            bool ok2 = false;
            {
                double V = 0;
                for(int l = d; l >= 0; l--){
                    V += x[l]*pow(i,l);
                }
                if(abs(V-v[i]) < eps){ ok1 = true;}
            }
            {
                double V = 0;
                for(int l = d; l >= 0; l--){
                    V += x[l]*pow(j,l);
                }
                if(abs(V-v[j]) < eps) ok2 = true;
            }
            if(ok1 == ok2) continue;
            if(ok1) return j;
            else return i;
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    while(cin >> d,d){
        cout << solve() << endl;
    }
    return 0;
}
