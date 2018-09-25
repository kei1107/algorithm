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
 <url:https://yukicoder.me/problems/no/213>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 重複の無いような素数＋合成サイコロの和がiとなる場合の個数をdpを用いて求める。
 
 その後、行列累乗を用いて答えを求める。
 今回の場合は M = 13*P + 12*C とすれば
 これまでの合計が N 〜　N+M-1 となる場合なので
 行列累乗 F = AB
 のBの初期状態を 総和が0 , -1 , ... , -(M-1) の状態で全て1と見立てて
 F(N)を求めてやれば良い
 ================================================================
 */

const ll MOD = 1000000007;

typedef vector<ll> vec;
typedef vector<vec> mat;
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


const ll prime[6] = {2,3,5,7,11,13};
const ll comp[6] = {4,6,8,9,10,12};
ll solve(){
    ll res = 0;
    ll N,P,C; cin >> N >> P >> C;
    
    ll M = 13*P + 12*C;
    vector<vector<ll>> dp(P+C+1,vector<ll>(M+1));
    dp[0][0] = 1;
    for(int k = 0; k < 6;k++){
        for(int m = 0; m < M;m++){
            for(int i = 0; i < P;i++){
                if(dp[i][m] == 0) continue;
                (dp[i+1][m+prime[k]]+=dp[i][m])%=MOD;
            }
        }
    }
    for(int k = 0; k < 6;k++){
        for(int m = 0; m < M;m++){
            for(int i = (int)P; i < P+C;i++){
                if(dp[i][m] == 0) continue;
                (dp[i+1][m+comp[k]]+=dp[i][m])%=MOD;
            }
        }
    }
    auto comb = dp[P+C];

    mat A(M,vec(M));
    for(int i = 1; i <= M;i++) A[0][i-1] = comb[i];
    for(int i = 1; i < M;i++) A[i][i-1] = 1;
    mat B(M,vec(1,1));
    
    mat PowA = pow(A,N+M-1,MOD);
    mat F = mul(PowA,B,MOD);
    res = F[M-1][0];

    return res;
}

int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
