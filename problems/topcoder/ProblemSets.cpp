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

bool ok(ll m,ll E,ll EM,ll M,ll MH,ll H){
    EM -= max(0LL,m-E);
    MH -= max(0LL,m-H);
    if(EM < 0 || MH < 0) return false;
    return EM+M+MH >= m;
}
class ProblemSets {
    public:
    long long maxSets(long long E, long long EM, long long M, long long MH, long long H) {
        ll res = 0;
        ll l = 0, r = 3*LINF;
        while(r-l>1){
            ll m = (l+r)/2;
            if(ok(m,E,EM,M,MH,H)) l = m;
            else r = m;
        }
        res = l;
        return res;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 2LL; long long Arg1 = 2LL; long long Arg2 = 1LL; long long Arg3 = 2LL; long long Arg4 = 2LL; long long Arg5 = 3LL; verify_case(0, Arg5, maxSets(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { long long Arg0 = 100LL; long long Arg1 = 100LL; long long Arg2 = 100LL; long long Arg3 = 0LL; long long Arg4 = 0LL; long long Arg5 = 0LL; verify_case(1, Arg5, maxSets(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { long long Arg0 = 657LL; long long Arg1 = 657LL; long long Arg2 = 657LL; long long Arg3 = 657LL; long long Arg4 = 657LL; long long Arg5 = 1095LL; verify_case(2, Arg5, maxSets(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { long long Arg0 = 1LL; long long Arg1 = 2LL; long long Arg2 = 3LL; long long Arg3 = 4LL; long long Arg4 = 5LL; long long Arg5 = 3LL; verify_case(3, Arg5, maxSets(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { long long Arg0 = 1000000000000000000LL; long long Arg1 = 1000000000000000000LL; long long Arg2 = 1000000000000000000LL; long long Arg3 = 1000000000000000000LL; long long Arg4 = 1000000000000000000LL; long long Arg5 = 1666666666666666666LL; verify_case(4, Arg5, maxSets(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE


};

// BEGIN CUT HERE
//int main(){
//    ProblemSets ___test;
//    ___test.run_test(-1);
//    return 0;
//}
// END CUT HERE
