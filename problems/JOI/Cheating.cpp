#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:https://www.ioi-jp.org/camp/2008/2008-sp-tasks/2008-sp_tr-day2_21.pdf>
問題文============================================================

近年，日本情報オリンピックは受験者数が著しく増加したが，それにつれて不正行為を行う受験者も増えてしまい，問題となっている．
日本情報オリンピックの試験会場は長方形である．
座標軸をそれぞれ試験会場の壁に平行にとり，原点は試験会場の一つの隅とする．
情報オリンピック日本委員会は受験者の不正行為を自動で監視する装置を n 個製作した．
それぞれの監視装置は，x 軸方向の監視または y 軸方向の監視のいずれかに用いることができる．
	• 監視装置 i を x 軸方向の監視に用いるとき，監視装置 i は pi <= y <=pi + di の領域にいる受験者を監視する．
	• 監視装置 i を y 軸方向の監視に用いるとき，監視装置 i は pi <= x <=pi + di の領域にいる受験者を監視する．
ただし，di, pi の値は整数であり，それぞれの監視装置について個別に設定できるが，0 <=diで，
di が小さいほど精度よく監視することができる．使用しない監視装置があってもよい．

情報オリンピック日本委員会は，注意を要する受験者のリストを持っており，それらの受験者をできるだけ精度よく監視しようと考えた．
したがって，図 1 のように，
各々の受験者に対して x 軸方向に監視を行っている監視装置 1 つ以上と，
y 軸方向に監視を行っている監視装置 1つ以上により要注意の受験者を監視しなければならない．
さらに，全ての監視装置での di の最大値を dmax としたとき，dmax をできるだけ小さくしなければならない．
=================================================================
解説=============================================================

最大値の最小だで、にぶたんしたくなる。
よってニブタン。

判定するためのライトのおき方について、
問題文より、1つの頂点につきx軸方向及びy軸方向の両方から照らさなければならないでの
それぞれ独立に考えることができる。
よって各軸にソートして、小さい値から順番にライトを置いていけばよい

================================================================
*/
ll n, m;
struct Point {
	ll x;
	ll y;
	Point() {}
	Point(ll x, ll y) :x(x), y(y) {}
};

bool compX(const Point& p1, const Point& p2) {
	return (p1.x != p2.x) ? (p1.x < p2.x) : (p1.y < p2.y);
}

bool compY(const Point& p1, const Point& p2) {
	return (p1.y != p2.y) ? (p1.y < p2.y) : (p1.x < p2.x);
}

vector<Point> P, PX, PY;

bool check(ll d) {
	ll cam = 0;
	ll pre_xy = -LINF;
	for (int i = 0; i < m;i++) {
		if (PX[i].x - pre_xy >= 0 && PX[i].x - pre_xy <= d) continue;
		pre_xy = PX[i].x;
		cam++;
		if (cam > n) return false;
	}
	pre_xy = -LINF;
	for (int i = 0; i < m;i++) {
		if (PY[i].y - pre_xy >= 0 && PY[i].y - pre_xy <= d) continue;
		pre_xy = PY[i].y;
		cam++;
		if (cam > n) return false;
	}
	return true;
}

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	cin >> n >> m;
	P.resize(m);
	for (int i = 0; i < m;i++) {
		ll x, y; cin >> x >> y;
		P[i] = Point(x, y);
	}
	sort(P.begin(), P.end(), compX);
	PX = P;
	sort(P.begin(), P.end(), compY);
	PY = P;
	ll l = 0, r = LINF;
	while (true) {
		if (r == l)break;
		ll d = l + (r - l) / 2;
		if (check(d)) {
			r = d;
		}
		else {
			l = d + 1;
		}
	}
	cout << r << endl;
	return 0;
}