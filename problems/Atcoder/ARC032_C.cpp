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
 <url:https://arc032.contest.atcoder.jp/tasks/arc032_3?lang=en>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */

void solve(){
    int N; cin >> N;
    vector<vector<pii>> G(1000005);
    vector<pii> ab(N);
    for(int i = 0; i < N;i++){
        int a,b; cin >> a >> b;
        ab[i] = {a,b};
        G[b].push_back(pii(a,i+1));
    }
    vector<pii> dp(1000005,make_pair(0, INF)); // 最大時間、最小番号
    for(int i = 1000000; i >= 0; i--){
        dp[i] = min(dp[i],dp[i+1]);
        for(auto p:G[i]){
            dp[p.first] = min(dp[p.first],make_pair(dp[i].first-1,p.second));
        }
    }
    vector<int> ans;
    int now = 0;
    while(dp[now].second != INF){
        int idx = dp[now].second;
        ans.push_back(idx);
        now = ab[idx-1].second;
    }
    cout << ans.size() << endl;
    cout << ans << endl;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
