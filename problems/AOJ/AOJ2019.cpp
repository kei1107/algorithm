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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2019&lang=jp>
 問題文============================================================
 =================================================================
 解説=============================================================
 期待値の大きいものから順に処理して行けば良い
 ================================================================
 */
ll N,M;
ll solve(){
    ll res = 0;
    vector<pll> dp(N);
    for(auto& in:dp) cin >> in.first >> in.second;
    sort(dp.begin(),dp.end(),[](const pll& o1,const pll& o2){return o1.second > o2.second;});
    for(int i = 0; i < N;i++){
        ll X = min(dp[i].first,M);
        M -= X;
        dp[i].first -= X;
        res += dp[i].first*dp[i].second;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    while(cin >> N >> M,N|M){
        cout << solve() << endl;
    }
    return 0;
}
