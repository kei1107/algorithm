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
 <url:https://yukicoder.me/problems/no/196>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 木上でdpを行う
 ある頂点にいる時
 dp[i] := 色を塗った頂点数がiとなる場合の数
 として葉から順にdpを行っていけば良い
 
 ここで、一見,O(N^3)だが、
 ある頂点とその頂点の子供分までしかiを見る必要がなく
 O(N^2で)計算が可能
 ================================================================
 */

ll N,K;
vector<vector<ll>> G;
vector<ll> child;

const ll MOD = 1e9+7;
ll child_init(ll n,ll pre){
    ll now = 1;
    for(ll next:G[n]){
        if(pre == next) continue;
        now += child_init(next, n);
    }
    return child[n] = now;
}

// solver 1
vector<pll> rec(ll n,ll pre){
    vector<ll> dp(N+1);
    dp[0] = 1;
    for(ll next:G[n]){
        if(pre == next) continue;
        auto T = rec(next,n);
        for(ll i = N; i >= 0; i--){
            if(dp[i] == 0) continue;
            for(auto p:T){
                if(p.first == 0) continue;
                (dp[i+p.first] += dp[i]*p.second)%=MOD;
            }
        }
    }
    dp[child[n]] = 1;
    vector<pll> ret;
    for(int i = 0; i <= N;i++){
        if(dp[i] == 0) continue;
        ret.push_back({i,dp[i]});
    }
    return ret;
}

// solver 2
vector<ll> rec2(ll n,ll pre){
    vector<ll> dp(N+1);
    dp[0] = 1;
    for(ll next:G[n]){
        if(pre == next) continue;
        auto T = rec2(next,n);
        for(ll i = child[n]; i >= 0; i--){
            if(dp[i] == 0) continue;
            for(ll j = 1; j <= child[next];j++){
                if(T[j] == 0) continue;
                (dp[i+j] += dp[i]*T[j])%=MOD;
            }
        }
    }
    dp[child[n]] = 1;
    return dp;
}
ll solve(){
    cin >> N >> K;
    G.resize(N);
    child.resize(N);
    for(int i = 0; i < N-1;i++){
        ll a,b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    child_init(0, -1);
    ll res = 0;
//    auto T = rec(0,-1);
//    for(auto p :T){
//        if(p.first==K) res = p.second;
//    }
    auto T2 = rec2(0,-1);
    res = T2[K];
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
