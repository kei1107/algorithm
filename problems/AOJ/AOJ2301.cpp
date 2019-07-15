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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2301>
 問題文============================================================
 =================================================================
 解説=============================================================
 枝借り全探索
 ================================================================
 */

double P,E,T;
double rec(int K,double L,double R){
    double H = (L+R)/2;
    if(K == 0){
        return (double)(abs(T-H)<E);
    }
    if(R < T-E || T+E < L){
        return 0;
    }else if(T-E<=L && R <= T+E){
        return 1;
    }
    if(H <= T){
        return P * rec(K-1,L,H) + (1-P)*rec(K-1,H,R);
    }else{
        return (1-P) * rec(K-1,L,H) + P *rec(K-1,H,R);

    }
}
template<class Type>
Type solve(Type res = Type()){
    int K; double R,L;
    cin >> K >> L >> R;
    cin >> P >> E >> T;
    res = rec(K,L,R);
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<double>() << endl;
    return 0;
}
