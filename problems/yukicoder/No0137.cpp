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
 <url:https://yukicoder.me/problems/no/137>
 問題文============================================================
 =================================================================
 解説=============================================================
 いや、思いつかんわ
 
 http://mayokoex.hatenablog.com/entry/2015/12/22/232742
 ================================================================
 */



const ll MOD = 1234567891; // prime
ll dp[500*101];
ll solve(){
    ll res = 0;
    ll N,M; cin >> N >> M;
    vector<ll> A(N); for(auto& in:A) cin >> in;
    dp[0] = 1;
    while(M){
        for(int i = 0; i < N;i++){
            for(int j = 100*500; j >= A[i]; j--){
                (dp[j] += dp[j-A[i]])%=MOD;
            }
        }
        for(int i = 0; i <= 50*500;i++) dp[i] = dp[i*2+M%2];
        for(int i = 0; i <= 50*500;i++) dp[i+50*500] = 0;
        M/=2;
    }
    res = dp[0];
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
