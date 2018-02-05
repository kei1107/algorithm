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
<url:http://poj.org/problem?id=3181>
問題文============================================================

 1..K円のコインでN円を作るときの場合の数を求めよ
 
=================================================================

解説=============================================================

 dp[i][j] := i円以下のコインでj円を作るときの場合の数
 dp[i][j] = if j < i dp[i-1][j] else dp[i-1][j] + dp[i][j-1];
 
 式は簡単だが、多倍長が必要となる
================================================================
*/

struct bigint {
    typedef long long i64;
    static const i64 BASE = 1.0e17;
    vector<i64> data;
    bigint() {}
    bigint (i64 x) {
        for(; x > 0; x /= BASE) data.push_back(x % BASE);
    }
    bigint& operator += (const bigint& x) {
        if(data.size() < x.data.size()) data.resize(x.data.size());
        i64 tmp = 0LL;
        for(int i = 0; i < data.size(); ++i) {
            data[i] += (i < x.data.size() ? x.data[i] : 0) + tmp;
            tmp = data[i] / BASE;
            data[i] %= BASE;
        }
        if(tmp) data.push_back(1LL);
        return *this;
    }
    void print() {
        for(int i = data.size() - 1; i >= 0; --i) {
            if(i == data.size() - 1) printf("%lld", data[i]);
            else printf("%016lld", data[i]);
        }
        printf("\n");
    }
};

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N,K; cin >> N >> K;
    vector<bigint> dp(N+1,0);
    dp[0] = 1;
    for(int k = 1; k <= K;k++){
        for(int n = k; n <= N;n++){
            dp[n] += dp[n-k];
        }
    }
    dp[N].print();
	return 0;
}
