#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://abc088.contest.atcoder.jp/tasks/abc088_c>
問題文============================================================

 3×3 のグリッドがあります.
 上から i 番目で左から j 番目のマスを (i,j) で表すとき, マス (i,j) には数 ci,j が書かれています.
 高橋君によると, 整数 a1,a2,a3,b1,b2,b3 の値が決まっており,
 マス (i,j) には数 ai+bj が書かれているらしいです.
 高橋君の情報が正しいか判定しなさい.
=================================================================

解説=============================================================

 a[1] = 0 と決めうちしてしまえば他の全てのa,bがもとまる。
 あとは矛盾していないかどうか確かめれば良い
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll c[4][4];
    for(int i = 1; i <= 3;i++)for(int j = 1; j <= 3;j++) cin >> c[i][j];
    ll a[4],b[4];
    a[1] = 0;
    b[1] = c[1][1] - a[1];
    b[2] = c[1][2] - a[1];
    b[3] = c[1][3] - a[1];
    a[2] = c[2][2] - b[2];
    a[3] = c[3][3] - b[3];
    for(int i = 1; i <= 3;i++){
        for(int j = 1; j<= 3;j++){
            if(c[i][j] != a[i]+b[j]){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
	return 0;
}
