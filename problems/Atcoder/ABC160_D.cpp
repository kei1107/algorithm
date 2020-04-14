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
 <url:https://atcoder.jp/contests/abc160/tasks/abc160_d>
 問題文============================================================
 D - Line++
 =================================================================
 解説=============================================================
 
 すべての頂点i,jの組み合わせにおいて、
 頂点X,Yを経由する場合としない場合のそれぞれを計算して小さい方を選択していけばいい。

 頂点X,Yを経由する場合の距離は abs(X-i)+abs(Y-j)+1　であり、
 頂点X,Yを経由しない場合の距離は j-i　となる。

 https://atcoder.jp/contests/abc160/submissions/11888096

 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int N,X,Y; cin >> N >> X >> Y;
    map<int,int> mp;
    for(int i = 1; i <= N; i++){
        for(int j = i+1; j <= N;j++){
            int D = min(j-i,abs(X-i)+abs(Y-j)+1);
            mp[D]++;
        }
    }
    for(int k = 1; k <= N-1;k++) cout << mp[k] << endl;

    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve(0);
    // cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
