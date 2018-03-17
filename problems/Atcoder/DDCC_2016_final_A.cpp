#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://ddcc2016-final.contest.atcoder.jp/tasks/ddcc_2016_final_a>
問題文============================================================
 半径 R cmのウェーハにダイシングという操作を行い、正方形のチップをいくつか作成することにしました。
 作成される正方形のチップの個数を求めてください。
 
 ウェーハとは、ある部品を作るのに使われる薄い円盤状の物体です。
 ダイシングという操作は、ウェーハの中心から C cm間隔で水平方向と垂直方向に切れ目を入れてウェーハを分割する操作です。
=================================================================

解説=============================================================

 第一象限に関して、マスの右上の座標が円の内部に含まれるかどうかを確認し、カウントする
 答えは　総数*4
 
 ps. 絶対2017のAの方が面倒だし、むずい
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    int R,C; cin >> R >> C;
    int cnt = 0;
    int T = (R + C - 1)/C;
    for(int i = 1; i <= T;i++){
        for(int j = 1; j<= T;j++){
            if(C*i*C*i + C*j*C*j <= R*R)cnt++;
        }
    }
    cout << cnt * 4 << endl;
	return 0;
}
