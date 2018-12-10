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
 <url:https://yukicoder.me/problems/no/385>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */

const ll MAX_PRIME = 10000;
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

ll solve(){
    ll res = 0;
    init_primes();
    
    int M,N; cin >> M >> N;
    vector<int> C(N); for(auto& in:C) cin >> in;
    
    vector<vector<int>> dp(N+1,vector<int>(M+1,-1));
    dp[0][M] = 0;
    for(int i = 0; i < N;i++){
        for(int j = 0; j <= M;j++){
            if(dp[i][j] == -1) continue;
            dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
            for(int k = 0; k <= j;k++){
                if(j < C[i]*k) break;
                dp[i+1][j-C[i]*k] = max(dp[i+1][j-C[i]*k],dp[i][j]+k);
            }
        }
    }
    for(int j = 0; j <= M;j++){
        if(is_prime[j]){
            res += max(dp[N][j],0);
        }
    }
    res += M/(*min_element(C.begin(), C.end()));
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
