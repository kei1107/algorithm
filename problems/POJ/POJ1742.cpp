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
 
 dp[i+1][j] := i番目までの品物からj円になるか否か
 
 dp[i+1][j] = dp[i][j-A*k] (1<= k <= C)
 O(mΣC)
 
 dp[i+1][j] := i番目まででjを作る際に余る最大のi番目の個数(X := -1)
 
 
 ================================================================
 */

int dp[100001];
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n,m;
    while(cin >> n >> m){
        if(n == 0 && m == 0) break;
        for(int j = 0; j <=m;j++) dp[j] = -1;
        vector<int> A(n),C(n);
        for(int i = 0; i < n;i++) cin >> A[i];
        for(int i = 0; i < n;i++) cin >> C[i];
        
        dp[0] = 0;
        for(int i = 0; i < n;i++){
            for(int j = 0; j <= m;j++){
                if(dp[j]>=0){
                    dp[j] = C[i];
                }else if(j < A[i] || dp[j-A[i]] <= 0){
                    dp[j] = -1;
                }else{
                    dp[j] = dp[j-A[i]] - 1;
                }
            }
        }
        ll ans = 0;
        for(int i = 1; i <=m;i++){
            if(dp[i] >= 0)ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
