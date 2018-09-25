#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

/*
 <url:https://yukicoder.me/problems/no/733>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 solve
 単純なbitDPとして解く
 部分集合の部分集合を列挙して構築していく
 ただし、普通にやると 4^N かかるので
 典型な 部分集合を 3^Nで列挙する方法を使う
 
 solve2
 ビンパッキング問題として解く
 
 ビンパッキング問題
 与えられた「荷物（重さや個数がついている）」をつめる「箱（ビンやコンテナなど）」の最小数を見つけるものである
 
 荷物の数 N
 容量 T
 荷物の大きさ t[i]
 dp[i][j] := 問題の集合iをj人で解けるだけ解いたとき、解かれずに残った問題の容量の合計の最小値
 O(N^2 2^N)
 
 ================================================================
 */

ll solve(){
    ll res = 0;
    ll T,N; cin >> T >> N;
    vector<ll> t(N); for(auto& in:t) cin >> in;
    vector<ll> uset(1<<N,0);
    for(int j = 0; j < (1<<N);j++){
        for(int k = 0; k < N;k++){
            if((j>>k)&1){
                uset[j] += t[k];
            }
        }
    }
    vector<int> dp(1<<N,INF);
    dp[0] = 0;
    for(int i = 1; i <= (1<<N);i++){
        for(int j = i;; j = (j-1)&i){
            int pre = i&(~j);
            if(uset[j] <= T){
                dp[i] = min(dp[i],dp[pre]+1);
            }
            if(j == 0)break;
        }
    }
    res = dp[(1<<N)-1];
    return res;
}

ll solve2(){
    ll res = 0;
    ll T,N; cin >> T >> N;
    vector<ll> t(N); for(auto& in:t) cin >> in;

    vector<vector<ll>> dp(1<<N,vector<ll>(N+1,INF));
    for(int j = 0; j <= N;j++) dp[0][j] = 0;
    
    for(int i = 1; i < (1<<N);i++){
        for(int j = 0; j < N;j++){
            if(!((i>>j)&1)) continue;
            for(int k = 0; k < N;k++){
                dp[i][k] = min(dp[i][k],dp[i^(1<<j)][k]+t[j]);
                if(dp[i][k] <= T) dp[i][k+1] = 0;
            }
        }
    }
    
    for(int i = 0; i <= N;i++){
        if(!dp[(1<<N)-1][i]){
            res = i;
            break;
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    //cout << solve() << endl;
    cout << solve2() << endl;
    return 0;
}
