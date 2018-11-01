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
 <url:https://yukicoder.me/problems/no/302>
 問題文============================================================
 =================================================================
 解説=============================================================
 Nが小さい時は普通にdp
 
 Nが大きい場合は、
 ダイスについて調べてみると次第に正規分布に確率が近づく事がわかるので
 実際に積分計算を行う
 https://ja.wikipedia.org/wiki/%E6%AD%A3%E8%A6%8F%E5%88%86%E5%B8%83
 ================================================================
 */

typedef long double ld;
ld solve(){
    ld res = 0;
    ll N,L,R; cin >> N >> L >> R;
    
    L = min(6*N,max(N,L));
    R = min(6*N,R);
    
    if(N <= 9000){ // Nが小さい場合
        vector<vector<ld>> dp(2,vector<ld>(6*N+1));
        int cur = 0,next = 1;
        dp[cur][0] = 1;
        for(int i = 0; i < N;i++){
            for(int j = i; j <= 6*i; j++){
                for(int x = 1; x <= 6;x++){
                    dp[next][j+x] += dp[cur][j]/6.0;
                }
                dp[cur][j] = 0;
            }
            swap(cur,next);
        }        res = accumulate(dp[cur].begin()+L,dp[cur].begin()+R+1,0.0);
    }else{
        ld mu = 3.5*N;
        ld var = 35.0*N/12.0;
        res = (erf((R+0.5-mu)/sqrt(2*var))-erf((L-0.5-mu)/(sqrt(2*var))))/2.0;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(12) << solve() << endl;
    return 0;
}
