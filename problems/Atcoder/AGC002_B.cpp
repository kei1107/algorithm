#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://agc002.contest.atcoder.jp/tasks/agc002_b>
問題文============================================================
 N 個の箱があります。 箱は 1 から N まで番号が振られています。
 最初、1 番目の箱には赤いボールが 1 個入っています。
 また、2～N 番目の箱には白いボールが 1 個ずつ入っています。
 
 高橋君は M 回の操作を順に行います。
 i 回目の操作では、xi 番目の箱から適当なボールを 1 個選び、それを yi 番目の箱へ移します。
 
 高橋君がすべての操作を終えた後、赤いボールが入っている可能性のある箱は何個か求めてください。
=================================================================

解説=============================================================

 単純に、箱に等しい数の配列を持っておき、その配列に{箱に入っているボールの数、赤いボールが入っている可能性があるか}
 で情報を持てば良い
 赤いボールが入っている可能性に関しては、その可能性がある箱からボールを移すときはその可能性を必ず移行し、
 箱に入っているボールの数が０の時に可能性が０となる
 
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N,M; cin >> N >> M;
    vector<pll> B(N,pll(1,0));
    B[0].second = 1;
    for(int i = 0; i < M;i++){
        ll x,y; cin >> x >> y;
        x--; y--;
        if(B[x].second == 1){
            B[y].second = 1;
        }
        B[y].first++;
        B[x].first--;
        if(B[x].first == 0) B[x].second = 0;
    }
    ll ans = 0;
    for(int i = 0; i < N;i++) ans += B[i].second;
    cout << ans << endl;
	return 0;
}
