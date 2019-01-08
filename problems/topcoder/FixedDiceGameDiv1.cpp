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


class FixedDiceGameDiv1 {
public:
    double getExpectation(int a, int b, int c, int d) {
        if(a*b <= c) return -1;
        double res = 0;
        double d1[2][50*50+1],d2[2][50*50+1];
        fill(*d1,*d1+2*(50*50+1),0.0);
        fill(*d2,*d2+2*(50*50+1),0.0);
        d1[0][0] = d2[0][0] = 1.0;
        
        int cur1 = 0,next1 = 1;
        for(int i = 0; i < a;i++){
            for(int j = 0; j <= 2500;j++){
                if(d1[cur1][j]){
                    for(int k = 1; k <= b; k++){
                        d1[next1][j+k] += d1[cur1][j]/b;
                    }
                }
                d1[cur1][j] = 0.0;
            }
            swap(cur1,next1);
        }
        
        int cur2 = 0,next2 = 1;
        for(int i = 0; i < c;i++){
            for(int j = 0; j <= 2500;j++){
                if(d2[cur2][j]){
                    for(int k = 1; k <= d; k++){
                        d2[next2][j+k] += d2[cur2][j]/d;
                    }
                }
                d2[cur2][j] = 0.0;
            }
            swap(cur2,next2);
        }
        
        double winp = 0;
        for(int i = 2; i <= 2500; i++){
            for(int j = 1; j < i; j++){
                winp += d1[cur1][i]*d2[cur2][j];
            }
        }
        if(winp == 0.0) return -1.0;
        
        for(int i = 2; i <= 2500; i++){
            for(int j = 1; j < i; j++){
                res += (double)i*d1[cur1][i]*d2[cur2][j]/winp;
            }
        }
        
        return res;
    }
    
    
    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 1; int Arg3 = 5; double Arg4 = 2.0; verify_case(0, Arg4, getExpectation(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_1() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 1; int Arg3 = 3; double Arg4 = 3.0; verify_case(1, Arg4, getExpectation(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_2() { int Arg0 = 1; int Arg1 = 5; int Arg2 = 1; int Arg3 = 1; double Arg4 = 3.4999999999999996; verify_case(2, Arg4, getExpectation(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_3() { int Arg0 = 2; int Arg1 = 6; int Arg2 = 50; int Arg3 = 30; double Arg4 = -1.0; verify_case(3, Arg4, getExpectation(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_4() { int Arg0 = 50; int Arg1 = 11; int Arg2 = 50; int Arg3 = 50; double Arg4 = 369.8865999182022; verify_case(4, Arg4, getExpectation(Arg0, Arg1, Arg2, Arg3)); }
    
    // END CUT HERE
    
    
};

// BEGIN CUT HERE
//int main(){
//    FixedDiceGameDiv1 ___test;
//    ___test.run_test(-1);
//    return 0;
//}
// END CUT HERE
