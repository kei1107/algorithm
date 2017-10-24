#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/* 拡張ユークリッドの互除法 extgcd */
ll extgcd(ll a, ll b, ll& x, ll& y){
    ll g = a; x = 1; y = 0;
    if(b!=0) { g = extgcd(b, a%b, y, x); y -= (a/b)*x;}
    return g;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll a,b; cin >> a >> b;
    ll x,y;
    extgcd(a,b,x,y);
    cout << x << " " << y << endl;
    return 0;
}
