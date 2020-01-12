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
 <url:https://atcoder.jp/contests/abc149/tasks/abc149_d>
 問題文============================================================
 D - Prediction and Restriction
 =================================================================
 解説=============================================================
 i番目の勝負に影響があるのはK回前の勝負だけなので、K周期毎に独立して計算を行なっていけばいい
 よって、

 dp[i][j] := i番目の勝負をする時、K回前に出した手がjの時の最大値
 
 としてdpで解ける。
 答えは Σ_i=N〜N+K max(dp[i])
 となる。

 https://atcoder.jp/contests/abc149/submissions/9302896
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int N,K; cin >> N >> K;
    ll R,S,P; cin >> R >> S >> P;
    string T; cin >> T;


    // dp[i][j] := i番目の勝負をする時、K回前に出した手がjの時の最大
    auto dp = make_v<ll>(N+K,3);

    for(int i = 0; i < K;i++){
        // グー
        if(T[i] == 's'){
            dp[i+K][0] = R;
        }
        //　チョキ
        if(T[i] == 'p'){
            dp[i+K][1] = S;
        }
        // パー
        if(T[i] == 'r'){
            dp[i+K][2] = P;
        }
    }

    for(int i = K; i < N;i++){
        for(int j = 0; j < 3;j++){
            for(int k = 0; k < 3;k++){
                if(j == k) continue;
                { // 勝つ
                    if(T[i] == 's' && k == 0){
                        dp[i+K][k] = max(dp[i+K][k],dp[i][j]+R);
                    }
                    if(T[i] == 'p' && k == 1){
                        dp[i+K][k] = max(dp[i+K][k],dp[i][j]+S);
                    }
                    if(T[i] == 'r' && k == 2){
                        dp[i+K][k] = max(dp[i+K][k],dp[i][j]+P);
                    }
                }
                // 負ける or あいこ
                dp[i+K][k] = max(dp[i+K][k],dp[i][j]);
            }
        }
    }

    for(int i = N; i <N+K; i++){
        res += max({dp[i][0],dp[i][1],dp[i][2]});
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
