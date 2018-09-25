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
 <url:https://yukicoder.me/problems/no/194>
 問題文============================================================
 =================================================================
 解説=============================================================
 前半のテストケースは K <= 1e6 なので
 累積和を用いつつO(K)の愚直計算で間に合う
 
 後半のテストケースは典型的な行列累乗問題
 
 (Fk+1 ... Fk-N+1)' = (コンパニオン行列) (Fk-1 ... Fk-N)'
 の形で表すことができるので行列累乗が可能
 また、Skについても　コンパニオン行列の一番上の段に全て1の行を挿入することで
 一緒に計算を行うことができる
 ================================================================
 */

const ll MOD = 1e9+7;

typedef vector<ll> vec;
typedef vector<vec> mat;

mat mul(mat&A,mat&B,const ll M){
    mat C(A.size(),vec(B[0].size()));
    for(int i = 0; i < (int)A.size();i++){
        for(int k = 0; k < (int)B.size();k++){
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

vector<ll> solve(){
    vector<ll> res;
    ll N,K; cin >> N >> K;
    vector<ll> A(N); for(auto& in:A) cin >> in;
    if(K<=1e6){   // testcase01~10
        vector<ll> F(K+1),S(K+1);
        for(int i = 0; i < N;i++){
            (F[i+1] = A[i])%=MOD;
            (S[i+1] = S[i] + A[i])%=MOD;
        }
        for(ll i = N+1; i <= K;i++){
            (F[i] = S[i-1] - S[i-1-N] + MOD)%=MOD;
            (S[i] = S[i-1] + F[i])%=MOD;
        }
        res = vector<ll>{F[K],S[K]};
    }else{      // testcase11~20
        vector<vector<ll>> Mat(N+1,vector<ll>(N+1));
        for(int i = 0; i <= N;i++) Mat[0][i] = 1;
        for(int i = 1; i <= N;i++) Mat[1][i] = 1;
        for(int i = 2; i <= N;i++) Mat[i][i-1] = 1;
        auto retMat = pow(Mat,K-N,MOD);
        vector<vector<ll>> B(N+1,vector<ll>(1));
        B[0][0] = accumulate(A.begin(),A.end(),0LL)%MOD;
        for(int i = 1; i <= N;i++) B[i][0] = A[N-i];
        auto ansMat = mul(retMat,B,MOD);
        res = vector<ll>{ansMat[1][0],ansMat[0][0]};
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
