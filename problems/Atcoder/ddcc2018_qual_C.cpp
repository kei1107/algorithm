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
 <url:https://atcoder.jp/contests/ddcc2019-qual/tasks/ddcc2018_qual_c>
 問題文============================================================
 =================================================================
 解説=============================================================
 数学計算をがんばる
 ================================================================
 */

const ll MAX_N = 200;
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
template<class Type>
Type solve(Type res = Type()){
    init();
    ll N; cin >> N;
    
    for(ll p = 1; p <= N; p++){
        ll q = N/p;
        
        ll mulP = 0;
        ll mulQ = powmod(q,10);
        for(int x = 1; x <= 10; x++){
            (mulP += nCr(10,x)*powmod(p-1,10-x)%MOD)%=MOD;
        }
        (res += mulP*mulQ%MOD)%=MOD;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
