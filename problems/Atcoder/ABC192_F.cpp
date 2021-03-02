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
 <url:https://atcoder.jp/contests/abc192/tasks/abc192_f>
 問題文============================================================
 F - Potion 
 =================================================================
 解説=============================================================
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    ll N,X; cin >> N >> X;
    vector<ll> A(N); for(auto& in:A) cin >> in;

    auto dp = make_v<ll>(N+1,N+1,N+1);
    res = numeric_limits<ll>::max();
    for(int k = 1; k <= N;k++){
        fill_v(dp,numeric_limits<ll>::max());

        dp[0][0][X%k] = X;

        for(int i = 0; i < N;i++){
            for(int j = 0; j <= k; j++){
                for(int l = 0; l < k; l++){
                    if(dp[i][j][l] == numeric_limits<ll>::max()) continue;

                    dp[i+1][j][l] = min(dp[i+1][j][l],dp[i][j][l]);

                    if(j < k){
                        ll T = ((l - A[i])%k + k)%k;
                        dp[i+1][j+1][T] = min(dp[i+1][j+1][T],dp[i][j][l] - A[i]);
                    }
                }
            }
        }
        if(dp[N][k][0] != numeric_limits<ll>::max()){
            res = min(res,dp[N][k][0]/k);
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    //solve<ll>(0);
    cout << fixed << setprecision(12) << solve<ll>() << endl;
    return 0;
}