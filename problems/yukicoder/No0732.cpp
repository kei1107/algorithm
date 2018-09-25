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
 <url:https://yukicoder.me/problems/no/732>
 問題文============================================================
 =================================================================
 解説=============================================================
 嘘解法
 無理やりやったら通った
 dp[i][j]:=i個の素数を足してその和がjになる時の個数
 でdp、普通にやったらTLEだけど色々といじるとギリギリ通る
 ================================================================
 */

const ll MAX_PRIME = 500050;
vector<int> primes;
vector<int> is_prime(MAX_PRIME + 1,true);
void init_primes(){
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i <= MAX_PRIME;i++){
        if(is_prime[i]){
            primes.push_back(i);
            for(int j = i*2; j <= MAX_PRIME; j+=i) is_prime[j] = false;
        }
    }
}

int dp[4][MAX_PRIME];

ll solve(){
    init_primes();
    ll res = 0;
    ll N; cin >> N;
    dp[0][0] = 1;

    for(int i = 0; i < primes.size();i++){
        if(N < primes[i]) continue;

        int j = 2;
        for(int k = 2*primes[i]; k >= 0;k--){
            if(dp[j][k] == 0) continue;
            dp[j+1][k+primes[i]] += dp[j][k];
        }
        j = 1;
        for(int k = primes[i]; k >= 0; k--){
            if(dp[j][k] == 0) continue;
            dp[j+1][k+primes[i]] += dp[j][k];
        }
        j = 0;
        dp[j+1][primes[i]] += dp[j][0];
    }
    for(int i = 0; i <= 3*N;i++){
        if(is_prime[i]){
            res += dp[3][i];
        }
    }

    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
