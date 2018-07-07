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
 <url:https://beta.atcoder.jp/contests/abc029/tasks/abc029_d>
 問題文============================================================
 =================================================================
 解説=============================================================
 dp[桁数][N未満であるか][1の数] := 総数
 として桁dp
 ================================================================
 */

ll dp[15][2][15];
ll solve(){
    ll res = 0;
    string S; cin >> S; for(auto &c:S) c -= '0';
    ll L = S.length();
    dp[0][0][0] = 1;
    for(int i = 0; i < L;i++){
        for(int j = 0; j < 2;j++){
            for(int k = 0; k < L;k++){
                for(int l = 0; l <= (j?9:S[i]);l++){
                    dp[i+1][j||(l<S[i])][k+(l==1)] += dp[i][j][k];
                }
            }
        }
    }
    for(int i = 1; i <= L;i++) res += dp[L][0][i]*i + dp[L][1][i]*i;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
