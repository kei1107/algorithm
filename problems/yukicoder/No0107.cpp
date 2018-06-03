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
 <url:https://yukicoder.me/problems/no/107>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 良いモンスターに遭遇した状態と悪いモンスターを倒した状態をbitDPで全探索する
 
 dp[S1][S2] := 良いモンスターに遭遇した状態がS1,悪いモンスターを倒した状態がS2の時の最大体力
 
 とすれば良い
 
 ================================================================
 */

ll solve(){
    ll res = 0;
    ll N; cin >> N;
    vector<ll> D(N);
    vector<ll> good,evil;
    for(auto& in:D){
        cin >> in;
        if(in > 0) good.push_back(in);
        if(in < 0) evil.push_back(-in);
    }
    
    vector<vector<ll>> dp(1<<good.size(),vector<ll>(1<<evil.size(),0));
    dp[0][0] = 100;
    for(int i = 0; i < (1<<good.size()); i++){
        for(int j = 0; j < (1<<evil.size()); j++){
            if(dp[i][j] <= 0) continue;
            int good_num = __builtin_popcount(j);
            for(int k = 0; k < good.size();k++){
                if((i>>k)&1) continue;
                dp[i|(1<<k)][j] = max(dp[i|(1<<k)][j],min(100*(good_num+1LL),dp[i][j]+good[k]));
            }
            for(int k = 0; k < evil.size();k++){
                if((j>>k)&1) continue;
                dp[i][j|(1<<k)] = max(dp[i][j|(1<<k)],dp[i][j]-evil[k]);
            }
        }
    }
    res = max(res,dp[(1<<good.size())-1][(1<<evil.size())-1]);
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
