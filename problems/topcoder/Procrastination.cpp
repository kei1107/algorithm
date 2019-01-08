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


class Procrastination {
public:
    long long findFinalAssignee(long long n) {
        ll res = 0;
        vector<ll> idx(1010);
        ll l = n-500,r = n+500;
        for(int i = 0; i < 1001;i++) idx[i] = l+i;
        
        for(ll h = 2; h*2 <= n;){
            for(ll v = max(h*2,(l+(h-1))/h*h); v <= r; v+=h){
                swap(idx[v-l],idx[v-l+1]);
            }
            if(h<1e6 || l/(h+1)!=r/(h+1)) h++;
            else h = l/(l/(h+1));
        }
        
        res = idx[n-l];
        return res;
    }
    
    
    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { long long Arg0 = 3LL; long long Arg1 = 3LL; verify_case(0, Arg1, findFinalAssignee(Arg0)); }
    void test_case_1() { long long Arg0 = 8LL; long long Arg1 = 11LL; verify_case(1, Arg1, findFinalAssignee(Arg0)); }
    void test_case_2() { long long Arg0 = 20LL; long long Arg1 = 20LL; verify_case(2, Arg1, findFinalAssignee(Arg0)); }
    void test_case_3() { long long Arg0 = 196248LL; long long Arg1 = 196259LL; verify_case(3, Arg1, findFinalAssignee(Arg0)); }
    void test_case_4() { long long Arg0 = 5587021440LL; long long Arg1 = 5587021440LL; verify_case(4, Arg1, findFinalAssignee(Arg0)); }
    
    // END CUT HERE
    
    
};

// BEGIN CUT HERE
//int main(){
//    Procrastination ___test;
//    ___test.run_test(-1);
//    return 0;
//}
// END CUT HERE
