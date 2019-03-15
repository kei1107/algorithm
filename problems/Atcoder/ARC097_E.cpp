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
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

/*
 <url:https://atcoder.jp/contests/arc097/tasks/arc097_c>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 解説AC:[http://drken1215.hatenablog.com/entry/2018/06/07/105800]
 
 dpを用いるとこまでは考えついたが、前処理部で計算量が落とせることに気づかなかった。
 ================================================================
 */


template<class Type>
Type solve(Type res = Type()){
    int N; cin >> N;
    vector<pair<char,int>> ca(2*N);
    map<pair<char,int>,int> mp;
    for(int i = 0; i < 2*N;i++){
        cin >> ca[i].first >> ca[i].second;
        ca[i].second--;
    }
    res = LINF;
    
    vector<vector<ll>> B(N+1,vector<ll>(N+1,0));
    vector<vector<ll>> W(N+1,vector<ll>(N+1,0));
    
    vector<ll> bcnt(N,0),wcnt(N,0);
    for(int i = 0; i < 2*N;i++){
        char c; int a; tie(c,a) = ca[i];
        
        vector<ll> bsum(N+1,0),wsum(N+1,0);
        for(int j = N; j > 0; j--){
            bsum[j-1] = bsum[j] + bcnt[j-1];
            wsum[j-1] = wsum[j] + wcnt[j-1];
        }
        for(int j = N+1; j > 0; j--){
            if(c == 'B') B[a][j-1] = wsum[j-1] + bsum[a+1];
            if(c == 'W') W[a][j-1] = wsum[a+1] + bsum[j-1];
        }
        if(c=='B') bcnt[a]++;
        else wcnt[a]++;
    }

    vector<vector<ll>> dp(N+1,vector<ll>(N+1,LINF));
    dp[0][0] = 0;
    for(int i = 0; i <= N;i++){
        for(int j = 0; j <= N;j++){
            if(i!=N) dp[i+1][j] = min(dp[i+1][j],dp[i][j]+B[i][j]);
            if(j!=N) dp[i][j+1] = min(dp[i][j+1],dp[i][j]+W[j][i]);
        }
    }
    res = dp[N][N];
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
