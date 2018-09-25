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
 <url:https://yukicoder.me/problems/no/187>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */

const ll MOD = 1e9+7;
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }

/*
 Garner のアルゴリズムの前処理
 
 Garnerのアルゴリズムを適応するには m1...mkが互いに素でなければならない
 => b ≡ m が互いに素になるような前処理
*/
ll PreGarner(vector<ll> &b, vector<ll> &m, ll MOD) {
    ll res = 1;
    for (int i = 0; i < (int)b.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            ll g = gcd(m[i], m[j]);
            if ((b[i] - b[j]) % g != 0) return -1;
            m[i] /= g;
            m[j] /= g;
            ll gi = gcd(m[i], g), gj = g/gi;
            do { g = gcd(gi, gj); gi *= g; gj /= g; } while (g != 1);
            m[i] *= gi; m[j] *= gj;
            b[i] %= m[i]; b[j] %= m[j];
        }
    }
    for (int i = 0; i < (int)b.size(); ++i) (res *= m[i]) %= MOD;
    return res;
}


inline ll mod(ll a,ll m){ return (a%m + m)%m;}
/* 拡張ユークリッドの互除法 extgcd */
ll extgcd(ll a, ll b, ll& x, ll& y){
    ll g = a; x = 1; y = 0;
    if(b!=0) { g = extgcd(b, a%b, y, x); y -= (a/b)*x;}
    return g;
}
// 逆元計算 (a,mが違いに素)
ll modinv(ll a,ll m){
    ll x,y;
    extgcd(a,m,x,y);
    return mod(x,m);
}


// Garner のアルゴリズム, x%MOD, LCM%MOD を求める (m は互いに素でなければならない)
//
// 巨大な数字に適応可能
//
// for each step, we solve "coeffs[k] * t[k] + constants[k] = b[k] (mod. m[k])"
//      coeffs[k] = m[0]m[1]...m[k-1]
//      constants[k] = t[0] + t[1]m[0] + ... + t[k-1]m[0]m[1]...m[k-2]
ll Garner(vector<ll> b, vector<ll> m, ll MOD) {
    m.push_back(MOD);
    vector<ll> coeffs((int)m.size(), 1);
    vector<ll> constants((int)m.size(), 0);
    for (int k = 0; k < (int)b.size(); k++) {
        ll t = mod((b[k] - constants[k]) * modinv(coeffs[k], m[k]), m[k]);
        for (int i = k+1; i < (int)m.size(); ++i) {
            (constants[i] += t * coeffs[i]) %= m[i];
            (coeffs[i] *= m[k]) %= m[i];
        }
    }
    return constants.back();
}

ll solve(){
    ll N; cin >> N;
    vector<ll> b(N),m(N);
    for(int i = 0; i < N;i++) cin >> b[i] >> m[i];
    ll LCM = PreGarner(b, m, MOD);
    if(LCM == -1) return -1;
    if(count(b.begin(),b.end(),0)==N) return LCM;
    return Garner(b, m, MOD);
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
