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
ll powmod(ll a,ll b) {ll res=1;a%=MOD;for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}


int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll m,n; cin >> m >> n;
    cout << powmod(m,n) << endl;
    return 0;
}


ll pow_mod(ll x, ll k, ll m)
{
        if(!k) return 1;
        if(k%2) return x*pow_mod(x,k-1,p)%p;
        else return pow_mod(x*x%p,k/2,p);
}




// ==================================

// return (a * b) % m
ll mul_mod(ll a,ll b,ll m){
    ll res = 0;
    ll exp = a % m;
    while(b){
        if(b&1){
            res += exp;
            if(res > m) res -= m;
        }
        exp <<= 1;
        if(exp > m) exp -= m;
        b >>= 1;
    }
    return res;
}

// return (x ^ k) % m
ll pow_mod(ll a, ll b, ll m){
    ll res = 1;
    ll exp = a % m;
    while(b){
        if(b& 1) res = mul_mod(res, exp, m);
        exp = mul_mod(exp, exp, m);
        b >>= 1;
    }
    return res;
}
