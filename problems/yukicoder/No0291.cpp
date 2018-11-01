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
 <url:https://yukicoder.me/problems/no/291>
 問題文============================================================
 =================================================================
 解説=============================================================
 難しいっぽい
 
 dp[何番目の文字][kまでできている個数][kuまで...][kur...][kuro] := kuroiまでできている個数
 
 でdpするっぽい
 
 L^5になる雰囲気があるが、100文字なので最大でも20個までしか見る必要がない
 ================================================================
 */

ll dp[2][21][21][21][21];
ll solve(){
    ll res = 0;
    string S; cin >> S;
    int L = (int)S.length();
    
    fill(****dp,****dp+2*21*21*21*21,-1);
    int cur = 0,next = 1;
    dp[cur][0][0][0][0] = 0;
    for(int _ = 0; _ < L;_++){
        for(int k = 0; k < 21;k++){
            for(int u = 0; u < 21;u++){
                for(int r = 0; r < 21;r++){
                    for(int o = 0; o < 21;o++){
                        if(dp[cur][k][u][r][o]==-1)continue;
                        ll i = dp[cur][k][u][r][o];
                        if(S[_]=='K'||S[_]=='?') if(k<20) dp[next][k+1][u][r][o]=max(dp[next][k+1][u][r][o],i);
                        if(S[_]=='U'||S[_]=='?') if(u<20&&k) dp[next][k-1][u+1][r][o]=max(dp[next][k-1][u+1][r][o],i);
                        if(S[_]=='R'||S[_]=='?') if(r<20&&u) dp[next][k][u-1][r+1][o]=max(dp[next][k][u-1][r+1][o],i);
                        if(S[_]=='O'||S[_]=='?') if(o<20&&r) dp[next][k][u][r-1][o+1]=max(dp[next][k][u][r-1][o+1],i);
                        if(S[_]=='I'||S[_]=='?') if(o){
                            res = max(res,i+1);
                            dp[next][k][u][r][o-1]=max(dp[next][k][u][r][o-1],i+1);
                        }
                        dp[next][k][u][r][o] = max(dp[next][k][u][r][o],i);
                        dp[cur][k][u][r][o] = -1;
                    }
                }
            }
        }
        swap(cur,next);
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
