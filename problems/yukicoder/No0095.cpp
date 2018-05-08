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
 <url:https://yukicoder.me/problems/no/95>
 問題文============================================================
 1からNまでのN個のノードからなる無向グラフが存在する
 ノードkは2^(k-1)-1個のコインが存在する
 
 最初ノード１から始まり、最大でK回隣接ノードへ移動可能な時、収集可能な最大コイン数を求めよ
 ノード1へ再び戻ってくる必要な無い
 =================================================================
 解説=============================================================
 
 こういったノードごとの得点差が大きい場合は、できる限り大きい得点を取って行った方がいい
 
 ∵ 2^(k-1)-1 > Σ(n=1..k-1)(2^(n-1)-1)
 
 よって、Kの制約が小さいことを利用して、大きいノードから順番に取って行った時に条件を満たす
 ことができるかどうかをbitdpによって求めて行けば良い
 
 ================================================================
 */

ll check(vector<ll>& l,vector<vector<ll>>& G){
    ll res = LINF;
    ll n = l.size();
    vector<vector<ll>> dp(1<<n,vector<ll>(n,LINF));
    dp[1][0] = 0;
    for(int i = 1; i < (1<<n);i++){
        for(int j = 0; j < n; j++){
            if(dp[i][j] == LINF) continue;
            for(int k = 0; k < n;k++){
                if((i>>k)&1) continue;
                dp[i|(1<<k)][k] = min(dp[i|(1<<k)][k],dp[i][j]+G[l[j]][l[k]]);
            }
        }
    }
    res = *min_element(dp[(1<<n)-1].begin(), dp[(1<<n)-1].end());
    return res;
}
ll solve(){
    ll res = 0;
    ll N,M,K; cin >> N >> M >> K;
    vector<vector<ll>> G(N,vector<ll>(N,LINF));
    for(int i = 0; i < N;i++) G[i][i] = 0;
    for(int i = 0; i < M;i++){
        ll u,v; cin >> u >> v; u--; v--;
        G[u][v] = G[v][u] = 1;
    }
    for(int i = 0; i < N;i++) for(int j = 0; j < N;j++) for(int k = 0; k < N;k++)
        G[j][k] = min(G[j][k],G[j][i]+G[i][k]);
    
    vector<ll> l; l.push_back(0);
    for(ll x = N-1; x > 0; x--){
        if(l.size() > K) break;
        l.push_back(x);
        if(check(l,G) > K) l.pop_back();
    }
    for(auto v:l) res += (1LL<<v) - 1;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
