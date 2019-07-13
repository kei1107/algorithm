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
template<class T> ostream& operator << (ostream& out,const vector<T>& V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> >& Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T>& mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }
template<typename T>vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}
/*
 <url:https://atcoder.jp/contests/abc127/tasks/abc127_e>
 問題文============================================================
 =================================================================
 解説=============================================================
 xについてのみ考える
 先に累積和等を用いてある2点から得られる全状態の総和を求めておく。
 その後、それら2点以外の全ての点の置き方N*M-2_C_K-2を乗じてあげると
 xについての値の総和となる。

 その後、行と列を逆転させてyを同様に求めればいい
 ================================================================
 */

const ll MAX_N = 3e6 + 10;
const ll MOD = 1e9+7;
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

ll calc(int N,int M,int K){
    ll ret = 0;
    vector<ll> cusum(N+1); // cusum[i] := 長さiまでの使える時の総長
    for(ll i = 1; i <= N;i++){
        cusum[i] = (cusum[i-1] + i*(i-1)/2 * M % MOD * M %MOD)%MOD;
    }
    ret = cusum[N] * nCr(N*M-2,K-2);
    return ret%MOD;
}
template<class Type>
Type solve(Type res = Type()){
    init();
    int N,M,K; cin >> N >> M >> K;
    res = (calc(N,M,K) + calc(M,N,K))%MOD;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
