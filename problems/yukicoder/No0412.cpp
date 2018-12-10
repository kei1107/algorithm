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
 <url:https://yukicoder.me/problems/no/412>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 dp[i][j] := i番目のレジャーシートを見たとき、現在の条件を満たす状態がjのとき
 の場合の数としてdpすればいい
 ================================================================
 */

ll solve(){
    ll res = 0;
    vector<ll> BCD(3);
    for(auto& in:BCD) cin >> in;
    sort(BCD.begin(),BCD.end());
    int N; cin >> N;
    vector<ll> E(N); for(auto& in:E) cin >> in;
    vector<vector<ll>> dp(N+1,vector<ll>(8,0));
    dp[0][0] = 1;
    for(int i = 0; i < N;i++){
        for(int j = 0; j < 8;j++){
            if(dp[i][j] == 0) continue;
            dp[i+1][j] += dp[i][j];
            int next = j;
            for(int k = 2; k >= 0; k--){
                if(E[i] >= BCD[k]){
                    for(int l = k; l >= 0;l--){
                        if((next>>l)&1) continue;
                        next += (1<<l);
                        break;
                    }
                    break;
                }
            }
            dp[i+1][next] += dp[i][j];
        }
    }
    res = dp[N][7];
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
