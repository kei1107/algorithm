#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <bitset>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <numeric>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <deque>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:http://poj.org/problem?id=3045>
問題文============================================================
 牛がN匹いる．i番目の牛は重さがw[i]で，強さがs[i]であることがわかっている．
 この牛でタワーをつくりたい．タワーは牛が別の牛一頭にのることを繰り返してつくられる．
 この時，牛iの危険度は (牛iの上に乗っている牛の重さの合計) - (牛iの強さ) で求められる．
 N匹の牛を使って作るとき，牛の危険度の最大値を最小化したい．
=================================================================

解説=============================================================
にぶたんカテゴリだけど、貪欲で解けちゃう
 
 考察を進めると wとsの和を基準としてソートし、その数列を順番に見ていけば最適となる
================================================================
*/
vector<pll> WS;
bool comp(pll i,pll j){
    return i.first + i.second > j.first + j.second;
}

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N; cin >> N;
    ll W_sum = 0;
    WS.resize(N);
    for(int i = 0; i < N;i++){
        cin >> WS[i].first >> WS[i].second;
        W_sum += WS[i].first;
    }
    
    sort(WS.begin(),WS.end(),comp);

    ll ans = -(LINF);
    for(int i = 0; i < N;i++){
        W_sum -= WS[i].first;
        ans = max(ans,W_sum - WS[i].second);
    }
    cout << ans << endl;
	return 0;
}
