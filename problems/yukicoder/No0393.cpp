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
 <url:https://yukicoder.me/problems/no/393>
 問題文============================================================
 =================================================================
 解説=============================================================
 短い順に竹を作っていったほうが明らかに最適
 
 ここで、i番目までにどの長さを片方の竹で用いルカ決めれば
 もう片方の竹の必要長さは一意に決まる。
 
 あとはdpの要領で計算すればいい
 ================================================================
 */

ll solve(){
    ll res = 0;
    ll n[2]; cin >> n[0] >> n[1];
    ll m; cin >> m;
    vector<ll> A(m); for(auto &in:A) cin >> in;
    sort(A.begin(),A.end());
    
    vector<ll> cusum(m+1);
    for(int i = 0; i < m;i++) cusum[i+1] = cusum[i] + A[i];
    vector<vector<int>> dp(m+1,vector<int>(n[0]+1));
    dp[0][0] = true;
    for(ll i = 0; i < m;i++){
        for(int j = 0; j <= n[0];j++){
            if(dp[i][j]){
                if(j+A[i]<=n[0]){
                    res = max(res,i+1);
                    dp[i+1][j+A[i]] = true;
                }
                if(cusum[i]-j+A[i]<=n[1]){
                    res = max(res,i+1);
                    dp[i+1][j] = true;
                }
            }
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    int n; cin >> n;
    while(n--){ cout << solve() << endl; }
    return 0;
}
