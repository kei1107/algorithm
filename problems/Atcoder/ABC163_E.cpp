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
 <url:https://atcoder.jp/contests/abc163/tasks/abc163_e>
 問題文============================================================
 E - Active Infants
 =================================================================
 解説=============================================================

 幼児のうれしさが大きい順に優先的に右詰め or 左詰めに詰めて行きたくなる。
 実際にこの気持ちは正しく、
 
 dp[i][j] := i番目にうれしさの大きい幼児を見た時、これまでにj人右詰めされているときのうれしさの最大

 というdpを行うことで答えがもとまる.

 https://atcoder.jp/contests/abc163/submissions/12219881

 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    ll N; cin >> N;
    vector<ll> A(N); for(auto & in:A) cin >> in;

    vector<pll> B(N);
    for(int i = 0; i < N;i++){
        B[i] = pll(A[i],i);
    }
    sort(B.rbegin(),B.rend());

    auto dp = make_v<ll>(N+1,N+1);
    for(int i = 0; i < N;i++){
        ll a,n; tie(a,n) = B[i];
        for(int j = 0; j <= i;j++){
            dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j] + (n-j) * a);

            dp[i+1][j] = max(dp[i+1][j],dp[i][j] + ((N-(i-j)-1)-n)*a);
        }
    }
    for(int i = 0; i <= N;i++) res = max(res,dp[N][i]);
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
