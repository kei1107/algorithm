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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1335>
 問題文============================================================
 
 N,K,Sが与えられる
 ここで N以下の数字で構成された、互いに異なるK個の整数かつ総和がSとなるような集合の
 総数を述べよ
 
 =================================================================
 解説=============================================================
 
 dp[i][j][k] := 数字iを加算するとき、これまでの集合の個数がjで総和がkである時の総数
 でdp
 ================================================================
 */
int N,K,S;
ll dp[22][12][200];
ll solve(){
    ll res = 0;
    fill(**dp,**dp+22*12*200,0);
    dp[1][0][0] = 1;
    for(int i = 1; i <= N;i++){
        for(int j = 0; j <= K;j++){
            for(int k = 0; k <= S; k++){
                if(dp[i][j][k] == 0) continue;
                dp[i+1][j][k] += dp[i][j][k];
                dp[i+1][j+1][k+i] += dp[i][j][k];
            }
        }
    }
    res = dp[N+1][K][S];
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    while(cin >> N >> K >> S,N){
        cout << solve() << endl;
    }
    return 0;
}
