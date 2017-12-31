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
#include <iomanip>
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
#define INF (1<<30)
#define LINF (1LL<<60)

/*
<url:>
問題文============================================================

=================================================================

解説=============================================================
 dp[i][j] := i番目の牛をみたとき、j番の農場が既に使用されている時の総数
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N,M; cin >> N >> M;
    vector<vector<ll> > dp(2,vector<ll>(1<<M,0));

    dp[0][0] = 1;
    vector<vector<int> > Cow(N);
    for(int i = 0; i < N;i++){
        int P; cin >> P;
        for(int j = 0; j < P;j++){
            int F; cin >> F; F--;
            Cow[i].push_back(F);
        }
    }
    
    int cur = 0;
    int next = 1;
    for(int i = 0; i < N;i++){
        for(int j = 0; j < (1<<M);j++) dp[next][j] = 0;
        for(int j = 0; j < (1<<M);j++){
            if(dp[cur][j] == 0) continue;
            for(int k = 0; k < Cow[i].size();k++){
                int b = Cow[i][k];
                if(!((j>>b)&1)){
                    dp[next][j|(1<<b)] += dp[cur][j];
                }
            }
        }
        cur^=1;
        next^=1;
    }
    
    ll ans = 0;
    for(int i = 0; i < (1<<M);i++){
        ans += dp[cur][i];
    }
    cout << ans << endl;
	return 0;
}
