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
 <url:https://yukicoder.me/problems/no/209>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 dp[i][j] := 直前にi->jの山を用いた場合の最長の部分列
 
 としてdp
 ================================================================
 */

vector<vector<int>> init_dp(int N,vector<ll>& A){
    vector<vector<int>> dp(N,vector<int>(N,0));
    for(int i = 0; i < N;i++) dp[i][i] = 1;
    for(int i = 0; i < N;i++){
        for(int j = 0; j <= i; j++){
            for(int k = i+1; k < N;k++){
                if(A[i]<A[k]){
                    if(A[i] - A[j] < A[k] -A[i]){
                        dp[i][k] = max(dp[i][k],dp[j][i]+1);
                    }
                }
            }
        }
    }
    return dp;
}
ll solve(){
    int res = 0;
    int N; cin >> N;
    vector<ll> A(N); for(auto& in:A) cin >> in;
    auto dpl = init_dp(N,A);
    reverse(A.begin(),A.end());
    auto dpr = init_dp(N,A);
    
    
    for(int i = 0; i < N;i++){
        for(int j = 0; j <= i;j++){
            for(int k = i; k < N;k++){
                res = max(res,dpl[j][i]+dpr[N-1-k][N-1-i]-1);
            }
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    int T; cin >> T;
    while(T--){
        cout << solve() << endl;
    }
    return 0;
}
