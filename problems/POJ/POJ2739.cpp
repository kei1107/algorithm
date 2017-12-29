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
 しゃくとり法
 ================================================================
 */

ll kassa;
vector<int> primes;

bool IsPrime(int num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く
    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2){
        if (num % i == 0){
            return false;
        }
    }
    return true;
}

void init(){
    primes.push_back(2);
    for(int i = 3; i < 10000; i+=2){
        if(IsPrime(i)) primes.push_back(i);
    }
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    init();
    int _size = (int)primes.size();
    //cout << _size << endl;
    vector<int> cusum(_size + 1,0);
    for(int i = 0; i < _size;i++){
        cusum[i+1] = cusum[i] + primes[i];
    }
    
    while(cin >>kassa){
        if(kassa == 0) break;
        int l = 0, r = 0, sum = 0;
        int ans = 0;
        while(true){
            while(r < _size && sum < kassa){
                if(l >= ++r){
                    sum = -1;
                    continue;
                }
                sum = cusum[r] - cusum[l];
            }
            if(sum < kassa) break;
            if(sum == kassa) ans++;
            
            if(++l >= r){
                sum = -1;
                continue;
            }
            sum = cusum[r] - cusum[l];
        }
        cout << ans << endl;
    }
    return 0;
}
