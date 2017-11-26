#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:https://www.ioi-jp.org/camp/2008/2008-sp-tasks/2008-sp_tr-day1_20.pdf>
問題文============================================================
根を０とした木構造が与えられる。
各辺にはコストが与えられており、根から子を辿って行った時のそのコストが最大となる時の値を求める
根を除いた頂点数n(<=100000), i番目の頂点の親をsi(0<=si<i), コストai(-100<=ai<=100)
=================================================================
解説=============================================================

深さ優先探索で辿っていけばok
出力コストが負になりうるため、初期化等で0にしないように注意
================================================================
*/

vector<int> C;
vector<vector<int>> G;
vector<int> memo;
int dfs(int n) {
	int res = C[n];
	for (auto next : G[n]) {
		res += max(0, dfs(next));
	}
	return (memo[n] = res);
}

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	int N; cin >> N;
	C.assign(N + 1, 0);
	G.assign(N + 1, vector<int>());
	memo.assign(N + 1, 0);
	for (int i = 1; i <= N;i++) {
		int v, c; cin >> v >> c;
		G[v].push_back(i);
		C[i] = c;
	}
	dfs(0);
	cout << *max_element(memo.begin()+1, memo.end()) << endl;
	return 0;
}
