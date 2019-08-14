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
 <url:https://atcoder.jp/contests/abc137/tasks/abc137_f>
 問題文============================================================
 =================================================================
 解説=============================================================

 解説AC : https://img.atcoder.jp/abc137/editorial.pdf
 
 これは気づきたかった
 
 1 - (x - i)^{p-1}は x = i の時のみ 1 であり、 それ以外の時 0 となる。
 よって、 a_i = 1 となるiに対して1 - (x - i)^{p-1}を全て足し合わせればいい。
 
 ================================================================
 */

const ll MAX_N = 10000;
ll MOD = 1e9+7;
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
ll nCr(int n,int r) {
    if(n < r) return 0;
    return (fact[n] * (factInv[r] * factInv[n-r] % MOD)) % MOD;
}
void init(){
    Inv_init();
    fact_init();
}

template<class Type>
Type solve(Type res = Type()){
    
    int p ; cin >> p;
    vector<ll> a(p); for(auto& in:a) cin >> in;
    vector<ll> b(p);
    
    
    MOD = p;
    init();
    
    for(int i = 0; i < p;i++){
        vector<ll> pi(p);
        pi[0] = 1;
        for(int j = 1; j < p;j++){
            pi[j] = pi[j-1] * (-i);
            pi[j] = (pi[j]%p + p)%p;
        }
        if(a[i]){
            // 1 - (x-i)^{p-1}
            b[0] += 1;
            for(int j = 0; j < p;j++){
                b[j] -= pi[p-1-j]*nCr(p-1,j);
            }
        }
    }
    
    for(auto& v:b) v = (v%p + p)%p;
    res = b;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<vector<ll>>() << endl;
    return 0;
}
