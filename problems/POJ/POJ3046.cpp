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
 dp[i+1][j] := i番目までのアリからj組選ぶ組み合わせの総数
 ================================================================
 */
const ll MOD = 1e6;
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    int T,A,S,B; cin >> T >> A >> S >> B;
    vector<int> a(T);
    for(int i = 0; i < A;i++){
        int ant; cin >> ant; ant--;
        a[ant]++;
    }
    
    vector<vector<int> > dp(T+1,vector<int>(A+1));
    for(int i = 0; i <= T;i++){
        dp[i][0] = 1; //  選ばない方法は１通り
    }
    for(int i = 0; i < T;i++){
        for(int j = 1; j <=A;j++){
            if(j-1-a[i] >=0){
                dp[i+1][j] = (dp[i+1][j-1]+dp[i][j] -dp[i][j-1-a[i]]+MOD)%MOD;
            }else{
                dp[i+1][j] = (dp[i+1][j-1]+dp[i][j])%MOD;
            }
        }
    }
    ll ans = 0;
    for(int i = S;i <= B;i++){
        (ans+=dp[T][i])%=MOD;
    }
    cout << ans << endl;
    return 0;
}
