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

================================================================
*/

#define MAX_M 2000
ll dp[MAX_M][MAX_M+1];

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N,M; cin >> N >> M;
    string s; cin >> s;
    int Cost[26];
    for(int i = 0; i < N;i++){
        char c;
        int cost1,cost2;
        cin >> c >> cost1 >> cost2;
        Cost[c-'a'] = min(cost1,cost2);
    }
    for(int i = 0; i < M;i++){
        fill(dp[i],dp[i] + M + 1,INF);
        dp[i][i] = dp[i][i+1] = 0;
    }

    for(int i = 0; i < M;i++){
        for(int j = 0; j < M;j++){
            int k = i + j;
            if(j > 0){
                dp[j-1][k] = min(dp[j-1][k],dp[j][k] + Cost[s[j-1] - 'a']);
            }
            if(k < M){
                dp[j][k+1] = min(dp[j][k+1],dp[j][k] + Cost[s[k] - 'a']);
            }
            if(j > 0 && k < M && s[j-1] == s[k]){
                dp[j-1][k+1] = min(dp[j-1][k+1],dp[j][k]);
            }
        }
    }
    cout << dp[0][M] << endl;
    return 0;
}
