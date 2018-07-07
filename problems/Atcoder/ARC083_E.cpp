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
 <url:https://beta.atcoder.jp/contests/arc083/tasks/arc083_c>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 各頂点は、その頂点を根とした部分木において白側および黒川での重みの和を持っているとする
 
 ここで、ある頂点を見たときその子が持っている白と黒の値は反対にしても問題ない
 
 よって、現在の頂点において重みXを満たすには子たちの持っている二つの値のどちらかを
 うまく足し合わせてX以下にすれば良い。
 また、次の親へ伝播させるためにもう片方の総和の値はできるだけ小さいほうがいい
 
 したがって、各頂点に関して その子が持っている二つの値をうまく足し合わせて
 {X以下、できるだけ小さい値}
 を構成すれば次の親へ{X,できるだけ小さい値}を伝えることができる
 
 したがって葉から順番に根までにおいて動的計画法を持ち行くことによって上記
 値を計算することができ、同時に重みの割り当て可能かどうかを判定することができる
 ================================================================
 */

pll rec(int n,ll& N,vector<vector<int>>& G,vector<ll>& X){
    pll ret = {0,0};
    int sz = (int)G[n].size();
    vector<pll> scores(sz);
    for(int i = 0; i < sz;i++){
        scores[i] = rec(G[n][i],N,G,X);
        if(scores[i].first == LINF) return {LINF,LINF};
    }
    vector<vector<ll>> dp(2,vector<ll>(X[n]+1,LINF));
    int cur = 0,next = 1;
    dp[cur][0] = 0;
    for(int i = 0; i < sz;i++){
        for(int j = 0;j <= X[n];j++){
            if(j+scores[i].first <= X[n]){
                dp[next][j+scores[i].first] = min(dp[next][j+scores[i].first],dp[cur][j]+scores[i].second);
            }
            if(j+scores[i].second <= X[n]){
                dp[next][j+scores[i].second] = min(dp[next][j+scores[i].second],dp[cur][j]+scores[i].first);
            }
            dp[cur][j] = LINF;
        }
        swap(cur,next);
    }
    auto minV = *min_element(dp[cur].begin(),dp[cur].end());
    if(minV == LINF) return {LINF,LINF};
    ret = {X[n],minV};
    return ret;
}
string solve(){
    string res;
    ll N; cin >> N;
    vector<vector<int>> G(N);
    for(int i = 1; i < N;i++){
        int P; cin >> P; P--;
        G[P].push_back(i);
    }
    vector<ll> X(N); for(auto& in:X) cin >> in;
    return res=(rec(0,N,G,X).first==LINF?"IMPOSSIBLE":"POSSIBLE");
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
