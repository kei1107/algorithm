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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1368>
 問題文============================================================
 =================================================================
 解説=============================================================
 問題文通りのことを気合いで書く
 ================================================================
 */


int getv(int a,int b,int c,int d,int e,vector<vector<int>>& x){
    return x[x[x[x[x[0][a]][b]][c]][d]][e];
}
bool check(int a,int b,int c,int d,int e,vector<vector<int>>& x){
    for(int i = 0; i < 10;i++){
        if(i==a) continue;
        if(getv(i,b,c,d,e,x) == 0) return true;
    }
    for(int i = 0; i < 10;i++){
        if(i==b) continue;
        if(getv(a,i,c,d,e,x) == 0) return true;
    }
    for(int i = 0; i < 10;i++){
        if(i==c) continue;
        if(getv(a,b,i,d,e,x) == 0) return true;
    }
    for(int i = 0; i < 10;i++){
        if(i==d) continue;
        if(getv(a,b,c,i,e,x) == 0) return true;
    }
    for(int i = 0; i < 10;i++){
        if(i==e) continue;
        if(getv(a,b,c,d,i,x) == 0) return true;
    }
    if(x[x[x[x[x[0][b]][a]][c]][d]][e] == 0 && a != b) return true;
    if(x[x[x[x[x[0][a]][c]][b]][d]][e] == 0 && b != c) return true;
    if(x[x[x[x[x[0][a]][b]][d]][c]][e] == 0 && c != d) return true;
    if(x[x[x[x[x[0][a]][b]][c]][e]][d] == 0 && d != e) return true;

    return false;
}
template<class Type>
Type solve(Type res = Type()){
    auto x = make_v<int>(10,10);
    for(auto & vec:x) for(auto& in:vec) cin >> in;
    for(int a = 0; a <= 9; a++){
        for(int b = 0; b <= 9; b++){
            for(int c = 0; c <= 9; c++){
                for(int d = 0; d <= 9; d++){
                    int e = x[x[x[x[0][a]][b]][c]][d];
                    res += check(a,b,c,d,e,x);
                }
            }
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
