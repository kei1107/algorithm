#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

/*
 <url:https://yukicoder.me/problems/no/344>
 問題文============================================================
 =================================================================
 解説=============================================================
 蟻本p239
 

 (1+√3)^n = a_n + b_n√3
 (1-√3)^n = a_n - b_n√3
 
 (1+√3)^n + (1-√3)^n = 2*a
 (1+√3)^n = 2*a - (1-√3)^n
 
 
 if n is even
    0 < (1-√3)^n < 1
 
    ans = 2*a_n - 1
 else
    -1 < (1-√3)^n < 0
 
    ans = 2*a_n
 
 (1+√3)^(n+1) = (a_n + b_n√3)(1+√3) = (a_n + 3*b_n) + (a_n + b_n)*√3
 
 a_n+1 = a_n + 3*b_n
 b_n+1 = a_n + b_n
 
 |a_n+1 |       |   1   3   | | a_n |
 |      |   =   |           | |     |
 |b_n+1 |       |   1   1   | | b_n |
 
 a_nを行列累乗で求めればいい
 ================================================================
 */

typedef vector<ll> vec;
typedef vector<vec> mat;

/*
 行列累乗
 X = A^M*B
 A ( N*N行列)
 
 O(N^3 logM)
 */
mat mul(mat&A,mat&B,const ll M){
    mat C(A.size(),vec(B[0].size()));
    for(int i = 0; i < (int)A.size();i++){
        for(int k = 0; k < (int)B.size();k++){
            if(A[i][k] == 0) continue;
            for(int j = 0; j < B[0].size();j++){
                C[i][j] = (C[i][j] + A[i][k]*B[k][j])%M;
            }
        }
    }
    return C;
}

mat pow(mat A,ll n,const ll M){
    mat B(A.size(),vec(A.size()));
    for(int i = 0; i < A.size();i++){
        B[i][i] = 1;
    }
    while(n > 0){
        if(n&1) B= mul(B,A,M);
        A = mul(A,A,M);
        n>>=1;
    }
    return B;
}


ll solve(){
    ll res = 0;
    ll n; cin >> n;
    mat A = {{1,3},{1,1}};
    mat B = {{1},{0}};
    A = pow(A,n,1000);
    res = 2*mul(A,B,1000)[0][0] % 1000;
    if(n%2==0) (res += 999)%=1000;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
