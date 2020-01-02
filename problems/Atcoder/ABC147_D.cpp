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
 <url:https://atcoder.jp/contests/abc147/tasks/abc147_d>
 問題文============================================================
 D - Xor Sum 4
 =================================================================
 解説=============================================================

 xorなので、2進数表記上で1桁ずつ考える。

 今、各整数のb桁目について着目する。
 この時、b桁目が0である整数の個数をx1,b桁目が1である整数の個数をx2とした時、
 任意の二つの整数を選択した場合におけるxorの値で1が立つものの個数はx1*x2となる。
 よって、2^b * x1 * x2を答えに加算すればいい。

 上記の処理を全ての桁について行うことで答えが求まる。（O(Nlog_max(A)）

 https://atcoder.jp/contests/abc147/submissions/9121255
 ================================================================
 */

const ll MOD = 1e9+7;
template<class Type>
Type solve(Type res = Type()){
    ll N; cin >> N;
    vector<ll> A(N); for(auto& in:A) cin >> in;

    for(ll b = 0; b <= 60; b++){
        ll x[2] = {0};
        for(int i = 0; i < N;i++){
            x[(A[i]>>b)&1]++;
        }
        res += (x[0]*x[1])%MOD*((1LL<<b)%MOD)%MOD;
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
