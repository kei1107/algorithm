#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60
/*
<url:https://colopl2018-qual.contest.atcoder.jp/tasks/colopl2018_qual_c>
問題文============================================================
すぬけ君は、その日にこれまでに食べたどのカードに書かれた整数とも互いに素である整数の書かれたカードを食べたとき、喜ぶ。そうでないとき、悲しむ。

今日のカードショップには A 以上 B 以下の整数の書かれたカードが 1 枚ずつ売られています。 
あなたは、このうちの 0 枚以上の任意の枚数を購入し、すべてのカードをすぬけ君に与えることにしました。このとき、すぬけ君を 1 度でも悲しませてはいけません。
カードの買い方は何通りあるでしょうか。
=================================================================
解説=============================================================
貪欲全探索　気合
================================================================
*/
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }

ll A, B;
ll N;
ll res;
vector<vector<int>> check;
void dfs(ll dep,vector<int>& L) {
	if (dep > N) {
		res++;
		return;
	}
	bool f = true;;
	for (auto l : L) {
		if (check[l][dep] == 0) {
			f = false;
			break;
		}
	}
	auto tmp = L;
	dfs(dep + 1, tmp);
	if (f) {
		auto tmp = L;
		tmp.push_back(dep);
		dfs(dep + 1, tmp);
	}
}

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	cin >> A >> B;
	N = B - A;
	check.assign(N+1, vector<int>(N+1, 0));
	for (int i = 0; i <= N;i++) {
		for (int j = i + 1; j <= N;j++) {
			if (gcd(A + i, A + j) == 1) {
				check[i][j] = check[j][i] = 1;
			}
		}
	}
	vector<int> L;
	dfs(0, L);
	cout << res << endl;
	return 0;
}