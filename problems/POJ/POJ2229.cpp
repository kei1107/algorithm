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
dp
================================================================
*/
const ll MOD = 1e9;
ll dp[1000001];
int main(){
    ll N; cin >> N;
    dp[1] = 1;
    for(int i = 2;i<=N;i++){
        if(i%2 == 0){
            dp[i] += dp[i/2];
        }
        (dp[i] += dp[i-1])%=MOD;
  //      cout << i << " " << dp[i] << endl;
    }
    cout << dp[N] << endl;
}
