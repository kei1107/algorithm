#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://agc013.contest.atcoder.jp/tasks/agc013_b>
問題文============================================================
 N 頂点 M 辺の、連結な単純無向グラフが与えられます。
 頂点には 1 から N までの番号がついており、辺には 1 から M までの番号がついています。
 辺 i は、頂点 Ai と頂点 Bi を結んでいます。 次の条件を満たすパスを 1 つ見つけて、出力してください。
 
 2 個以上の頂点を通る
 同じ頂点を 2 度以上通らない
 パスの少なくとも一方の端点と直接辺で結ばれている頂点は、必ずパスに含まれる
 
 ただし、この問題の制約の下で、このようなパスが必ず存在することが証明できます。
 また、あり得る答えのうちどれを出力しても構いません。
 
=================================================================

解説=============================================================

 とりあえず、適当に一本のパスを見て
 その端点につながる頂点であって全体のパスに含まれるかどうかを判定する。
 もし、含まれない頂点があれば、それを新たな端点として再度判定を繰り返す
 
 そうすればいずれ、次頂点にいけなくなる => 次頂点がない or すでに次頂点がパス内部に含まれている
 
 ということになるため、ひたすら判定を繰り返せばいい
 
================================================================
*/

void solve(){
    ll N,M; cin >> N >> M;
    vector<ll> A(M),B(M);
    for(int i = 0; i < M;i++){
        cin >> A[i] >> B[i];
        A[i]--; B[i]--;
    }
    vector<vector<ll>> G(N);
    for(int i = 0; i < M;i++){
        G[A[i]].push_back(B[i]); G[B[i]].push_back(A[i]);
    }
    vector<int> used(N,0);
    ll l = 0, r = G[0][0];
    used[l] = used[r] = 1;
    deque<ll> deq; deq.push_front(l); deq.push_back(r);
    while(true){
        bool f = true;
        for(auto v:G[l]){
            if(used[v]) continue;
            f = false; used[v] = 1;
            deq.push_front(v); l = v; break;
        }
        if(!f)continue;
        for(auto v:G[r]){
            if(used[v])continue;
            f = false; used[v] = 1;
            deq.push_back(v); r = v; break;
        }
        if(f) break;
    }
    vector<ll> ans(deq.begin(),deq.end());
    cout << ans.size() << endl;
    for(int i = 0; i < (int)ans.size();i++){
        cout << ans[i]+1 << " \n"[i == ans.size()-1];
    }
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    solve();
	return 0;
}
