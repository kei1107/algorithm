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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2312>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 sort済みのKについて見ると
 この問題は K[0] -> K[N-1]まで昇順に最適に選んで行き、
 K[N-1] -> K[0] まで降順に選んでいけば良いことがわかる。
 
 これはバイトニック巡回セールスマン問題を解くことになるため、
 先に費用について累積和で計算しておいて、バイトニック巡回セールスマン問題を解けば良い
 
 ================================================================
 */

ll N,M,L;
ll Cost(ll a,ll b,vector<ll>& cusum){
    if(a > b) swap(a,b);
    return (cusum[b]-cusum[a-1])/L;
}
ll solve(){
    ll res = LINF;
    cin >> N >> M >> L;
    vector<ll> K(N),S(M);
    for(auto& in:K) {cin >> in;}
    for(auto& in:S) cin >> in;
    vector<ll> cusum(M+1,0);
    for(int i = 0; i < M;i++) cusum[i+1] += cusum[i] + S[i];
    sort(K.begin(),K.end());

    vector<vector<ll>> dp(N,vector<ll>(N,0));
    for(int j = 1; j < N;j++){
        for(int i = 0; i < j; i++){
            if(i == 0&& j == 1){
                dp[i][j] = Cost(K[i],K[j],cusum);
            }else if(i < j - 1){
                dp[i][j] = dp[i][j-1] + Cost(K[j-1],K[j],cusum);
            }else{
                dp[i][j] = LINF;
                for(int k = 0; k < i; k++){
                    dp[i][j] = min(dp[i][j],dp[k][i] + Cost(K[k],K[j],cusum));
                }
            }
        }
    }

    for(int k = 0; k < N-1;k++){
        res = min(res,dp[k][N-1]+Cost(K[k],K[N-1],cusum));
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
