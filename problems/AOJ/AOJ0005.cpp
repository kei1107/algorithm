#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0005>
問題文============================================================
 正の整数 a,b を入力し、a と b の最大公約数と最小公倍数を出力するプログラムを作成して下さい。
=================================================================

解説=============================================================
いや、これは、もう、やるだけでしょ
================================================================
*/
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll a,b;
    while(cin >> a >> b){
        ll GCDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD = gcd(a,b);
        cout << GCDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD << " " << a/GCDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD*b<< endl;
    }
	return 0;
}
