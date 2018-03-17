#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://arc064.contest.atcoder.jp/tasks/arc064_a>
問題文============================================================
 N 個の箱が横一列に並んでいます。 最初、左から i 番目の箱には ai 個のキャンディが入っています。
 
 すぬけ君は次の操作を好きな回数だけ行うことができます。
 
 キャンディが 1 個以上入っている箱をひとつ選び、その箱のキャンディを 1 個食べる。
 すぬけ君の目標は次の通りです。
 
 どの隣り合う 2 つの箱を見ても、それらの箱に入っているキャンディの個数の総和が x 以下である。
 目標を達成するために必要な操作回数の最小値を求めてください。
=================================================================

解説=============================================================

 左から二つずつ
 a[i] と a[i+1] を見た時、
 最適に飴を取っていくには、a[i+1]にある飴をできるだけ多く取っていけば良い
 
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N,x; cin >> N >> x;
    vector<ll> a(N);
    for(auto& in:a) cin >> in;
    ll ans = 0;
    for(int i = 1;i <N;i++){
        if(a[i] > x){
            ans += a[i]-x; a[i] = x;
        }
        if(a[i-1] > x){
            ans += a[i-1] - x; a[i-1] = x;
        }
        ll tmp = a[i] + a[i-1];
        if(tmp > x){
            ans += tmp - x;
            a[i] -= min(tmp-x,a[i]);
        }
    }
    cout << ans << endl;
	return 0;
}
