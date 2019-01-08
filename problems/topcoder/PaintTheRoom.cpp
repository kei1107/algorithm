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
class PaintTheRoom {
    public:
    string canPaintEvenly(int R, int C, int K) {
        if(K == 1) return "Paint";
        if(R > C) swap(R,C);
        if(R == 1 && C == 1) return "Cannot paint";
        if(R == 1 && C%2==0) return "Paint";
        if(R == 1) return "Cannot paint";
        if(R%2 == 0 || C%2==0) return "Paint";
        return "Cannot paint";
    }

    


};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
