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
<url:http://poj.org/problem?id=3421>
問題文============================================================
 正の整数 X に対し，長さ m の X-factor chain は
 
     X[0] = 1
     X[m] = X
     X[i] < X[i+1]
     X[i+1] は X[i] で割りきれる
 というような数列 X[i] である．
 与えられた X に対して，作れる最大の数列の長さ m と，その長さになる数列がいくつあるか答える．
 
=================================================================

解説=============================================================
素因数分解　＋　組み合わせ
 
 Xを素因数分解する。この素因数の冪の合計を長さとでき、各素因数の重複した順列が個数に対応する
================================================================
*/

/* 素因数分解 */
vector<int> PrimeFact(ll n){
    vector<int> res;
    while(n!=1){
        if(n == 2 || n == 3){
            res.push_back(n); n/=n;
            continue;
        }
        bool prime_flag = false;
        for(int i = 2;i*i <= n;i++){
            if(n%i==0){
                res.push_back(i); n/=i;
                prime_flag = true;
                break;
            }
        }
        if(!prime_flag){res.push_back(n); n/= n;}
    }
    return res;
}

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll fact[21];
    fact[0] = 1;
    for(int i = 1; i < 21;i++){
        fact[i] = fact[i-1]*i;
    }
    
    ll n;
    while (cin >> n) {
        vector<int> primes = PrimeFact(n);
        sort(primes.begin(),primes.end());
        int len = (int)primes.size();
        map<int,int> mp;
        for(int i = 0; i < len;i++){
            mp[primes[i]]++;
        }
        ll cnt = fact[len];
        for(map<int,int>::iterator it = mp.begin();it != mp.end();it++){
            cnt/=fact[it->second];
        }
        cout << len << " " << cnt << endl;
    }
	return 0;
}
