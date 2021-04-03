#include "bits/stdc++.h"
#include "atcoder/all"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T>& V){ for(size_t i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> >& Mat){ for(size_t i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T>& mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }
template<typename T>vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}
/*
 <url:https://atcoder.jp/contests/arc044/tasks/arc044_b>
 問題文============================================================
 B - 最短路問題 
 =================================================================
 解説=============================================================
 ================================================================
 */

const ll MOD = 1e9+7;
ll powmod(ll a,ll b) {ll res=1;a%=MOD; for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}

template<class Type>
Type solve(Type res = Type()){
    int N; cin >> N;
    vector<int> A(N); for(auto& in:A) cin >> in;
    if(A[0] != 0) return 0;
    if(count(A.begin(),A.end(),0)!=1) return 0;

    vector<vector<int>> G(N);
    for(int i = 0; i < N;i++){
        G[A[i]].emplace_back();
    }
    for(int i = 1; i < N; i++){
        if(G[i-1].size() == 0 && G[i].size() != 0) return 0;
    }

    res = 1;
    for(int i = 1; i < N; i++){
        if(G[i].empty()) break;

        ll x = G[i-1].size();
        ll y = G[i].size();

        res = res * powmod((powmod(2,x) - 1 + MOD),y) % MOD;
        ll z = (y - 1) * y /2;
        res = res * powmod(2,z) % MOD;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    //solve<ll>(0);
    cout << fixed << setprecision(12) << solve<ll>() << endl;
    return 0;
}