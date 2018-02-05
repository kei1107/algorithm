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
 <url:http://poj.org/problem?id=3666>
 問題文============================================================
 
 長さN(<2000)の整数列Aが与えられる。
 広義単調な整数列Bを作ってsum |A[i]-B[i]|を最小化せよ
 
 =================================================================
 
 解説=============================================================
 
 広義単調増加、減少についてはそれぞれ数列を左から、右から見ていけば良いので、
 問題を簡単にするため広義単調増加に限定できる
 
 dp[i][j] := {B[i] = j番目に小さいA[k]の値の時の最小値}
 
 として、双方向から見れば良い
 
 ================================================================
 */

#define MAX_N 2000
ll N;
ll A[MAX_N];
ll _A[MAX_N];
ll dp[MAX_N+1][MAX_N];

ll Abs(ll a){
    return a < 0 ? -a:a;
}

ll calc(){
    ll res = LINF;
    for(int i = 0; i <= N;i++)for(int j = 0; j < N;j++) dp[i][j] = LINF;
    dp[0][0] = 0;
    for(int i = 0; i < N;i++){
        ll tmp = LINF;
        for(int j = 0; j < N;j++){
            tmp = min(tmp,dp[i][j]);
            dp[i+1][j] = tmp + Abs(A[i] - _A[j]);
        }
    }
    for(int i = 0; i < N;i++) res = min(res,dp[N][i]);
    return res;
}
int main(void) {
    //	cin.tie(0); ios::sync_with_stdio(false);
    scanf("%lld",&N);
    for(int i = 0; i < N;i++){
        scanf("%lld",&A[i]);
        _A[i] = A[i];
    }
    sort(_A,_A+N);
    
    ll ans = calc();
    
    reverse(A,A+N);
    
    ans = min(ans,calc());
    cout << ans << endl;
    return 0;
}
