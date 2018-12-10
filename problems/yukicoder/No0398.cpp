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
 <url:https://yukicoder.me/problems/no/398>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 処理が単調なので、
 愚直なdpが間に合ってしまう
 ================================================================
 */

ll dp[6][601][101][101]; // dp[i][j][k][l] := i個,総和j, min k , max l の個数
ll solve(){
    ll res = 0;
    double X; cin >> X;
    ll FX = 4*X;
    for(int i = 0; i <= 100; i++) dp[0][i][i][i] = 1;
    for(int i = 0; i < 5;i++){
        for(int j = 0; j <= 600;j++){
            for(int k = 0; k <= 100;k++){
                for(int l = 0; l <= 100;l++){
                    if(dp[i][j][k][l] == 0) continue;
                    
                    for(int m = 0; m <= 100; m++){
                        dp[i+1][j+m][min(k,m)][max(l,m)] += dp[i][j][k][l];
                    }
                    
                }
            }
        }
    }
    for(int j = 0; j <= 600;j++){
        for(int k = 0; k <= 100;k++){
            for(int l = 0; l <= 100;l++){
                if(j-k-l==FX){
                    res += dp[5][j][k][l];
                }
            }
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
