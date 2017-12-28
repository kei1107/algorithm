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
int n,k;

int a[1005],b[1005];
double y[1005];
bool ok(double m){
    for(int i = 0; i < n;i++){
        y[i] = a[i] - m*b[i];
    }
    sort(y,y+n);
    
    double sum = 0;
    for(int i = k; i < n;i++){
        sum += y[i];
    }
   // cout << sum << endl;
    return sum >= 0;
}

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    while(cin >> n >> k){
        if(n == 0 && k == 0) break;
        for(int i = 0; i < n;i++) cin >> a[i];
        for(int i = 0; i < n;i++) cin >> b[i];
        double l = 0, r = 1;
        for(int i = 0; i < 100;i++){
           // cout << l << " " << r << endl;
            double m = (l+r)/2;
            if(ok(m)){
                l = m;
            }else{
                r = m;
            }
        }
        cout << int(100*r + 0.5) << endl;
    }
	return 0;
}
