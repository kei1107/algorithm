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
class TreeAndPathLength3 {
public:
    vector <int> construct(int s) {
        vector<int> res;
        res.push_back(0);
        res.push_back(1);
        res.push_back(1);
        res.push_back(2);
        res.push_back(2);
        res.push_back(3);
        
        //        for(int i = 1; i < s;i++){
        //            res.push_back(2);
        //            res.push_back(3+i);
        //        }
        
        int add = 4;
        [&]{
            for(int i = 1; i <= s;i++){
                for(int j = i+1; i*j <= s; j++){
                    if(i*j==s && i+j+2 <= 500){
                        for(int k = 1; k < i;k++){
                            res.push_back(1);
                            res.push_back(add++);
                        }
                        for(int k = 1; k < j;k++){
                            res.push_back(2);
                            res.push_back(add++);
                        }
                        return;
                    }
                    int d = s-(i+1)*j;
                    if((i+1)*j <= s&&i+j+2+d+1<=500){
                        for(int k = 1; k < i;k++){
                            res.push_back(1);
                            res.push_back(add++);
                        }
                        for(int k = 1; k < j;k++){
                            res.push_back(2);
                            res.push_back(add++);
                        }
                        res.push_back(3);
                        res.push_back(add);
                        for(int k = 0; k < d;k++){
                            res.push_back(add++);
                            res.push_back(add);
                        }
                        return;
                    }
                }
            }
        }();
        return res;
    }
    
    
    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
    void test_case_0() { int Arg0 = 1; int Arr1[] = {0, 1, 1, 2, 2, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, construct(Arg0)); }
    void test_case_1() { int Arg0 = 2; int Arr1[] = {0, 1, 1, 2, 2, 3, 3, 4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, construct(Arg0)); }
    void test_case_2() { int Arg0 = 6; int Arr1[] = {0, 1, 1, 2, 0, 3, 3, 4, 0, 5, 5, 6 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, construct(Arg0)); }
    void test_case_3() { int Arg0 = 8; int Arr1[] = {0, 1, 1, 2, 1, 3, 3, 4, 3, 5, 5, 6, 5, 7 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, construct(Arg0)); }
    
    // END CUT HERE
    
    
};

// BEGIN CUT HERE
//int main(){
//    TreeAndPathLength3 ___test;
//    ___test.run_test(-1);
//    return 0;
//}
// END CUT HERE
