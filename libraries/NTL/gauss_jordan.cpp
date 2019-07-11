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
 GAUSS JORDAN
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
