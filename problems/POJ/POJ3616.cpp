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
 <url:http://poj.org/problem?id=3616>
 問題文============================================================
 
 N（1<=N<=1000000)個以下の重み付き区間のスケジュールが与えられる。
 ２つ以上の区間が重ならないようにスケジュールを設定したときに取得できる最大の重みを求めよ
 
 =================================================================
 
 解説=============================================================
 dp[i] := i時の時に得ることができる最大の重み
 ================================================================
 */

ll dp[1000005];
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll N,M,R; cin >> N >> M >> R;
    vector<vector<pii> > mp(N+1);
    for(int i = 0; i < M;i++){
        int s,e,v; cin >> s >> e >> v;
        mp[e].push_back(make_pair(s, v));
    }
    for(int i = 2; i <= N;i++){
        dp[i] = max(dp[i],dp[i-1]);
        for(int j = 0; j < (int)mp[i].size();j++){
            dp[i] = max(dp[i],dp[max(mp[i][j].first-R,0LL)] + mp[i][j].second);
        }
    }
    cout << dp[N] << endl;
    return 0;
}
