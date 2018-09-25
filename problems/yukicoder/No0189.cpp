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
 <url:https://yukicoder.me/problems/no/189>
 問題文============================================================
 =================================================================
 解説=============================================================
 桁dpを行う
 
 MについてとDについてそれぞれ
 dp[桁数][最大値未満が確定][桁和] := 条件を満たすものの総数
 とした桁dpを行う
 
 あとで、Mに対応したdpとDに対応したdpに対して桁和が等しいものの個数を数え上げれば良い
 ================================================================
 */
const ll MOD = 1e9+9;
// dp[MかDか][桁数][最大値未満が確定][桁和]
ll dp[2][202][2][2000];
void calc(int id,string& S){
    dp[id][0][0][0] = 1;
    for(int i = 0; i < S.length();i++){
        for(int j = 0; j < 2;j++){
            for(int k = 0; k < 2000;k++){
                if(dp[id][i][j][k]==0) continue;
                int lim = j?9:S[i]-'0';
                for(int l = 0; l <= lim;l++){
                    (dp[id][i+1][j|| l < lim][k+l] += dp[id][i][j][k])%=MOD;
                }
            }
        }
    }
}
ll solve(){
    ll res = 0;
    string M,D; cin >> M >> D;
    calc(0,M); calc(1,D);
    for(int i = 0; i < 2;i++){
        for(int j = 0; j < 2;j++){
            for(int k = 1; k < 2000;k++){
                (res += dp[0][M.length()][i][k]*dp[1][D.length()][j][k])%=MOD;
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
