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
<url:>
問題文============================================================

=================================================================

解説=============================================================

================================================================
*/

ll n;
ll k;
ll a[100001];
bool ok(ll m){
    ll t = 0;
    for(int i = 0; i < n;i++){
        if(a[i] - m <= 0)continue;
        t += (a[i] - m + (k - 1))/k;
    }
    return t <= m;
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    cin >> n;
    ll l = 0, r = 0;
    for(int i = 0; i< n;i++){
        cin >> a[i];
        r = max(r,a[i]);
    }
    cin >> k;
    k--;
    if(k == 0){
        cout << r << endl;
        return 0;
    }
    while(r-l > 1){
        ll m = (l+r)/2;
        if(ok(m)){
            r = m;
        }else{
            l = m;
        }
    }
    cout << r << endl;
	return 0;
}
