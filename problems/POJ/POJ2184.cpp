#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
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
const int INF = 1e9;
const ll LINF = 1e16;

/*
<url:http://poj.org/problem?id=2184>
問題文============================================================
 整数の数列SとFが与えられる。
 S+Fの部分和の最大値を計算する。
 しかしそのときのSの部分和、Fの部分和ともに0以上でなくてはならない。

=================================================================

解説=============================================================

 dp[i][j] := i番目を見ている時、Sの合計がjであるときのFの合計の最大値
 
================================================================
*/

#define MAX_N 100
#define MAX_R 2*100*1000+2
#define GETA 100000

int dp[2][MAX_R];
int S[MAX_N],F[MAX_N];
int N;

void init(){
    for(int i = 0; i < 2;i++) for(int j = 0; j < MAX_R;j++) dp[i][j] = -INF;
}

int main(void) {
//	cin.tie(0); ios::sync_with_stdio(false);
    scanf("%d",&N);
    for(int i = 0; i < N;i++) scanf("%d%d",&S[i],&F[i]);
    
    init();
    
    int cur = 0;
    int next = 1;
    
    dp[cur][GETA] = 0;
    for(int i = 0; i < N;i++){
        for(int j = 0; j < MAX_R;j++){
            if(dp[cur][j] == -INF) continue;
         //   cout << i << " : " << j << " : " << dp[cur][j] << endl;
            dp[next][j] = max(dp[next][j],dp[cur][j]);
            dp[next][j + S[i]] = max(dp[next][j+S[i]],dp[cur][j] + F[i]);
        }
        cur = !cur;
        next = !next;
        for(int i = 0; i < MAX_R;i++) dp[next][i] = -INF;
    }
    int ans = 0;
    for(int i = GETA; i < MAX_R;i++){
        if(dp[cur][i] >= 0){
            ans = max(ans,i-GETA + dp[cur][i]);
        }
    }
    cout << ans << endl;
	return 0;
}
