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
<url:>
問題文============================================================

=================================================================

解説=============================================================
メモ化再帰
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
