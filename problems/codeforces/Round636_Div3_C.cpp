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
 <url:https://codeforces.com/contest/1343/problem/C>
 問題文============================================================
 C. Alternating Subsequence

 配列が与えられた時、順序を保持したまま、符号が1つずつ反転し　かつ　最大個数　かつ　総和が最大となるような部分列を取り出した時の総和を出力せよ
 =================================================================
 解説=============================================================

 配列を連続する要素で同じ符号の集合毎にまとめたとき、
 各集合毎の最大値を選択していくことで条件を満たすことができる。
 あとは、実装するだけ

 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int n; cin >> n;
    vector<ll> a(n); for(auto& in:a) cin >> in;

    ll max_v = a[0];

    for(int i = 1; i < n;i++){
        if((a[i] > 0) == (a[i-1] > 0)){
            max_v = max(max_v,a[i]);
        }else{
            res += max_v;
            max_v = a[i];
        }
    }
    res += max_v;

    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    int t; cin >> t;
    while(t--){
        cout << fixed << setprecision(15) << solve<ll>() << endl;
    }
    return 0;
}
