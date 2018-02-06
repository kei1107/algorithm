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
<url:http://poj.org/problem?id=3641>
問題文============================================================
 二つの整数p,aが与えられる。
 
 ここでpが素数でなく、a^p≡a (mod p)となっているかを判定せよ。
=================================================================

解説=============================================================
素数判定を行い、繰り返し二乗法で実際にa^p (mod p) を計算すれば良い
================================================================
*/

ll MOD;
ll powmod(ll a,ll b) {ll res=1;a%=MOD; for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll p,a;
    while(cin >> p >> a){
        if(p == 0 && a == 0)break;
        bool f = true;
        for(int i = 2; i <= sqrt(p);i++){
            if(p%i == 0){
                f = false;
            }
        }
        if(f){
            cout << "no" << endl;
            continue;
        }
        MOD = p;
        
        if(a == powmod(a,p)){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }
        
    }
	return 0;
}
