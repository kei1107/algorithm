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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2199&lang=jp>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 dp[i][j] = i番目のデータと見るとき、今の音声信号がjである時の最小二乗和
 としてdpすれば良い
 ================================================================
 */

int N,M;
ll solve(){
    vector<ll> C(M),x(N);
    for(auto& in:C) cin >> in;
    for(auto& in:x) cin >> in;
    vector<vector<ll>> dp(N+1,vector<ll>(256,LINF));
    dp[0][128] = 0;
    for(int i = 0; i < N;i++){
        for(int j = 0; j < 256;j++){
            if(dp[i][j] == LINF) continue;
            for(int k = 0; k < M;k++){
                ll y = j + C[k];
                y = max(0LL,y); y = min(255LL,y);
                dp[i+1][y] = min(dp[i+1][y],dp[i][j] + (ll)pow(y-x[i],2));
            }
        }
    }
    return *min_element(dp[N].begin(),dp[N].end());
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    while(cin >> N >> M,N|M){
        cout << solve() << endl;
    }
    return 0;
}
