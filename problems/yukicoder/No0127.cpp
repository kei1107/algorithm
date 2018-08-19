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
 <url:https://yukicoder.me/problems/no/127>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 深く考え過ぎていた。。。orz
 思いつきたかった
 
 >> https://yukicoder.me/problems/no/127/editorial
 ================================================================
 */

const ll MAXN = 3000;
ll dp[2][MAXN][MAXN];
ll solve(){
    ll res = 1;
    int N; cin >> N;
    vector<int> A(N); for(auto& in:A) cin >> in;
    for(int i = 0; i < N;i++) dp[0][i][i] = dp[1][i][i] = 1;
    for(int add = 1; add <= N;add++){
        for(int l = 0; l+add < N;l++){
            int r = l+add;
            if(A[l] >= A[r]) dp[0][l][r] = dp[0][l][r-1];
            else dp[0][l][r] = max(dp[0][l][r-1],dp[1][l+1][r]+1);
            
            if(A[l] <= A[r]) dp[1][l][r] = dp[1][l+1][r];
            else dp[1][l][r] = max(dp[1][l+1][r],dp[0][l][r-1]+1);
            
            res = max({res,dp[0][l][r],dp[1][l][r]});
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
