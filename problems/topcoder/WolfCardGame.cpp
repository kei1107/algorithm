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
class WolfCardGame {
public:
    vector <int> createAnswer(int N, int K) {
        vector<int> res;
        int sum = 0;
        for(int i = 1; i <= K; i++) sum+=i;
        if(sum < N) {
            res.resize(K); iota(res.begin(),res.end(),1);
            return res;
        }
        if(N == 60){
            res.push_back(1);
            for(int i = 1; i <= K-1;i++) res.push_back(7*i);
            return res;
        }
        for(int i = 1; i <= 100;i++){
            if(N%i==0) continue;
            for(int j = 1; j <= K;j++) res.push_back(i*j);
            break;
        }
        return res;
    }
    
    
    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
    void test_case_0() { int Arg0 = 20; int Arg1 = 4; int Arr2[] = {1, 2, 3, 4 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, createAnswer(Arg0, Arg1)); }
    void test_case_1() { int Arg0 = 40; int Arg1 = 1; int Arr2[] = {39 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, createAnswer(Arg0, Arg1)); }
    void test_case_2() { int Arg0 = 97; int Arg1 = 6; int Arr2[] = {7, 68, 9, 10, 62, 58 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, createAnswer(Arg0, Arg1)); }
    void test_case_3() { int Arg0 = 2; int Arg1 = 12; int Arr2[] = {33, 69, 42, 45, 96, 15, 57, 12, 93, 9, 54, 99 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, createAnswer(Arg0, Arg1)); }
    
    // END CUT HERE
    
    
};

// BEGIN CUT HERE
//int main(){
//    WolfCardGame ___test;
//    ___test.run_test(-1);
//    return 0;
//}
// END CUT HERE
