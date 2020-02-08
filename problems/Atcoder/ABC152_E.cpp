#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a/gcd(a,b)*b; }
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T>& V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> >& Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T>& mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }
template<typename T>vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}
/*
 <url:https://atcoder.jp/contests/abc152/tasks/abc152_e>
 問題文============================================================
 E - Flatten
 =================================================================
 解説=============================================================
 配列Aの最小公倍数をLCMとすると。答えはΣLCM/Ai
 
 ここで、問題がとしてC++などだとLCMがオーバーフローする。（多倍長使えば大丈夫だけど、C++の多倍長だとTLEする。何故かpythonとかだと間に合うっぽい）
 
 なので、MODをとりながらLCMを求める必要がある。 その為、各Aを素因数分解して素因数ベースでLCMを求める。
 LCM、各素因数について全A中の最大数を乗じていけばいい。
 
 https://atcoder.jp/contests/abc152/submissions/9640764
 ================================================================
 */

const ll MOD = 1e9+7;
// a^b % MOD;
ll powmod(ll a,ll b) {ll res=1;a%=MOD; for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
// 逆元 1/a % MOD
ll inversemod(ll a) { return powmod(a,MOD - 2);}
map<ll,ll> lcms;
void PrimeFact(ll n){
    map<ll,ll> mp;
    while(n!=1){
        if(n == 2 || n == 3){
            mp[n]++; n/=n;
            continue;
        }
        bool prime_flag = false;
        for(ll i = 2;i*i <= n;i++){
            if(n%i==0){
                mp[i]++; n/=i;
                prime_flag = true;
                break;
            }
        }
        if(!prime_flag){mp[n]++; n/= n;}
    }
    for(auto p:mp){
        lcms[p.first] = max(lcms[p.first],p.second);
    }
}
template<class Type>
Type solve(Type res = Type()){
    ll N; cin >> N;
    vector<ll> A(N); for(auto& in:A) cin >> in;

    for(auto a:A) PrimeFact(a);
    ll _lcm = 1;
    for(auto p:lcms){
        for(int i = 0; i < p.second; i++){
            _lcm *= p.first;
            _lcm %= MOD;
        }
    }

    for(int i = 0; i < N;i++){
        res += _lcm*inversemod(A[i])%MOD;
        res %= MOD;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
