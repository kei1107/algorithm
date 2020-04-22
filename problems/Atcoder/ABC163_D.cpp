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
 <url:https://atcoder.jp/contests/abc163/tasks/abc163_d>
 問題文============================================================
 D - Sum of Large Numbers
 =================================================================
 解説=============================================================

 この問題は数字の付与されている10^100が 1...Nまでの総和よりもはるかに大きいので、
 N+1個の数からいくつの数を選ぶかで差別化することができる。

 選ぶ数の個数kを固定化させた時、和として作れる数は小さい方からk個選んだ数と大きい方からk個選んだ数の間の数は全てつくることができる。
 よって、小さい方からk個選んだ数と大きい方からk個選んだ数は選ぶ個数を決め打った時にO(1)で求まるので、
 この問題はO(N)で解ける。

 https://atcoder.jp/contests/abc163/submissions/12218123

 ================================================================
 */

const ll MOD = 1e9+7;
template<class Type>
Type solve(Type res = Type()){

    ll N,K; cin >> N >> K;

    // 少ない方からK個とる場合の総和
    ll L = K*(K-1)/2 % MOD;
    for(ll i = K-1; i <= N;i++){
        // 全部とる場合の総和
        ll R = i*(i+1)/2 % MOD;
        (res += (R-L+1+MOD)%MOD)%=MOD;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
