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
 <url:https://atcoder.jp/contests/abc148/tasks/abc148_e>
 問題文============================================================
 E - Double Factorial
 =================================================================
 解説=============================================================
 末尾が10となるのは素因数に2と5がペアで含まれる場合
 
 今回の場合
　Nが奇数:素因数2が出てこないので 0
　Nが偶数:素因数2は大量に出てくるので素因数5の個数が答え
 
 素因数5の個数の求め方は偶奇の区別がない時は
 Nを 5,5*5,5*5*5,...で割った値の総和になる。
 今回は偶数のみなので
 Nを 5,5*5,5*5*5,...で割った値の"半分"の総和になる。
 
 https://atcoder.jp/contests/abc148/submissions/9079100
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    ll N; cin >> N;
    if(N%2 == 1) return 0;
    for(ll x = 5; x <= N;x*=5) res += N/x/2;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
