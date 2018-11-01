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
 <url:https://yukicoder.me/problems/no/247>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 dp[i] := iを作るときのΣxiの最小値
 としてdpしてやればok
 ================================================================
 */
ll solve(){
    ll res = 0;
    ll C; cin >> C;
    ll N; cin >> N;
    vector<ll> a(N); for(auto& in:a) cin >> in;
    vector<int> dp(C+1,INF);
    dp[0] = 0;
    for(int i = 0; i <= C;i++){
        if(dp[i] == INF) continue;
        for(int j = 0; j < N;j++){
            if(i+a[j]<=C){dp[i+a[j]] = min(dp[i+a[j]],dp[i]+1);}
        }
    }
    res = dp[C];
    if(res==INF) res = -1;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
