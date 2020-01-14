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
 <url:https://atcoder.jp/contests/abc150/tasks/abc150_e>
 問題文============================================================
 E - Change a Little Bit
 =================================================================
 解説=============================================================
 ザ・数学 + walfram alpha

 まず、Cは値の小さいものから操作を行うのが最適であるので、Cを昇順ソートしておく。
 （数列もソート後のCに合わせて並び替えるとする）

 0-indexで考える。

 C[i]を見たとき、C[i]によって得られるコストの和は

 C[i]を含めてC[i]以降にk個異なる箇所が存在するとき、
 2*Binomial(N-i-1,k-1) * 2^k * 2^{N-i-1-k} * 4^i * k * C[i]
 であるので、

 2*4^i*2^{N-i-1}*Σ_[k=1,N-i]Binomial(N-i-1,k-1)*k

 ここで、Σの中身は Walfram alpha先生によると(https://www.wolframalpha.com/input/?i=%CE%A3%5Bk%3D1%2CN-i%5Dk*Binomial%28N-i-1%2Ck-1%29&lang=ja)
 2^{N-i-2}*(N-i+1)となる。

 整理すると

 C[i] * 4^{N-1} * (N-i+1)

 よって答えは
 Σ_[i=0,N-1] C[i] * 4^{N-1} * (N-i+1)
 となる。

 https://atcoder.jp/contests/abc150/submissions/9430023
 ================================================================
 */

const ll MOD = 1e9+7;
// a^b % MOD;
ll powmod(ll a,ll b) {ll res=1;a%=MOD; for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}

template<class Type>
Type solve(Type res = Type()){
    ll N; cin >> N;
    vector<ll> C(N); for(auto& in:C) cin >> in;

    sort(C.begin(),C.end());
    for(int i = 0; i < N;i++){
        res += powmod(4,N-1)*C[i]%MOD*(N-i+1)%MOD;
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
