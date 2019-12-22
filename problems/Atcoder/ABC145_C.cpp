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
 <url:https://atcoder.jp/contests/abc145/tasks/abc145_c>
 問題文============================================================
 C - Average Length
 =================================================================
 解説=============================================================
 Nの数が小さいので全探索すればいい

 https://atcoder.jp/contests/abc145/submissions/9028754
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    using Point = complex<double>;
    int N; cin >> N;
    vector<Point> ps(N);
    for(int i = 0; i < N;i++){
        double x,y; cin >> x >> y;
        ps[i] = Point(x,y);
    }
    double sum = 0;
    vector<int> order(N);
    iota(order.begin(),order.end(),0);
    do{
        for(int i = 1; i < N;i++){
            sum += abs(ps[order[i]]-ps[order[i-1]]);
        }
    }while(next_permutation(order.begin(),order.end()));
    double p = 1;
    for(int i = 1; i <= N;i++){
        p *= i;
    }
    res = sum/p;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<double>() << endl;
    return 0;
}
