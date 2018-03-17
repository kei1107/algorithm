#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://arc079.contest.atcoder.jp/tasks/arc079_a>
問題文============================================================
 高橋キングダムには、高橋諸島という、N 個の島からなる諸島があります。
 便宜上、これらの島を島 1、島 2、 ...、島 N と呼ぶことにします。
 
 これらの諸島の間では、船の定期便が M 種類運行されています。
 定期便はそれぞれ 2 つの島の間を行き来しており、i 種類目の定期便を使うと、
 島 ai と島 bi の間を行き来する事ができます。
 
 すぬけくんは今島 1 にいて、島 N に行きたいと思っています。
 しかし、島 1 から島 N への定期便は存在しないことがわかりました。
 なので、定期便を 2 つ使うことで、島 N に行けるか調べたいと思っています。
 
 これを代わりに調べてあげてください。

=================================================================

解説=============================================================
IDDFSの要領
 
 深さ2まで調べて目的地に到達しているかどうか確認すれば良い
================================================================
*/
ll N,M;
vector<vector<ll>> G;

bool f = false;
void dfs(int n,int x){
    if(n == N - 1) f = true;
    if(x == 2) return;
    if(f) return;
    for(auto v: G[n]) dfs(v,x+1);
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    cin >> N >> M;
    G.resize(N);
    for(int i = 0; i < M;i++){
        ll a,b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(0,0);
    if(f){
        cout << "POSSIBLE" << endl;
    }else{
        cout << "IMPOSSIBLE" << endl;
    }
	return 0;
}
