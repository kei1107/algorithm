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
組み合わせ数
================================================================
*/

ll C(int n,int m){
    m = m<(n-m) ? m : (n-m);
    if(m == 0) return 1;
    ll ans = 1;
    for(int i=1;i<=m;i++){
        ans = ans *(n-i+1)/i;
    }
    return ans;
}

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll n,k;
    while(cin >> n >> k){
        if(n == 0 && k == 0) break;
        cout << C(n,k) << endl;
    }
	return 0;
}
