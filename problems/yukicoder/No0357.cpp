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
 <url:https://yukicoder.me/problems/no/357>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 bitdp[state] := stateまで並べた時の最大コストとして
 
 bitdpすればいい
 ================================================================
 */

ll solve(){
    ll res = 0;
    ll N,M; cin >> N >> M;
    vector<vector<ll>> scores(N,vector<ll>(N));
    for(int i = 0; i < M;i++){
        ll u,v,score; cin >> u >> v >> score;
        scores[u][v] = score;
    }
    vector<ll> dp(1<<N);
    for(int b = 0; b < (1<<N); b++){
        for(int i = 0; i < N;i++){
            if((b>>i)&1) continue;
            ll add = 0;
            for(int j = 0; j < N;j++){
                if((b>>j)&1){
                    add += scores[j][i];
                }
            }
            dp[b | (1<<i)] = max(dp[b | (1<<i)],dp[b] + add);
        }
    }
    res = dp[(1<<N)-1];
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
