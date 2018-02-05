#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1562>
問題文============================================================
 12以下の自然数 N が与えられるので、約数の個数がちょうど N 個であるような最小の自然数を求めよ。
=================================================================

解説=============================================================
貪欲
================================================================
*/

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N; cin >> N;
    for(int i = 1; i < 10000;i++){
        ll cnt = 0;
        for(int j = 1; j <= i;j++){
            if(i%j == 0) cnt++;
        }
        if(cnt == N){
            cout << i << endl;
            break;
        }
    }
	return 0;
}
