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
 <url:https://beta.atcoder.jp/contests/agc025/tasks/agc025_b>
 問題文============================================================
 =================================================================
 解説=============================================================
 解けなかった。。。。orz
 
 緑をA,Bのどちらも塗る箇所と捉えることができる。
 よって 0<=i<=N の iに対して K - A*i が Bの倍数であり 0 <= (K-A*i)/B = j <= N
 であれば nCr(N,i)*nCr(N,j) がその組み合わせ数
 
 重なっている部分は緑と捉えていいため.
 ================================================================
 */

const ll MOD = 998244353;
const ll MAX_N = 3e5 + 10;
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
ll nCr(ll n,ll r) {
    if(n < r) return 0;
    return (fact[n] * (factInv[r] * factInv[n-r] % MOD)) % MOD;
}

void init(){
    Inv_init();
    fact_init();
}

inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }

ll solve(){
    ll res = 0;
    ll N,A,B,K; cin >> N >> A >> B >> K;
    for(ll x = 0; x <= N; x++){
        ll T = K - A*x;
        if(T < 0) continue;
        if(T%B != 0) continue;
        ll y = T/B;
        if(y > N) continue;
        (res += nCr(N,x)*nCr(N,y))%=MOD;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    init();
    cout << solve() << endl;
    return 0;
}
