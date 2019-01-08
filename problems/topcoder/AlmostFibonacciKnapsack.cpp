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
class AlmostFibonacciKnapsack {
public:
    vector<ll> A,cusum;
    
    void rec(int n,ll now,vector<int>& B,vector<int>& res){
        if(res.size()) return;
        if(now==0){
            res = B;
            return;
        }
        if(n==0) return;
        if(cusum[n] < now) return;
        
        rec(n-1,now,B,res);
        B.push_back(n);
        rec(n-1,now-A[n-1],B,res);
        B.pop_back();
    }
    vector <int> getIndices(long long x) {
        A.clear(); cusum.clear();
        A.push_back(2); A.push_back(3);
        while(A.back()<=LINF) A.push_back(A[A.size()-1]+A[A.size()-2]-1);
        int n = (int)A.size();
        cusum.resize(n+1);
        for(int i = 0;i < n;i++) cusum[i+1] = cusum[i] + A[i];
        
        vector<int> res,B;
        rec(n,x,B,res);
        return res;
    }
    
    
    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
    void test_case_0() { long long Arg0 = 148LL; int Arr1[] = {6, 10, 8, 5 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getIndices(Arg0)); }
    void test_case_1() { long long Arg0 = 2LL; int Arr1[] = {1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getIndices(Arg0)); }
    void test_case_2() { long long Arg0 = 13LL; int Arr1[] = {2, 3, 4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getIndices(Arg0)); }
    void test_case_3() { long long Arg0 = 3LL; int Arr1[] = {2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getIndices(Arg0)); }
    void test_case_4() { long long Arg0 = 86267769395LL; int Arr1[] = {3, 14, 15, 9, 26, 53, 5, 8 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, getIndices(Arg0)); }
    
    // END CUT HERE
    
    
};

// BEGIN CUT HERE
//int main(){
//    AlmostFibonacciKnapsack ___test;
//    ___test.run_test(-1);
//    return 0;
//}
// END CUT HERE
