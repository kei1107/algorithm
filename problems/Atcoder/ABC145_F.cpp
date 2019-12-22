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
 <url:https://atcoder.jp/contests/abc145/tasks/abc145_f>
 問題文============================================================
 F - Laminate
 =================================================================
 解説=============================================================
 
 高さの変更をしていない時、
 必要な最低限の操作回数は Σmax(0,H[i+1]-H[i]) となる。(H[0] = 0とする)
 これは、左から順番に計算できるので何かしらのdpの形でできないか考える。
 
 色々考えると
 dp[i][j] := i番目まで見た時、j項を選択した場合の最小操作回数
 とした形が思いつく、更新方法は
 
 dp[i][j] = min_k dp[k][j-1] + max(0,H[i]-H[k]) (1 <= k <= i-1)

 となり O(N^3)だが、Nが小さいので十分間に合う
 
 
 https://atcoder.jp/contests/abc145/submissions/9050817
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    ll N,K; cin >> N >> K;
    vector<ll> H(N+1);
    for(int i = 1; i <= N;i++) cin >> H[i];
    
    // dp[i][j] := i番目まで見た時、j項を選択した場合の最小操作回数
    /*
     dp[i][j]
     
        dp[i][j] = min dp[k][j-1] + max(0,H[i]-H[k])
        k = 1 : i-1
     */
    auto dp = make_v<ll>(N+1,N+1);
    fill_v(dp,LINF);
    dp[0][0] = 0;
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N;j++){
            
            for(int k = 0; k < i;k++){
                dp[i][j] = min(dp[i][j],dp[k][j-1] + max(0LL,H[i]-H[k]));
            }
            
        }
    }
    
    res = LINF;
    for(int i = 0; i <= N;i++){
        res = min(res,dp[i][N-K]);
    }
    
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
