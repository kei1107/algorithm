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
 <url:https://yukicoder.me/problems/no/214>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 制約が厳しくなったので
 No214をkitamasa法を用いて解く O(N^2 log K)
 ================================================================
 */

const ll MOD = 1000000007;
/*
 kitamasa法
 F(x) = Σ_{i=1..N} A(x,i)*F(i)
 
 F(K)をO(N^2 logK)で求める

 calc関数で
 F_K = A0*F0 + A1*F1 + ... A_K-1*F_K-1 => return F_N
 を返す
 
 自分メモ
 普段頭の中では以下の形で行列を考えているので、代入値に注意
 (A0,A1,....,A_K-1) |F_K-1  |
                    |...    |
                    |F1     |
                    |F0     |
 
 */
struct kitamasa{
    vector<ll> mul(const vector<ll>& v1,const vector<ll>& v2,const vector<ll>& A,const ll M){
        int N =(int)v1.size();
        vector<ll> ret(2*N,0);
        for(int i = 0; i < N;i++){
            for(int j = 0; j < N;j++){
                if(v1[i] == 0 && v2[j] == 0) continue;
                (ret[i+j] += v1[i]*v2[j]%M + M)%=M;
            }
        }
        for(int i = 2*N-2; i>= N;i--){
            if(ret[i] == 0) continue;
            for(int j = 1; j <= N; j++){
                if(A[N-j] == 0) continue;
                (ret[i-j] += A[N-j]*ret[i]%M + M)%=M;
            }
        }
        ret = vector<ll>(ret.begin(),ret.begin()+N);
        return ret;
    }
    vector<ll> pow(ll N,const vector<ll>& A,const ll M){
        int _n = (int)A.size();
        vector<ll> ret(_n,0),v(_n,0);
        ret[0] = v[1] = 1;
        while(N > 0){
            if(N&1) ret = this->mul(ret,v,A,M);
            v = this->mul(v,v,A,M);
            N>>=1;
        }
        return ret;
    }
    
    // F_K = A0*F0 + A1*F1 + ... A_K-1*F_K-1 => return F_N
    ll calc(ll N,const vector<ll>& F,const vector<ll>& A,const ll M){
        ll ret = 0;
        vector<ll> PowA = this->pow(N,A,M);
        for(int i = 0; i < F.size();i++) (ret += F[i]*PowA[i]%M + M)%=M;
        return ret;
    }
};


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
    
    // F_K = A0*F0 + A1*F1 + ... A_K-1*F_K-1
    vector<ll> F(M,1),A(M,0);
    for(int i = 0; i < M;i++) A[i] = comb[M-i];
    kitamasa kt;
    res = kt.calc(N+M-1,F,A,MOD);
    return res;
}

int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
