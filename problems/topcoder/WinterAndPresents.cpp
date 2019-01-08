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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
class WinterAndPresents {
    public:
    long long getNumber(vector <int> apple, vector <int> orange) {
        ll res = 0;
        ll n = (int)apple.size();

        ll maxX = LINF;
        for(int i = 0; i < n;i++) maxX = min(maxX,(ll)apple[i]+orange[i]);
        for(ll X = 1; X <= maxX; X++){
            ll MAXV = 0;
            ll MINV = 0;
            for(int i = 0; i < n;i++){
                MAXV += min(X,(ll)apple[i]);
                MINV += max(0LL,X-orange[i]);
            }
            res += MAXV-MINV+1;
        }
        return res;
    }
};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
