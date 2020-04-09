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
 <url:https://atcoder.jp/contests/abc159/tasks/abc159_d>
 問題文============================================================
 D - Banned K
 =================================================================
 解説=============================================================

 まず同じ数字が書かれたボールの個数をmapなどを用いて数える。
 この状態でも、k番目のボールを取り除いた場合の選び方をmapを用いて選んだとしても
 O(N^2)となるケースが存在し間に合わない。

 ここで、どのボールも取り除かない場合の選び方の総数を事前に計算しておく。
 これにより、k番目のボールをみたときの同じ数値のボールの個数から、
 k番目のボールを取り除いた時の選び方の総数を高速に計算可能となる。

 https://atcoder.jp/contests/abc159/submissions/11672354

 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    ll N; cin >> N;
    vector<ll> A(N); for(auto& in:A) cin >> in;
    map<ll,ll> mp;
    for(auto a:A) mp[a]++;

    ll sum = 0;
    for(auto p:mp){
        sum += p.second*(p.second-1)/2;
    }

    for(int k = 0; k < N;k++){

        ll num = mp[A[k]];

        ll dec = num*(num-1)/2;
        ll add = (num-1)*(num-2)/2;
        cout << sum - dec + add << endl;
    }

    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve(0);
    // cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
