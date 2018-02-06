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
 <url:http://poj.org/problem?id=1995>
 問題文============================================================
 (A1^B1+A2^B2+ ... +AH^BH)mod M を求めよ
 =================================================================
 
 解説=============================================================
 mod M とした繰り返し二乗法を行えば良い
 ================================================================
 */

ll MOD = 1e9+7;
ll powmod(ll a,ll b) {ll res=1;a%=MOD; for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll Z; cin >> Z;
    for(int _Z = 0; _Z < Z;_Z++){
        ll M; cin >> M;
        ll H; cin >> H;
        MOD = M;
        ll ans = 0;
        for(int i = 0; i < H;i++){
            ll A,B; cin >> A >> B;
            (ans += powmod(A, B))%=MOD;
        }
        cout << ans << endl;
    }
    
    return 0;
}
