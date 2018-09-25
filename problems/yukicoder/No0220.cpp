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
 <url:https://yukicoder.me/problems/no/220>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 桁dpするだけ
 ================================================================
 */

ll dp[20][3][2]; // i桁目,桁和j,3を含むか否か
ll solve(){
    ll P; cin >> P;
    ll res = 0;
    for(int i = 0; i < P;i++){
        for(int j = 0; j < 3;j++){
            for(int k = 0; k < 2;k++){
                for(int l = 0; l <= 9;l++){
                    dp[i+1][(j+l)%3][k|(l==3)]+=dp[i][j][k];
                }
            }
        }
        for(int l = 1; l <= 9;l++){
            dp[i+1][l%3][l==3]++;
        }
    }
    res = dp[P][0][0] + dp[P][0][1] + dp[P][1][1] + dp[P][2][1];
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
