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
<url:http://poj.org/problem?id=3176>
問題文============================================================

 一番手前に1個、2段目に2個、... N段目にN個とボーリングのピンが並んでいる。(1<=N<=350)
 各ピンには倒した時のスコアが決まっている。
 一つピンを倒すと、次に倒れるピンは、次の段の最も近い二つのピンの内のどちらかになる。
 一投で最大何点取れるか?
 
=================================================================

解説=============================================================
メモ化再帰
 
あるピン以降に注目した時に取得できる最大得点をメモとして計算すれば良い
================================================================
*/
ll N;
vector<vector<ll> > pin;
vector<vector<ll> > memo;
ll dfs(int n,int at){
    ll& res = memo[n][at];
    if(res != -1) return res;
    if(n == N-1){
        return res = pin[n][at];
    }
    ll l = dfs(n+1,at);
    ll r = dfs(n+1,at+1);
    return res = pin[n][at] + max(l,r);
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    cin >> N;
    pin.resize(N);
    memo.resize(N);
    for(int i = 0; i < N;i++){
        memo[i].assign(i+1,-1);
        for(int j = 0; j < i+1;j++){
            ll x; cin >> x;
            pin[i].push_back(x);
        }
    }
    cout << dfs(0,0) << endl;
	return 0;
}
