#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:https://www.ioi-jp.org/camp/2007/2007-sp-tasks/2007-sp-day2_21.pdf>
問題文============================================================
国際情報オリンピックが日本で開かれることとなり，世界の選手達を歓迎するため，
空港から宿泊施設までの道沿いにある高層ビルを飾りつけることにした．
ある著名なデザイナーにデザインを依頼したところ，飾りつけに利用するビルは，
空港から宿泊施設に向けて高くなっていく必要があると言った．つまり，
飾りつけに利用するビルの高さを，空港に近いものから順に h1, h2, h3, · · · とおくと，
h1 < h2 < h3 < · · · となっていなければならない．できるだけ飾りつけを華やかにするため，
飾りつけに利用するビルの数をできるだけ多くしたい．
入力として全てのビルの高さが与えられたとき
利用することのできるビルの数の最大値を計算するプログラムを作れ．
=================================================================
解説=============================================================
単なる単調増加部分列
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	ll n; cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n;i++) cin >> a[i];
	vector<ll> res(n, INF);
	for (int i = 0; i < n;i++) {
		*lower_bound(res.begin(), res.end(), a[i]) = a[i];
	}
	cout << (lower_bound(res.begin(), res.end(), INF) - res.begin()) << endl;
	return 0;
}