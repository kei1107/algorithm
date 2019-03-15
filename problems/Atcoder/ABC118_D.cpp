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
 <url:https://atcoder.jp/contests/abc118/tasks/abc118_d>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 dp[i] := マッチ棒をi本消費したときの最大値
 
 としてdpする。
 64bitを超えるので、多倍長で計算するか、文字列として持って計算する。
 ================================================================
 */

ll cost[] = {INF,2,5,5,4,5,6,3,7,6};
string dp[10010];
template<class Type>
Type solve(Type res = Type()){
    fill(dp,dp+10010,"#");
    ll N,M; cin >> N >> M;
    vector<ll> A(M); for(auto & in:A) cin >> in;
    dp[0] = "";
    for(int i = 0; i < N;i++){
        if(dp[i]=="#") continue;
        for(int j = 0; j < M;j++){
            string S = dp[i] + to_string(A[j]);
            ll C = cost[A[j]];
            
            if(dp[i+C] == "#"){
                dp[i+C] = S;
            }else{
                if(dp[i+C].length() < S.length()){
                    dp[i+C] = S;
                }else if(dp[i+C].length()==S.length()){
                    dp[i+C] = max(dp[i+C],S);
                }
            }
        }
    }
    res = dp[N];
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<string>() << endl;
    return 0;
}
