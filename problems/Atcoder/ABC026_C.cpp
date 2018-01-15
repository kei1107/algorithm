#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e16;

/*
<url:https://beta.atcoder.jp/contests/abc026/tasks/abc026_c>
問題文============================================================

 （略)
 
=================================================================

解説=============================================================
 
 部下と上司の関係を見て、上司から部下へ辺を貼る
 
 社長のちょくだいから部下へ頂点を再帰的に見ていき、
 部下がいれば（自身の頂点から次の頂点への辺があれば）
     さらに部下を見て行き、その部下たちの中の最大給料と最小給料を保持し、
     最終的に 最大給料+最小給料+1 を返却
 部下がいなければ（自身の頂点が木の根であれば）、給料１を返却
 
 としていけば良い、条件として、上司は一人しかいないとされているので、十分間に合う
 
================================================================
*/

ll solve(int n,vector<vector<int>> &G){
    ll res = 1;
    if(G[n].size() == 0) return res;
    
    ll Max = 0, Min = LINF;
    for(int i = 0; i < (int)G[n].size();i++){
        ll res = solve(G[n][i],G);
        Max = max(res,Max);
        Min = min(res,Min);
    }
    return Max + Min + 1;
}

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N; cin >> N;
    vector<vector<int>> G(N);
    for(int i = 1; i < N;i++){
        int b; cin >> b; b--;
        G[b].push_back(i);
    }
    cout << solve(0,G) << endl;
	return 0;
}
