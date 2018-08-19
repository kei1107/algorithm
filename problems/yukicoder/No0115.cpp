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
 <url:https://yukicoder.me/problems/no/115>
 問題文============================================================
 =================================================================
 解説=============================================================
 制約が小さいのでO(NDK)のdpで間に合う
 ================================================================
 */

vector<ll> solve(){
    vector<ll> res;
    ll N,D,K; cin >> N >> D >> K;
    vector<vector<vector<ll>>> dp(D+1,vector<vector<ll>>(K+1,vector<ll>{INF}));
    dp[0][0] = {};
    for(int i = 1; i <= N;i++){
        for(int j = D-1; j >= 0;j--){
            if(i+j>D) continue;
            for(int k = 0; k < K;k++){
                vector<ll> it = dp[j][k];
                it.push_back(i);
                dp[i+j][k+1] = min(dp[i+j][k+1],it);
            }
        }
    }
    if(dp[D][K][0] == INF){
        return vector<ll>{-1};
    }else{
        return dp[D][K];
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
