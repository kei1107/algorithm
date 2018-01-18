#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <bitset>
#include <iostream>
#include <iomanip>
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
const int INF = 1e9;
const ll LINF = 1e16;

/*
<url:>
問題文============================================================

=================================================================

解説=============================================================

 LIS
 
================================================================
*/

#define MAX_P 40000

int dp[MAX_P];
int a[MAX_P];
int main(void) {
//	cin.tie(0); ios::sync_with_stdio(false);
    int kassa; scanf("%d",&kassa);
    while(kassa--){
        int p; scanf("%d",&p);
        for(int i = 0; i < p;i++){
            scanf("%d",&a[i]);
            dp[i] = INF;
        }
        for(int i = 0; i < p;i++){
            *lower_bound(dp,dp+p,a[i]) = a[i];
        }
        cout << lower_bound(dp, dp+p, INF) - dp << endl;
    }
	return 0;
}
