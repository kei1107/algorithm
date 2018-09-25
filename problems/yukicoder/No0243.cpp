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
 <url:https://yukicoder.me/problems/no/243>
 問題文============================================================
 =================================================================
 解説=============================================================
 解説見た。
 https://yukicoder.me/problems/no/243/editorial
 
 包除原理までは一瞬思いついたが、dpでの集合の構築が思い浮かばずに
 忘却の彼方に行ってしまった。
 ================================================================
 */

const ll MOD =1e9+7;
ll solve(){
    ll res = 0;
    int N; cin >> N;
    vector<ll> A(N); for(auto& in:A) cin >> in;
    
    vector<ll> fact(N+1);
    fact[0] = 1; for(int i = 1; i <=N;i++) (fact[i] = fact[i-1]*i)%=MOD;
    vector<ll> X(N);
    for(auto a:A) if(a < N) X[a]++;
    
    vector<ll> dp(N+1);
    dp[0] = 1;
    for(int i = 0; i < N;i++){
        for(int x = N; x >= 0; x--){
            if(dp[x]){
                (dp[x+1] += X[i]*dp[x])%=MOD;
            }
        }
    }
    for(int i = 0; i <= N;i++) (res += MOD + ((i%2)?-1:1)*dp[i]*fact[N-i]%MOD)%=MOD;
    
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
