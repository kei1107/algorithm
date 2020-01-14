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
 <url:https://atcoder.jp/contests/abc150/tasks/abc150_d>
 問題文============================================================
 D - Semi Common Multiple
 =================================================================
 解説=============================================================
 難しい

 ai = 2*xi とする。
 このとき、全てのiに対して
 X = 2*xi(p+0.5) = 2*xi*p + xi  (1)
 となるXを見つける問題となる。
 ここで、最小のXを見つけたい。
 最小のXの"候補"はxiの最小公倍数を取ることで求めることができるが、
 ここで条件として、(1)式より、xiの奇数倍であることが必要となる。

 こうして、最小のXを見つけたら、あとは2*XずつMまでずらしていけばいいので数学で解ける

 https://atcoder.jp/contests/abc150/submissions/9429257
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    ll N,M; cin >> N >> M;
    vector<ll> a(N); for(auto& in:a) cin >> in;

    sort(a.begin(),a.end());
    ll _lcm = 1;
    for(auto x:a){
        _lcm = lcm(_lcm,x/2);
        if(_lcm > M) return res;
    }
    for(auto x:a){
        if(_lcm/(x/2)%2==0) return res;
    }
    res = (M-_lcm)/(2*_lcm) + 1;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
