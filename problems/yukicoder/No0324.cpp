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
 <url:https://yukicoder.me/problems/no/324>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 最初の頂点を選択したか、直前の頂点を選択したか、現在の頂点、何個選択したか
 の状態を保ってdpを行う
 ================================================================
 */

#define MAXN 3005
int dp[2][2][MAXN][MAXN]; // 最初の頂点を選択したか、直前の頂点を選択したか、現在の頂点、何個選択したか
int solve(){
    int res = -INF;
    int n,m; cin >> n >> m;
    vector<int> w(n); for(auto& in:w) cin >> in;
    
    fill(***dp,***dp+2*2*MAXN*MAXN,-INF);
    dp[0][0][0][0] = dp[1][1][0][1] = 0;
    for(int r = 0; r < 2;r++){
        for(int i = 0; i < n-1;i++){
            for(int j = 0; j <= m;j++){
                dp[r][0][i+1][j]=max(dp[r][0][i][j],dp[r][1][i][j]);
                if(j) dp[r][1][i+1][j]=max(dp[r][0][i][j-1],dp[r][1][i][j-1]+w[i]);

            }
        }
        res = max(res,dp[r][0][n-1][m]);
        if(r == 0){
            res = max(res,dp[r][1][n-1][m]);
        }else{
            res = max(res,dp[r][1][n-1][m]+w[n-1]);
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
