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
 <url:https://yukicoder.me/problems/no/140>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 先に、 xペアの夫婦でyグループ作る組み合わせを求めておけば
 x,yの全ての場合で
 
 nCx * (xペアの夫婦でyグループ作る組み合わせ) * (y*(y-1))^(N-x)
 の総和が答え
 ================================================================
 */

const ll MOD = 1e9+7;
const ll MAX_N = 600;
ll Inv[MAX_N];
ll fact[MAX_N];
ll factInv[MAX_N];
void Inv_init(){
    Inv[1] = 1;
    for(int i = 2; i < MAX_N; i++) {
        Inv[i] = Inv[MOD%i] * (MOD - MOD/i) % MOD;
    }
}
void fact_init(){
    fact[0] = fact[1] = factInv[0] = factInv[1] = 1;
    for(int i = 2; i < MAX_N; i++){
        fact[i] = (fact[i-1] * i) % MOD;
        factInv[i] = (factInv[i-1] * Inv[i])%MOD;
    }
}

// a^b % MOD;
ll powmod(ll a,ll b) {ll res=1;a%=MOD; for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
// 逆元 1/a % MOD
ll inversemod(ll a) { return powmod(a,MOD - 2);}

// 1 以上 N 以下の N 個の整数の中から，相異なる K 個の整数を選ぶパターンの数
ll nCr(int n,int r) {
    if(n < r) return 0;
    return (fact[n] * (factInv[r] * factInv[n-r] % MOD)) % MOD;
}
// 1 以上 N 以下の N 個の整数の中から，相異なる K 個の整数を選び，順番に並べるパターンの数
ll nPr(int n,int r){
    if(n < r) return 0;
    return (fact[n]*factInv[n-r])%MOD;
}
// 1 以上 N 以下の N 個の整数の中から，重複を許して K 個の整数を選ぶパターンの数
ll nHr(int n,int r){
    if(n == 0 && r == 0) return 1;
    return nCr(n+r-1,r);
}

void init(){
    Inv_init();
    fact_init();
}

// 区別できるN個のものを、区別できないrグループに分けるパターンの数
ll F[MAX_N][MAX_N];
ll nFr(int n,int r){
    return F[n][r];
}
void F_init(){
    for(int i = 1; i < MAX_N;i++){
        F[i][1] = F[i][i] = 1;
        for(int j = 2; j < i;j++){
            F[i][j] = (F[i-1][j-1] + j*F[i-1][j])%MOD;
        }
    }
}

ll solve(){
    init();
    F_init();
    ll res = 0;
    int N; cin >> N;
    vector<vector<ll>> table(N+1,vector<ll>(N+1));
    for(int i = 1; i <= N;i++) table[i][i] = 1;
    for(int x = 1; x <= N;x++){
        for(int y = 1; y <= x; y++){
            (res += nCr(N,x)*nFr(x,y)%MOD*powmod(y*(y-1),N-x))%=MOD;
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
