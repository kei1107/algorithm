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
 <url:https://codeforces.com/problemset/problem/1409/F>
 問題文============================================================
 F. Subsequences of Length Two
 =================================================================
 解説=============================================================
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int N,K; cin >> N >> K;
    string s,t; cin >> s >> t;

    if(t[0] == t[1]){
        // valid input
 
        ll cnt = count(s.begin(),s.end(),t[0]);
        ll max_cnt = min(1LL*N,cnt+K);
        res = max_cnt * (max_cnt-1)/2;
        return res;
    }

    auto dp = make_v<ll>(N+1,N+1,K+1);
    auto chmax = [](ll& l,const ll r){
        l = max(l,r);
    };
    fill_v(dp,-1);
    dp[0][0][0] = 0;
    for(int i = 0; i < N;i++){
        for(int j = 0; j <= N; j++){
            for(int k = 0; k <= K; k++){
                if(dp[i][j][k] == -1) continue;
                chmax(dp[i+1][j+(s[i]==t[0])][k],dp[i][j][k]+(s[i]==t[1])*j);

                if(k != K){
                    // replace t[0]
                    chmax(dp[i+1][j+1][k+1],dp[i][j][k]);
                    // replace t[1]
                    chmax(dp[i+1][j][k+1],dp[i][j][k]+j);   
                }                    
            }
        }
    }
    

    for(int j = 0; j <= N;j++){
        for(int k = 0; k <= K;k++){
            res = max(res,dp[N][j][k]);
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