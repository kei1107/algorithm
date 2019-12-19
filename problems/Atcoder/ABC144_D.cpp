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
 <url:https://atcoder.jp/contests/abc144/tasks/abc144_d>
 問題文============================================================
 =================================================================
 解説=============================================================

 数学

 水面の側面が三角形となる場合
　 c = 2*x/(a*b)として
　 側面は高さb,底辺cの三角形とみなせる
 水面の側面が台形となる場合
 　c = (2*x - a*a*b)/(a*a)として
 　側面は上辺c,底辺b,高さaの台形とみなせる

 あとは、この関係から普通に角度計算すればいい


 提出：https://atcoder.jp/contests/abc144/submissions/8669845
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    double a,b,x; cin >> a >> b >> x;
    double pi = acos(-1);
    if(x < a*a*b/2.0 + 1e-9){
        double c = 2*x/(a*b);
        res = atan2(b,c)*180.0/pi;
    }else{

        // (b+c)*a/2 * a = x
        // a^2*b/2 + a^2*c/2 = x
        // c = (2*x - a^2*b)/a^2
        double c = (2*x - a*a*b)/(a*a);
        res = atan2(b-c,a)*180.0/pi;

    }


    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<double>() << endl;
    return 0;
}
