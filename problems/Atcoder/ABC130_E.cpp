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
 <url:https://atcoder.jp/contests/abc130/tasks/abc130_e>
 問題文============================================================
 =================================================================
 解説=============================================================
 dp[i][j] := [S_1,S_i]及び[T_1,T_j]の二つの文字列を使って作れる共通部分列の総数
 としてdpする。
 
 更新は二次元累積和の要領で行えばいい
 具体的には
 
 dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + (S[i]==T[j]?dp[i-1][j-1]:0)
 
 で計算できる。
 ================================================================
 */

const ll MOD = 1e9+7;
template<class Type>
Type solve(Type res = Type()){
    ll N,M; cin >> N >> M;
    vector<ll> S(N),T(M);
    for(auto& in:S) cin >> in;
    for(auto& in:T) cin >> in;
    
    
    auto add = [](ll& t,const ll v){
        (t += v)%=MOD;
    };
    
    // dp[i][j] := [S_1,S_i]及び[T_1,T_j]の二つの文字列を使って作れる共通部分列の総数
    vector<vector<ll>> dp(N+1,vector<ll>(M+1));
    dp[0][0] = 1;
    for(int i = 0; i <= N;i++) dp[i][0] = 1;
    for(int j = 0; j <= M;j++) dp[0][j] = 1;

    
    for(int i = 1; i <= N;i++){
        for(int j = 1; j <= M;j++){
            add(dp[i][j],dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + MOD + (S[i-1]==T[j-1]?dp[i-1][j-1]:0));
        }
    }
    
    res = dp[N][M];
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
