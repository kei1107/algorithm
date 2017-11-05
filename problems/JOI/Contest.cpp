#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:https://www.ioi-jp.org/camp/2010/2010-sp-tasks/2010-sp-day4_23.pdf>
問題文============================================================
コンテストの参加者は N 人で，問題が M 問で，競技時間が T 秒である．
参加者には 1 から N までの番号が割り振られている．
問題にも 1 から M までの番号が振られている．
このコンテストでは，各参加者は問題毎に，問題文を閲覧し，問題を解き，解答のソースコードを提出する．
競技は時刻 0 からはじまり，時刻 T で終了する．
参加者が問題を閲覧すると，時刻と参加者番号と問題番号がログに 1 件の情報として記録される．
参加者が解答ソースコードを提出すると，時刻と参加者番号と問題番号と解答ソースコードの正誤がログに 1 件の情報として記録される．
各参加者はコンテスト開始から 1 秒毎に「ある問題を閲覧する」か「ある問題のソースコードを提出する」のいずれかを
1 回行うことが出来る．閲覧前にその問題のソースコードを提出する事や，正解後に再度ソースコードを提出する事は出来ない．
参加者 j が問題 i を，時刻 Sij に閲覧し，wij 回の不正解のソースコードを提出後，
時刻 Eij に正解のソースコードを提出したときの得点は，
(pi − (Ei j − S i j) − 120wi j)
と X のうち大きい方
である．
ただし，pi は問題 i の配点，X は問題番号に依存しない正解した時の最低得点である．
競技終了までに，正解しなかった問題の得点は 0 点である．
各参加者の得点は，その参加者の問題毎の得点の合計である．
N, M, T, X, ログに含まれる情報の件数，各問題の配点，および，ログの内容が与えられたときに各参加
者の得点を計算するプログラムを作成せよ．
=================================================================
解説=============================================================

各参加者の行動は他の参加者へ影響を与えないため、単純に、
ある参加者のある問題に対するopen時間、wa回数、correct時間を保持し、
最後にその情報から得点を計算すればよい
================================================================
*/

struct problem {
	int open = -1;
	int wa = 0;
	int correct = -1;
	problem() :open(-1), wa(0), correct(-1) {}
};
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	int N, M, T, X, Y; cin >> N >> M >> T >> X >> Y;
	vector<int> p(M);
	for (int i = 0; i < M;i++) cin >> p[i];
	vector<vector<problem>> problems(N, vector<problem>(M));
	for (int i = 0; i < Y;i++) {
		int t, n, m; string com;
		cin >> t >> n >> m >> com;
		n--; m--;
		auto& P = problems[n][m];
		if (com == "open") {
			if (P.open == -1)P.open = t;
		}
		if (com == "correct") {
			if (P.correct == -1)P.correct = t;
		}
		if (com == "incorrect") {
			if (P.correct == -1) P.wa++;
		}
	}
	for (int i = 0; i < N;i++) {
		int res = 0;
		for (int j = 0; j < M;j++) {
			auto& P = problems[i][j];
			if (P.correct == -1) continue;
			res += max(p[j] - (P.correct - P.open) - 120 * P.wa, X);
		}
		cout << res << endl;
	}
	return 0;
}