#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:>
問題文============================================================

=================================================================

解説=============================================================

================================================================
*/
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll a,b;
    while(cin >> a >> b){
        ll GCDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD = gcd(a,b);
        cout << GCDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD << " " << a/GCDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD*b<< endl;
    }
	return 0;
}
