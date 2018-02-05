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
<url:http://poj.org/problem?id=2229>
問題文============================================================

 ある数Nが与えられた時、そのNの分割数のうち要素が全て2の累乗となるものの総数を述べよ
 
=================================================================

解説=============================================================
 dp[i] := 数iでの答え
 
 要素が全て2の累乗で表されなければならないので、
 dp[i]において、単純に i は i-1に"1"を加算したものであり、1を用いる組み合わせの総数はdp[i-1]と同一
 また、iが偶数の時, i/2 の要素を見ることで、1を用いない組み合わせの総数を求めることができる為
 
 dp[i] = dp[i-1] + (if i is even then dp[i/2])
 
 もとまる
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
