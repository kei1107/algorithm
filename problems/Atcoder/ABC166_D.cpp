//#include "bits/stdc++.h"
//using namespace std;
//typedef long long ll;
//typedef pair<int, int> pii;
//typedef pair<ll, ll> pll;
//const int INF = 1e9;
//const ll LINF = 1e18;
//inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
//inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }
//template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
//template<class T> ostream& operator << (ostream& out,const vector<T>& V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
//template<class T> ostream& operator << (ostream& out,const vector<vector<T> >& Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
//template<class S,class T> ostream& operator << (ostream& out,const map<S,T>& mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }
//template<typename T>vector<T> make_v(size_t a){return vector<T>(a);}
//template<typename T,typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}
//template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
//template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}
///*
// <url:>
// 問題文============================================================
// =================================================================
// 解説=============================================================
// ================================================================
// */
//
//
//// nの約数を列挙する
//vector<ll> getdivisor(ll n){
//    vector<ll> res;
//    for(ll i = 1; i*i <= n;i++){
//        if(n%i == 0) {
//            res.push_back(i);
//            if(n/i != i) res.push_back(n/i);
//        }
//    }
//    sort(res.begin(),res.end());
//    return res;
//}
//
//template<class Type>
//Type solve(Type res = Type()){
//    ll X; cin >> X;
//
//    auto divisors = getdivisor(X);
//    for(auto div:divisors){
//        for(ll A = -120; A <= 120; A++){
//            if(A*A*A*A > X) continue;
//
//
//            ll A5 = A*A*A*A*A;
//            ll B = A - div;
//
//            ll B5 = B*B*B*B*B;
//
//            if(A5 - B5 == X){
//                cout << A << " " << B << endl;
//                return res;
//            }
//        }
//    }
//
//    return res;
//}
//int main(void) {
//    cin.tie(0); ios_base::sync_with_stdio(false);
//    solve(0);
//    // cout << fixed << setprecision(15) << solve<ll>() << endl;
//    return 0;
//}
