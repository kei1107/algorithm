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
 <url:https://codeforces.com/problemset/problem/1384/B1>
 問題文============================================================
 B1. Koa and the Beach (Easy Version)
 =================================================================
 解説=============================================================
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int n,k,l; cin >> n >> k >> l;
    vector<int> d(n+2);
    d[0] = -INF;
    for(int i = 1; i <= n;i++) cin >> d[i];
    d[n+1] = -INF;
    
    vector<int> p(2*k);
    for(int i = 0; i <= k; i++) p[i] = i;
    for(int i = k+1; i < 2*k; i++) p[i] = 2*k - i;
    
    vector<vector<bool>> dp(n+2,vector<bool>(2*k));
    dp[0] = vector<bool>(2*k,true);
    for(int i = 0; i <= n;i++){
        for(int c = 0; c < 2; c++){
            for(int j = 0; j < 2*k;j++){
                if(dp[i][j]){
                    int jj = (j+1)%(2*k);
                    
                    // 留まる
                    if(d[i]+p[jj] <= l){
                        dp[i][jj] = true;
                    }
                    
                    // 移動する
                    if(d[i+1]+p[jj] <= l){
                        dp[i+1][jj] = true;
                    }
                }
            }
        }
    }
    
    if(accumulate(dp[n+1].begin(),dp[n+1].end(),0)) return "YES";
    else return "NO";
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    int t; cin >> t; while(t--)
        cout << fixed << setprecision(15) << solve<string>() << endl;
    return 0;
}
