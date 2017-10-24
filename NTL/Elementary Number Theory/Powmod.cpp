#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60


/* 繰り返し二乗法 */
 
//const ll MOD=1e9+7;
//ll powmod(ll x, ll n, ll mod) {
//    ll res = 1;
//    while (n > 0) {
//        if (n & 1) { //奇数なら
//            res =(res*x)%mod;
//        }
//        x = (x*x)%mod;
//        n >>= 1;
//    }
//    return res;
//}

const ll MOD = 1e9+7;
ll powmod(ll a,ll b) {ll res=1;a%=MOD; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}


int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll m,n; cin >> m >> n;
    cout << powmod(m,n) << endl;
    return 0;
}
