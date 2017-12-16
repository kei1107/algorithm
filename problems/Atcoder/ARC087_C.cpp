#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:https://beta.atcoder.jp/contests/arc087/tasks/arc087_a>
問題文============================================================
 長さN(1<=N<=10^5)の正整数の数列a( 1<= ai <= 10^9)が与えられる
 
 このとき、数列を a の各要素xについてaに値xがちょうどx個含まれる
 という条件を満たすために取り除くべき要素の最小個数を求めよ
=================================================================

解説=============================================================
連想配列でハイ
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    int N; cin >> N;
    map<int,int> m;
    for(int i = 0; i < N;i++){
        int a; cin >> a;
        m[a]++;
    }
    ll res = 0;
    for(auto v:m){
        res += (v.first <= v.second)? v.second - v.first : v.second;
    }
    cout << res << endl;
	return 0;
}
