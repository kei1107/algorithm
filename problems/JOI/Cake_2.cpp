#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:https://www.ioi-jp.org/joi/2014/2015-ho/2015-ho.pdf>
問題文============================================================

円形のケーキがあり、N(1<=N<=2000)個のピースに切り分けられている。
ピースに1からNまで反時計回りに番号をつけた。ここでi番目のピースの大きさはAiする。

このN個をJOIくんとIOIちゃんで次のように分ける

1.
まず JOI くんが N 個のうちの好きな 1 つを選んで取る．

2.
その後，IOI ちゃんからはじめて IOI ちゃんと JOI くんが交互に残りのピースを 1 つずつ取っていく．
ただし，両隣のピースのうち少なくとも一方が既に取られているようなピースしか取ることができず，
取れるピースが複数あるときは，IOI ちゃんはそのうち最も大きいものを選んで取り，
JOI くんはそのうちで好きなものを選んで取ることができる．
JOI くんは，自分が最終的に取るピースの大きさの合計を最大化したい．
=================================================================
解説=============================================================

l ~ r までのピースが取り除かれている時点からJOIが得られるピースの大きさの最大
をメモ化再帰
================================================================
*/
ll res = 0;
ll N;
vector<ll> A;
vector<vector<ll>> memo;
ll rec(int l, int r, int cur, bool first) {
	if (first) {
		return rec((l - 1 + N) % N, (r + 1) % N, 1, false) + A[l];
	}
	if (l == r) {
		if (cur == 0) {
			if (memo[l][r] != 0)return memo[l][r];
			else return memo[l][r] = A[l];
		}
		else {
			return 0;
		}
	}

	if (cur == 0) {
		ll& res = memo[l][r];
		if (res != 0)return res;
		res = max(res, rec((l - 1 + N) % N, r, 1, false) + A[l]);
		res = max(res, rec(l, (r + 1) % N, 1, false) + A[r]);
		return res;
	}
	else {
		if (A[l] > A[r]) {
			return rec((l - 1 + N) % N, r, 0, false);
		}
		else {
			return rec(l, (r + 1) % N, 0, false);
		}
	}
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	cin >> N;
	A.assign(N, 0);
	memo.assign(N, vector<ll>(N, 0));
	for (auto& in : A) cin >> in;
	ll res = 0;
	for (int i = 0; i < N;i++) {
		res = max(res, rec(i, i, 0, true));
	}
	cout << res << endl;
	return 0;
}