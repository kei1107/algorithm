 #include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:https://www.ioi-jp.org/joi/2008/2009-yo-prob_and_sol/2009-yo-t4/2009-yo-t4.html>
問題文============================================================
冬の寒いある日，JOI太郎君は広場にはった薄氷を割って遊ぶことにした．
広場は長方形で， 東西方向に m 個， 南北方向に n 個， つまり， m × n の区画に区切られている．
また， 薄氷が有る区画と無い区画がある． JOI太郎君は，次のルールにしたがって，薄氷を割りながら区画を移動することにした．
薄氷があるどの区画からも薄氷を割り始めることができる．
東西南北のいずれかの方向に隣接し， まだ割られていない薄氷のある区画に移動できる．移動した先の区画の薄氷をかならず割る．
JOI太郎君が薄氷を割りながら移動できる区画数の最大値を求めるプログラムを作成せよ．
ただし， 1 ≦ m ≦ 90，1 ≦ n ≦ 90 である． 与えられる入力データでは， 移動方法は20万通りを超えない．
=================================================================
解説=============================================================
問題文にもあるように移動方法は20万通り(2*10^6)を超えないらしいので,貪欲に数え上げる
到達済のフラグ管理配列は、うまく使えば１つで全て使いまわすことが可能
================================================================
*/
vector<vector<int>> masu;
vector<vector<int>> checked;

int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
ll dfs(ll x, ll y, ll dep) {
	ll res = dep;
	for (int i = 0; i < 4;i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (masu[nx][ny] == 0) continue;
		if (checked[nx][ny] == 1)continue;
		checked[nx][ny] = 1;
		res = max(res, dfs(nx, ny, dep + 1));
		checked[nx][ny] = 0;
	}
	return res;
}

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	ll m, n;
    while(cin >> m >> n,m){
	masu.assign(n + 2, vector<int>(m + 2, 0));
	checked.assign(n + 2, vector<int>(m + 2, 0));
	for (int i = 1; i <= n;i++) for (int j = 1; j <= m;j++) cin >> masu[i][j];
	ll res = 0;
	for (int i = 1;i <= n;i++) {
		for (int j = 1; j <= m;j++) {
			if (masu[i][j] == 0)continue;
			checked[i][j] = 1;
			res = max(res, dfs(i, j, 1));
			checked[i][j] = 0;
		}
	}
	cout << res << endl;
    }
	return 0;
}
