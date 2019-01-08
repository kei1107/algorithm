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
class DoubleOrOneEasy {
    public:
    int minimalSteps(int a, int b, int newA, int newB) {
        int res = INF;
        
        int cnt =0;
        while(true){
            if(newA < a || newB < b) break;
            
            int da = newA-a;
            int db = newB-b;
            if(da==db){
                res = min(res,cnt+da);
            }
            if((newA+newB)%2==1){
                break;
            }else if(newA%2==0 && newB%2==0){
                newA/=2;
                newB/=2;
            }else{
                newA--;
                newB--;
            }
            cnt++;
        }
        
        if(res==INF) res = -1;
        return res;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 100; int Arg1 = 1000; int Arg2 = 101; int Arg3 = 1001; int Arg4 = 1; verify_case(0, Arg4, minimalSteps(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 100; int Arg1 = 1000; int Arg2 = 202; int Arg3 = 2002; int Arg4 = 2; verify_case(1, Arg4, minimalSteps(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 1; int Arg3 = 1; int Arg4 = -1; verify_case(2, Arg4, minimalSteps(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 111111111; int Arg2 = 8; int Arg3 = 888888888; int Arg4 = 3; verify_case(3, Arg4, minimalSteps(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 111111111; int Arg2 = 9; int Arg3 = 999999999; int Arg4 = -1; verify_case(4, Arg4, minimalSteps(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};

// BEGIN CUT HERE
//int main(){
//    DoubleOrOneEasy ___test;
//    ___test.run_test(-1);
//    return 0;
//}
// END CUT HERE
