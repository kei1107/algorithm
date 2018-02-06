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
 <url:http://poj.org/problem?id=3292>
 問題文============================================================
 4n+1 の形で表わされる正の整数を H-numbers と呼ぶ．H-numbers は乗算に関して閉じている．
 
 H-number h が単位元ではなく，
 そして2つの H-number の積で表わしたとき 1 * h の1通りしかないとき，h は H-prime であると呼ぶ．
 
 2つの H-prime の積で表わされる H-number を H-semi-prime とするとき，
 与えられた H-number h 以下の H-semi-prime がいくつあるか答える．
 =================================================================
 
 解説=============================================================
 あらかじめ，H-prime をすべて生成し，H-semi-prime をすべて生成して数を保存しておく
 ================================================================
 */

bool primes[1000002];
vector<ll> hprime;
ll dp[1000002];
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    for(int i = 5;i<=1000001;i+=4){
        if(primes[i])continue;
        hprime.push_back(i);
        for(int j = i*5; j <= 1000001;j += i*4)primes[j] = true;
    }
    int Size = (int)hprime.size();
    for(int i = 0; i < Size;i++){
        for(int j = 0; j < Size;j++){
            if(hprime[i]*hprime[j] >= 1000002) break;
            dp[hprime[i]*hprime[j]] = 1;
        }
    }
    
    for(int i = 1; i <= 1000001;i++){
        dp[i] += dp[i-1];
    }
    ll h;
    while(cin >> h){
        if(h==0)break;
        cout << h << " " << dp[h] << endl;
    }
    return 0;
}
