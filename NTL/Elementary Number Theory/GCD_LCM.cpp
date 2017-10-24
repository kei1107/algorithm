#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
 gcd : 最大公約数
 lcm : 最小公倍数
 */
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n; cin >> n;
    ll res = 1;
    for(int i = 0; i < n;i++) {
        ll a; cin >> a;
        res = lcm(res,a);
    }
    cout << res << endl;
    return 0;
}
