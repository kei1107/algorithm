#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://arc088.contest.atcoder.jp/tasks/arc088_a>
問題文============================================================
 高橋君は、日頃の感謝を込めて、お母さんに数列をプレゼントすることにしました。
 お母さんにプレゼントする数列 A は、以下の条件を満たす必要があります。
 
 A は X 以上 Y 以下の整数からなる
 すべての 1≤i≤|A|−1 に対し、Ai+1 は Ai の倍数であり、かつ Ai+1 は Ai より真に大きい
 
 高橋君がお母さんにプレゼントできる数列の長さの最大値を求めてください。
=================================================================

解説=============================================================

 最大の長さを得る数式は, a[0] = Xであり、
 a[1] = 2*a[0]
 a[2] = 2*a[1]
 .
 .
 .
 a[N] = 2*a[N-1]
 となるものである
 
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll X,Y; cin >> X >> Y;
    ll ans = 0;
    while(X <= Y){
        ans++; X*=2;
    }
    cout << ans << endl;
	return 0;
}
