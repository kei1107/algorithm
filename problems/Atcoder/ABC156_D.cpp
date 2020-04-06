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
 <url:https://atcoder.jp/contests/abc156/tasks/abc156_d>
 問題文============================================================
 D - Bouquet
 =================================================================
 解説=============================================================

 答えは　全種類の花束の総数 - a本となる花束の種類の数 - b本となる花束の種類の数　となる。

 ここで、全種類の花束の総数 = 2^n -1 であり、x本となる花束の種類の数は nCxとなる。
 今回、a・bは2x10^5以下なので nCxを愚直に計算できる。

 https://atcoder.jp/contests/abc156/submissions/11469332
 ================================================================
 */

const ll MOD = 1e9+7;
ll powmod(ll a,ll b) {ll res=1;a%=MOD; for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
// 逆元 1/a % MOD
ll inversemod(ll a) { return powmod(a,MOD - 2);}

template<class Type>
Type solve(Type res = Type()){
    ll n,a,b; cin >> n >> a >> b;

    ll S = powmod(2,n) - 1;
    ll A,B;
    {
        A = 1;
        for(ll i = 1; i <= a; i++){
            (A *= inversemod(i))%=MOD;
            (A *= (n-i+1))%=MOD;
        }
    }
    {
        B = 1;
        for(ll i = 1; i <= b; i++){
            (B *= inversemod(i))%=MOD;
            (B *= (n-i+1))%=MOD;
        }
    }

    res = ((S-A-B)%MOD + MOD)%MOD;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
