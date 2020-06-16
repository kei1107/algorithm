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
 <url:https://atcoder.jp/contests/abc169/tasks/abc169_f>
 問題文============================================================
 F - Knapsack for All Subsets
 =================================================================
 解説=============================================================
 　dp[i][j]:=i番目までみたとき、総和がjとなっているときのf(T)の個数
  遷移は
 　  dp[i+1][j] += dp[i][j]*2
 　  dp[i+1][j+A[i]] += dp[i][j]
  としてdpする。
 
 それぞれの遷移について言葉で説明すると以下の通りになる。
 - dp[i+1][j] += dp[i][j]*2について
    i番目の値は総和に寄与しないので、とる場合取らない場合の２通りが考える
 - dp[i+1][j+A[i]] += dp[i][j]について
    i番目の値が総和に寄与するので、とる場合の１通りのみ考える

  https://atcoder.jp/contests/abc169/submissions/13838122
 ================================================================
 */

const ll MOD = 998244353;
ll powmod(ll a,ll b) {ll res=1;a%=MOD;for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}

template<class Type>
Type solve(Type res = Type()){
    ll N,S; cin >> N >> S;
    vector<ll> A(N); for(auto& in:A) cin >> in;


    auto dp = make_v<ll>(N+1,S+1);
    dp[0][0] = 1;
    for(int i = 0; i < N;i++){
        for(int j = 0; j <= S;j++){
            if(dp[i][j] == 0) continue;

            {// not
                (dp[i+1][j] += dp[i][j]*2)%=MOD;
            }
            if(j+A[i] <= S){
                (dp[i+1][j+A[i]] += dp[i][j])%=MOD;
            }
        }
    }
    // cout << dp << endl;
    res = dp[N][S];

    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
