#include "bits/stdc++.h"
#include "atcoder/all"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T>& V){ for(size_t i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> >& Mat){ for(size_t i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T>& mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }
template<typename T>vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}
/*
 <url:https://atcoder.jp/contests/typical90/tasks/typical90_e>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */

const ll MOD = 1e9+7;

/*
 行列累乗
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
ll powmod(ll a,ll b,const ll MOD) {ll res=1;a%=MOD;for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}


template<class Type>
Type solve(Type res = Type()){
    ll N,B,K; cin >> N >> B >> K;
    vector<int> C(K); for(auto& in:C) cin >> in;

    // subtask2
    // mat a(B,vec(B));
    // for(int u = 0; u < B; u++){
    //     for(int k = 0; k < K;k++){
    //         int v = (10*u + C[k])%B;
    //         a[u][v] += 1;
    //     }
    // }
    // mat b(B,vec(1)); b[0][0] = 1;
    // {
    //     auto c = pow(a,N,MOD);
    //     auto d = mul(c,b,MOD);
    //     res = d[0][0];
    //     return res;
    // }

    vector<ll> power10(64);
    for(int i = 0; i <= 62; i++){
        power10[i] = powmod(10,(1LL<<i),B);
    }

    vector<vector<ll>> dp(64,vector<ll>(B+1));
    for(int i = 0; i < K; i++){
        dp[0][C[i]%B]++;
    }

    for(int i = 0; i < 62; i++){
        for(int j = 0; j < B; j++){
            for(int k = 0; k < B;k++){
                int next = (j*power10[i] + k) % B;
                (dp[i+1][next] += dp[i][j] * dp[i][k] %MOD) %=MOD;
            }
        }
    }

    vector<vector<ll>> ans(64,vector<ll>(B+1));

    ans[0][0] = 1;
    for(int i = 0; i < 62;i++){
        if((N>>i) & 1){
            for(int j = 0; j < B; j++){
                for(int k = 0; k < B; k++){
                    int next = (j * power10[i] + k)%B;
                    (ans[i+1][next] += ans[i][j] * dp[i][k]%MOD)%=MOD;
                }
            }
        }else{
            ans[i+1] = ans[i];
        }
    }
    res = ans[62][0];

    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    //solve<ll>(0);
    cout << fixed << setprecision(12) << solve<ll>() << endl;
    return 0;
}