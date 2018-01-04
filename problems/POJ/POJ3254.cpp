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
#define INF (1<<30)
#define LINF (1LL<<60)

/*
<url:>
問題文============================================================

=================================================================

解説=============================================================
 dp[i][S] := i行目を見る時、i-1行目の状態がSの時の総数
================================================================
*/
ll M,N;
ll masu[12];
ll dp[2][1<<12];
const ll MOD = 1000000000;

bool ok(int m,int S1,int S2){
    if(S1&S2) return false;
    if(S2&(S2<<1)) return false;
    if(S2&~masu[m]) return false;
    return true;
}
int main(void) {
//    cin.tie(0); ios::sync_with_stdio(false);
    scanf("%lld%lld",&M,&N);
    for(int i = 0; i < M;i++){
        for(int j = 0;j < N;j++){
            int f; cin >> f;
            if(f == 1){
                masu[i] |= (1<<j);
            }
        }
    }
    int cur = 0,next = 1;
    dp[cur][0] = 1;
    for(int i = 0; i < M;i++){
        for(int j = 0; j< (1<<N);j++){
            //if(dp[cur][j] == 0) continue;
            for(int k = 0; k < (1<<N);k++){
                if(j&k) continue;
                if(k&(k<<1))continue;
                if(k& ~masu[i]) continue;
                (dp[next][k] += dp[cur][j])%=MOD;
            }
        }
        
        for(int j = 0; j < (1<<N);j++) dp[cur][j] = 0;
        cur = !cur;
        next = !next;
    }
    
    
    ll res = 0;
    for(int i = 0; i< (1<<N);i++){
        (res += dp[cur][i])%=MOD;
    }
    cout << res << endl;
	return 0;
}
